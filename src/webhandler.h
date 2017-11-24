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
	void get(Request &req) const;
	void post(Request &req) const;
};
