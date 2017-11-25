CC = g++
CFLAGS =-std=c++14 -Wall
LFLAGS =-lcurl



all: main
	rm *.o
main: webhandler.o request.o web.o json.o
	$(CC) $(CFLAGS) src/main.cpp -o WebCurl++ $^ $(LFLAGS)

webhandler.o: web.o request.o
	$(CC) $(CFLAGS) -c src/webhandler.cpp

web.o:
	$(CC) $(CFLAGS) -c src/web.cpp

request.o:
	$(CC) $(CFLAGS) -c src/request.cpp

json.o:
	$(CC) $(CFLAGS) -c src/json.cpp
