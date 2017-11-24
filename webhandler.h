#pragma once

#include <string>
#include <curl/curl.h>
#include <vector>
#include <tuple>
#include "web.h"
#include "request.hpp"

class Webhandler
{
	private:
	bool verifySSL;
	public:
	Webhandler();
	Webhandler(bool verifySSL);
	~Webhandler();
	void get(const std::string &url,std::string &buffer);
	void post(const std::string &url,std::string &buffer,const Request &req);

	// TODO post();



};
