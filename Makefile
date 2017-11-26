CC = $(CXX)
CFLAGS =-std=c++14 -Wall -fPIC -I "src" -I "includes"
CFLAGS_TEST =-std=c++14 -Wall -I "src" -I "includes"
LFLAGS = -lwebcurl -lcurl

compile: webhandler.o


install: 
	sudo cp libwebcurl.so /usr/lib
	$(CC) $(CFLAGS_TEST) test/tester.cpp -o tester $(LFLAGS)
	./test/test.sh
	rm -rf ./tester
	sudo cp includes/* /usr/include

webhandler.o: request.o json.o
	$(CC) $(CFLAGS) -c src/webcurl.cpp
	$(CC) -shared -o libwebcurl.so webcurl.o $^
	rm -rf *.o

request.o:
	$(CC) $(CFLAGS) -c src/request.cpp

json.o:
	$(CC) $(CFLAGS) -c src/json.cpp
