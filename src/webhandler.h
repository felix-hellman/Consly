#pragma once

#include <curl/curl.h>
#include <string>
#include <tuple>
#include <vector>
#include "request.hpp"
#include "web.h"

class Webhandler {
 private:
  bool verifySSL;

 public:
  Webhandler();
  Webhandler(bool verifySSL);
  ~Webhandler();
  void get(Request &req) const;
  void post(Request &req) const;
  CURL *curlSetup(Request &req) const;
};
