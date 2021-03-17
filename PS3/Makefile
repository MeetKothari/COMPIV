CC = g++
CFLAGS = -g -Wall -Werror -ansi -pedantic -std=c++11 -O3

ED: ED.o main.o
	$(CC) $(CFLAGS) -o ED ED.o main.o -lsfml-system
all: ED
ED.o: ED.cpp ED.hpp
	$(CC) $(CFLAGS) -c ED.cpp
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
clean:
	 rm *.o ED
