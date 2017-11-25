CC = g++
CFLAGS =-std=c++14 -Wall -fPIC -I "src" -L.
LFLAGS = -lcurl -lwebcurl

final: all
	./test/test.sh
	rm -rf ./tester
	
all: test
	rm *.o
test: webhandler.o
	$(CC) $(CFLAGS) test/tester.cpp -o tester $(LFLAGS)


webhandler.o: web.o request.o json.o
	$(CC) $(CFLAGS) -c src/webhandler.cpp
	$(CC) -shared -o libwebcurl.so webhandler.o $^

web.o:
	$(CC) $(CFLAGS) -c src/web.cpp

request.o:
	$(CC) $(CFLAGS) -c src/request.cpp

json.o:
	$(CC) $(CFLAGS) -c src/json.cpp
