#include <curl/curl.h>
#include <iostream>
#include "request.hpp"
#include "webhandler.h"
#include "json.hpp"

int main() {
  Webhandler w;
  Request r1, r2, r3;

  /* Just doing some internal testing for now*/
  r1.setURL("192.168.0.108");
  r1.addForm("Alpha", "Beta");
  r1.addForm("Liger", "Tiger");

  r2.setURL("192.168.0.108?alpha=beta&liger=tiger");
  r3.setURL("https://api.imgur.com/3/image/X15ebc0");
  /* We can do multiple requests */
  w.post(r1);
  w.post(r2);
  w.get(r3);

  auto result1 = JSON::parse(r1.getBuffer());
  auto result2 = JSON::parse(r2.getBuffer());
  auto result3 = JSON::parse(r3.getBuffer());

  std::cout << result1.name << std::endl;
  for(auto &i: result1.elements)
	  std::cout << std::get<0>(i) << " : " << std::get<1>(i) << std::endl;

  

  return 0;
}
