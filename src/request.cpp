#include "request.hpp"

Consly::Request::Request() { this->verifySSL = true; }
Consly::Request::~Request() {}

bool Consly::Request::getSSL() const { return this->verifySSL; }
void Consly::Request::setSSL(bool SSL) { this->verifySSL = SSL; }
void Consly::Request::addForm(const std::string &name,
                               const std::string &data) {
  auto tuple = std::make_tuple(name, data);
  arguments.push_back(tuple);
}
void Consly::Request::addForm(
    const std::tuple<std::string, std::string> &tup) {
  arguments.push_back(tup);
}
void Consly::Request::addHeader(const std::string &headerfield) {
  headers.push_back(headerfield);
}
void Consly::Request::setURL(const std::string &URL) { this->URL = URL; }
std::string Consly::Request::getURL() const { return this->URL; }
std::string &Consly::Request::getBuffer() { return this->buffer; }
std::string *Consly::Request::getBufferPointer() { return &buffer; }
void Consly::Request::clearBuffer() { this->buffer = ""; }
