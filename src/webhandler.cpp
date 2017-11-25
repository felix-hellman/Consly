#include "webhandler.h"

Webhandler::Webhandler() {
  this->verifySSL = true;
  curl_global_init(CURL_GLOBAL_DEFAULT);
}
Webhandler::Webhandler(bool verifySSL) {
  this->verifySSL = verifySSL;
  curl_global_cleanup();
}
Webhandler::~Webhandler() {}
CURL *Webhandler::curlSetup(Request &req) const {
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

int Webhandler::get(Request &req) const {
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
int Webhandler::post(Request &req) const {
  CURLcode ret;
  CURL *curl = NULL;
  curl_mime *mime = NULL;
  curl_mimepart *part = NULL;
  struct curl_slist *slist = NULL;

  curl = this->curlSetup(req);
  mime = curl_mime_init(curl);

  for (const auto &i : req.headers) {
    slist = curl_slist_append(slist, i.c_str());
  }

  for (const auto &i : req.arguments) {
    part = curl_mime_addpart(mime);
    curl_mime_data(part, std::get<1>(i).c_str(), CURL_ZERO_TERMINATED);
    curl_mime_name(part, std::get<0>(i).c_str());
  }

  if (curl) {
    curl_easy_setopt(curl, CURLOPT_MIMEPOST, mime);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, slist);

    ret = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    curl_mime_free(mime);
    curl_slist_free_all(slist);
  }
  return ret;
}
