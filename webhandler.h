#pragma once

#include <string>
#include <curl/curl.h>
#include "web.h"

class Webhandler
{
	private:
	bool verifySSL;
	public:
	Webhandler();
	Webhandler(bool verifySSL);
	~Webhandler();
	void get(const std::string &url,std::string &buffer);

	// TODO post();



};
