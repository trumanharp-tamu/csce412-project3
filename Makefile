COMPILER = g++
CFLAGS = -Wall -Wextra -Werror -std=c++17

all: app
app: main.o LoadBalancer.o Webserver.o Request.o
	$(COMPILER) $(CFLAGS) -o app main.o LoadBalancer.o Webserver.o Request.o