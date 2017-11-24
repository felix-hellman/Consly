#pragma once

#include <tuple>
#include <vector>

class Request{

public:
  Request();
  ~Request();
  std::vector<std::tuple<std::string, std::string > > arguments;
  std::vector<std::string> headers;
  void addForm(const std::string & name,const std::string & data);
  void addHeader(const std::string &headerfield);
};
