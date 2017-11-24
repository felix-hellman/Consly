#include "request.hpp"

Request::Request(){}
Request::~Request(){}

void Request::addForm(const std::string & name, const std::string & data)
{
  auto tuple = std::make_tuple(name,data);
  arguments.push_back(tuple);
}
void Request::addHeader(const std::string &headerfield)
{
  headers.push_back(headerfield);
}
