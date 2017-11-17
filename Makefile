CC = clang++
CFLAGS = -std=c++14 -Wall -Werror -stdlib=libc++ 
LFLAGS = -lcurl



all: main
	rm *.o
main: webhandler.o
	$(CC) $(CFLAGS) main.cpp -o WebCurl++ webhandler.o web.o $(LFLAGS)
webhandler.o: web.o
	$(CC) $(CFLAGS) webhandler.cpp -c
web.o:
	$(CC) $(CFLAGS) web.cpp -c
