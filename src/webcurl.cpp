#include <webcurl>

WebCurl::Handler::Handler() {
  curl_global_init(CURL_GLOBAL_DEFAULT);
}

WebCurl::Handler::~Handler() {}
CURL *WebCurl::Handler::curlSetup(Request &req) const {
  CURL *curl = nullptr;
  curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_BUFFERSIZE, 102400L);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl/7.56.0");
    curl_easy_setopt(curl, CURLOPT_URL, req.getURL().c_str());
    curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 50L);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curlCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, req.getBufferPointer());
  }
  return curl;
}

int WebCurl::Handler::get(Request &req) const {
  CURLcode ret;
  CURL *curl = nullptr;
  curl = this->curlSetup(req);

  if (curl) {
    ret = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    curl = NULL;
  }
  return ret;
}
int WebCurl::Handler::post(Request &req) const {
  CURLcode ret;
  CURL *curl = NULL;
  struct curl_slist *slist = NULL;

  struct curl_httppost *post = NULL;
  struct curl_httppost *postend = NULL;

  curl = this->curlSetup(req);

  for (const auto &i : req.headers) {
    slist = curl_slist_append(slist, i.c_str());
  }

  for (const auto &i : req.arguments) {
	  curl_formadd(&post, &postend,
			CURLFORM_COPYNAME, std::get<0>(i).c_str(),
			CURLFORM_COPYCONTENTS, std::get<1>(i).c_str(),
			CURLFORM_END);
  }

  if (curl) {
    curl_easy_setopt(curl, CURLOPT_HTTPPOST, post);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, slist);

    ret = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    curl_formfree(post);
    curl_slist_free_all(slist);
  }
  return ret;
}


size_t WebCurl::curlCallback(void *contents, size_t size, size_t nmemb, std::string *s) {
  size_t newLength = size * nmemb;
  size_t oldLength = s->size();
  try {
    s->resize(oldLength + newLength);
  } catch (std::bad_alloc &e) {
    return 0;
  }

  std::copy((char *)contents, (char *)contents + newLength,
            s->begin() + oldLength);
  return size * nmemb;
}

std::string WebCurl::percentEncode(const std::string &input){
	std::vector<char> table{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9','A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' ,'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z','-', '.', '_', '~'};
  std::string dst;
  for(const auto &i : input){
    bool found = false;
    if (std::find(table.begin(), table.end(),i)!=table.end()){
      dst += i;
      found = true;
    }
    if(!found){
      dst += '%';
      std::stringstream stream;
      stream << std::hex << (int)i;
      dst += stream.str();
    }
  }
  return dst;
}
