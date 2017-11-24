#include <iostream>
#include "webhandler.h"
#include <curl/curl.h>
#include "request.hpp"

int main()
{
	Webhandler w;
	Request r1,r2;

	/* Just doing some internal testing for now*/
	r1.setURL("192.168.0.108");
	r1.addForm("Alpha","Beta");

	r2.setURL("192.168.0.108?alpha=beta");

	/* We can do multiple requests */
	w.post(r1);
	w.post(r2);

	/* And check our answers later */
	std::cout << r1.getBuffer() << std::endl;
	std::cout << r2.getBuffer() << std::endl;	
	/*Target is the test in test/webtest.php*/

	return 0;
}
