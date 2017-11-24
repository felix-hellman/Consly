#pragma once
#include <string>
#include <curl/curl.h>
size_t  curlCallback(void *contents, size_t size,size_t nmemb, std::string  *buffer);
