#include "webhandler.h"
#include "web.h"

Webhandler::Webhandler()
{
	this->verifySSL = true;
}
Webhandler::Webhandler(bool verifySSL)
{
	this->verifySSL = verifySSL;
}
Webhandler::~Webhandler(){}

void Webhandler::get(const std::string &url, std::string &buffer)
{
	CURLcode ret;
	CURL * curl = nullptr;
	curl = curl_easy_init();

	if(curl)
	{
		curl_easy_setopt(curl, CURLOPT_BUFFERSIZE, 102400L);
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	  curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 50L);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION,
	                      curlCallback);
	 	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);

		ret = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
		curl = NULL;
	}
}
void Webhandler::post(const std::string &url, std::string &buffer,const Request &req)
{
	CURLcode ret;
	CURL * curl = nullptr;
	curl_mime *mime = nullptr;
	curl_mimepart *part = nullptr;
	struct curl_slist *slist = NULL;

	for(const auto &i: req.headers)
	{
		slist = curl_slist_append(slist,i.c_str());
	}

	for(const auto &i: req.arguments)
	{
		part = curl_mime_addpart(mime);
		curl_mime_data(part,std::get<0>(i).c_str(),CURL_ZERO_TERMINATED);
		curl_mime_name(part,std::get<1>(i).c_str());
	}

	curl = curl_easy_init();
	if(curl)
	{
		curl_easy_setopt(curl,CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl,CURLOPT_HTTPHEADER,slist);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION,
	                      curlCallback);
	 	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
		curl_easy_setopt(curl,CURLOPT_MIMEPOST,mime);

		ret = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
		curl_mime_free(mime);
		curl_slist_free_all(slist);
	}
}
