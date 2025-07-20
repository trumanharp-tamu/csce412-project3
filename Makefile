COMPILER = g++
CFLAGS = -Wall -Wextra -Werror -std=c++17

all: app
app: main.o LoadBalancer.o WebServer.o Request.o RequestQueue.o
	$(COMPILER) $(CFLAGS) -o app main.o LoadBalancer.o WebServer.o Request.o RequestQueue.o


main.o: main.cpp
	$(COMPILER) $(CFLAGS) -c main.cpp

LoadBalancer.o: LoadBalancer.cpp LoadBalancer.h
	$(COMPILER) $(CFLAGS) -c LoadBalancer.cpp

WebServer.o: WebServer.cpp WebServer.h
	$(COMPILER) $(CFLAGS) -c WebServer.cpp

Request.o: Request.cpp Request.h
	$(COMPILER) $(CFLAGS) -c Request.cpp

RequestQueue.o: RequestQueue.cpp RequestQueue.h
	$(COMPILER) $(CFLAGS) -c RequestQueue.cpp

clean:
	rm -f app *.o