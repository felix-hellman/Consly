#include "request.hpp"

Request::Request() {}
Request::~Request() {}

void Request::addForm(const std::string &name, const std::string &data) {
  auto tuple = std::make_tuple(name, data);
  arguments.push_back(tuple);
}
void Request::addForm(const std::tuple<std::string, std::string> &tup){
  arguments.push_back(tup);
}
void Request::addHeader(const std::string &headerfield) {
  headers.push_back(headerfield);
}
void Request::setURL(const std::string &URL) { this->URL = URL; }
std::string Request::getURL() const { return URL; }
std::string &Request::getBuffer() { return buffer; }
std::string *Request::getBufferPointer() { return &buffer; }
void Request::clearBuffer(){ this->buffer = ""; }

