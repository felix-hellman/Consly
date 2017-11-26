#pragma once
#include <curl/curl.h>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

size_t curlCallback(void *contents, size_t size, size_t nmemb,
                    std::string *buffer);
std::string percentEncode(const std::string &input);
