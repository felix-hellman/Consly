#include "json.hpp"


WebCurl::JSONObject WebCurl::parse(const std::string &buffer)
{
	WebCurl::JSONObject returnValue;
	
	auto found = buffer.find("\"");
	found++;
	auto fend = buffer.find("\"",found);

	std::string name = buffer.substr(found,fend-found);
	found = fend;
	returnValue.name = name;
	while(found != std::string::npos)
	{
		found = buffer.find("\"",found+1);
		auto end = buffer.find("\"",found+1);
		if(end != std::string::npos)
		{
			found++;
			std::string elementpart = buffer.substr(found,end-found);
			returnValue.addPart(elementpart);
		}
		auto next = buffer.find("\"",end+1);
		if(next == std::string::npos)
			found = next;
		else
			found = end;
	}
	return returnValue;
}

