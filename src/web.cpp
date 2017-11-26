#include "web.hpp"

size_t curlCallback(void *contents, size_t size, size_t nmemb, std::string *s) {
  size_t newLength = size * nmemb;
  size_t oldLength = s->size();
  try {
    s->resize(oldLength + newLength);
  } catch (std::bad_alloc &e) {
    return 0;
  }

  std::copy((char *)contents, (char *)contents + newLength,
            s->begin() + oldLength);
  return size * nmemb;
}

std::string percentEncode(const std::string &input){
	std::vector<char> table{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9','A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' ,'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z','-', '.', '_', '~'};
  std::string dst;
  for(const auto &i : input){
    bool found = false;
    if (std::find(table.begin(), table.end(),i)!=table.end()){
      dst += i;
      found = true;
    }
    if(!found){
      dst += '%';
      std::stringstream stream;
      stream << std::hex << (int)i;
      dst += stream.str();
    }
  }
  return dst;
}
