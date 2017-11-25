#pragma once

#include <curl/curl.h>
#include <string>
#include <tuple>
#include <vector>
#include "request.hpp"
#include "web.h"
#include "json.hpp"

class Webhandler {
 private:
  bool verifySSL;

 public:
  Webhandler();
  Webhandler(bool verifySSL);
  ~Webhandler();
  int get(Request &req) const;
  int post(Request &req) const;
  CURL *curlSetup(Request &req) const;
};
