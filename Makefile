CC = $(CXX)
CFLAGS =-std=c++14 -Wall -fPIC -I "src"
CFLAGS_TEST =-std=c++14 -Wall -I "src"
LFLAGS = -lwebcurl -lcurl

compile: webhandler.o


install: test
	sudo cp libwebcurl.so /usr/lib
	$(CC) $(CFLAGS_TEST) test/tester.cpp -o tester $(LFLAGS)
	./test/test.sh
	rm -rf ./tester
	cp src/*.h /usr/include
	cp src/*.hpp /usr/include

webhandler.o: web.o request.o json.o
	$(CC) $(CFLAGS) -c src/webhandler.cpp
	$(CC) -shared -o libwebcurl.so webhandler.o $^
	rm -rf *.o
web.o:
	$(CC) $(CFLAGS) -c src/web.cpp

request.o:
	$(CC) $(CFLAGS) -c src/request.cpp

json.o:
	$(CC) $(CFLAGS) -c src/json.cpp
