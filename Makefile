CC = g++
CFLAGS =-std=c++14 -Wall
LFLAGS =-lcurl



all: main
	rm *.o
main: webhandler.o request.o web.o
	$(CC) $(CFLAGS) main.cpp -o WebCurl++ $^ $(LFLAGS)

webhandler.o: web.o request.o
	$(CC) $(CFLAGS) -c webhandler.cpp

web.o:
	$(CC) $(CFLAGS) -c web.cpp

request.o:
	$(CC) $(CFLAGS) -c request.cpp
