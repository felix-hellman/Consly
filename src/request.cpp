#include "request.hpp"

WebCurl::Request::Request() { this->verifySSL = true; }
WebCurl::Request::~Request() {}

bool WebCurl::Request::getSSL() const { return this->verifySSL; }

void WebCurl::Request::addForm(const std::string &name,
                               const std::string &data) {
  auto tuple = std::make_tuple(name, data);
  arguments.push_back(tuple);
}
void WebCurl::Request::addForm(
    const std::tuple<std::string, std::string> &tup) {
  arguments.push_back(tup);
}
void WebCurl::Request::addHeader(const std::string &headerfield) {
  headers.push_back(headerfield);
}
void WebCurl::Request::setURL(const std::string &URL) { this->URL = URL; }
std::string WebCurl::Request::getURL() const { return this->URL; }
std::string &WebCurl::Request::getBuffer() { return this->buffer; }
std::string *WebCurl::Request::getBufferPointer() { return &buffer; }
void WebCurl::Request::clearBuffer() { this->buffer = ""; }
