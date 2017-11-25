#pragma once

#include <vector>
#include <tuple>
#include <iostream>

namespace JSON
{	
	class JSONObject
	{
		public:
		std::string name;
		std::string part;
		std::vector<std::tuple <std::string, std::string> > elements;
		void addPart(std::string part)
		{
			if(this->part == "")
			{
				this->part = part;
			}
			else
			{
				auto result  = std::make_tuple(this->part,part);
				elements.push_back(result);
				this->part = "";
			}
		}
	};
	JSONObject parse(const std::string &buffer);
}
