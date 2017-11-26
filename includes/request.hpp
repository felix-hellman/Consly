#pragma once

#include <string>
#include <tuple>
#include <vector>
namespace WebCurl {
class Request {
 private:
  std::string URL;
  std::string buffer;
  bool verifySSL;

 public:
  Request();
  ~Request();
  std::vector<std::tuple<std::string, std::string> > arguments;
  std::vector<std::string> headers;
  void clearBuffer();
  void addForm(const std::string &name, const std::string &data);
  void addForm(const std::tuple<std::string, std::string> &tup);
  void addHeader(const std::string &headerfield);
  void setURL(const std::string &URL);
  bool getSSL() const;
  void setSSL(bool SSL);
  std::string getURL() const;
  std::string &getBuffer();
  std::string *getBufferPointer();
};
}  // namespace WebCurl
