#include "settings.h"
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <webcurl>

int main(int argc, char ** argv){
	

	std::vector<std::tuple<std::string, std::string> > vec;

	if(argc%2 != 1) //Since program name is the first argument
		std::cout << "ERROR: Input size" << std::endl;
	for(int i = 1; i < argc; i+=2){
		auto tup = std::make_tuple(std::string(argv[i]), std::string(argv[i+1]));
		vec.push_back(tup);
	}

	WebCurl w;
	
	Request r;
	r.setURL(serverURL);
	for(auto &i: vec)
		r.addForm(i);
	w.post(r);

	auto result = JSON::parse(r.getBuffer());
	
	for(auto &i: result.elements)
		std::cout << std::get<0>(i) << " " << std::get<1>(i) << std::endl;
	 	
	return 0;
}
