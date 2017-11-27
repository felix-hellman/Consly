#pragma once

#include <iostream>
#include <tuple>
#include <vector>

namespace Consly {
class JSONObject {
 public:
  std::string name;
  std::string part;
  std::vector<std::tuple<std::string, std::string> > elements;
  bool operator==(
      const std::vector<std::tuple<std::string, std::string> > &other) {
    if (this->elements.size() != other.size()) return false;
    for (unsigned int i = 0; i < this->elements.size(); i++)
      if (this->elements[i] != other[i]) return false;
    return true;
  }
  void addPart(std::string part) {
    if (this->part == "") {
      this->part = part;
    } else {
      auto result = std::make_tuple(this->part, part);
      elements.push_back(result);
      this->part = "";
    }
  }
};
JSONObject parse(const std::string &buffer);
}  // namespace Consly
