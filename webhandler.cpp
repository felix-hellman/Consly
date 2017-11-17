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
	CURL * curl;

	curl = curl_easy_init();
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
