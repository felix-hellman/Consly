#include <iostream>
#include "webhandler.h"
#include <curl/curl.h>

int main()
{
	Webhandler w;
	std::string buffer;
	w.get("https://www.google.se/",buffer);

	std::cout << buffer << std::endl;

	return 0;
}
