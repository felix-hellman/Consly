#include <iostream>
#include "webhandler.h"
#include <curl/curl.h>

int kek()
{
	return 1337;
}

void printMagic()
{
	std::cout << "Hallo magix" << std::endl;
}

int main()
{
	Webhandler w;
	std::string buffer;
	w.get("https://www.google.se/",buffer);

	std::cout << buffer << std::endl;

	return 0;
}
