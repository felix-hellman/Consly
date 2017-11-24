CC = clang++
CFLAGS = -std=c++14 -Wall -Werror -stdlib=libc++
LFLAGS = -lcurl



all: main
	rm *.o
main: webhandler.o request.o web.o
	$(CC) $(CFLAGS) main.cpp -o WebCurl++ $^ $(LFLAGS)
webhandler.o: web.o request.o
	$(CC) $(CFLAGS) webhandler.cpp -c
web.o:
	$(CC) $(CFLAGS) web.cpp -c
reqeuest.o:
	$(CC) $(CFLAGS) reqeuest.cpp -c
