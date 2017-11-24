#pragma once
#include <curl/curl.h>
#include <string>
size_t curlCallback(void *contents, size_t size, size_t nmemb,
                    std::string *buffer);
