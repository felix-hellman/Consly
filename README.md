# WebCurl++
C++ Library using Curl to simplify communicating with web api's 

[![Build Status](https://travis-ci.org/felix-hellman/WebCurl.svg?branch=master)](https://travis-ci.org/felix-hellman/WebCurl)

## Installation Ubuntu 17.10
```bash
sudo apt install build-essential libcurl4-gnutls-dev python
git clone https://github.com/felix-hellman/WebCurl
cd WebCurl
make ; sudo make install
cd ..
rm -rf WebCurl
```


## Imgur Upload Image Example
### imgurupload.cpp
```cpp
#include <iostream>
#include <webhandler.h>

int main()
{
	Webhandler w;
	Request r1,r2;

	std::string auth = "authorization: Bearer " + accesstoken; //This is your api accesstoken
	std::string imageURL_1 = "http://www.publicdomainpictures.net/pictures/210000/velka/statue-of-liberty-1485195728rRZ.jpg";
	std::string imageURL_2 = "http://www.publicdomainpictures.net/pictures/40000/velka/raton-laveur-4.jpg";

	r1.addHeader(auth);
	r1.setURL("https://api.imgur.com/3/image");

	//We can use r1 as a template for r2
	r2 = r1;

	r1.addForm("image", imageURL_1);
	r1.addForm("description","Freedom!");

	r2.addForm("image", imageURL_2);
	r2.addForm("description","Racoon!");

	//We can also do multiple consecutive posts
	w.post(r1);
	w.post(r2);

	//And read the status later
	std::cout << r1.getBuffer() << std::endl;
	std::cout << r2.getBuffer() << std::endl;

	return 0;
}
```
```bash
g++ -std=c++14 imgurupload.cpp -o imgurupload -lwebcurl -lcurl
```
