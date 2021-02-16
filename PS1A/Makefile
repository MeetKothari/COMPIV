CC=g++
CFLAGS =-g -O -Wall -Werror -std=c++11 -pedantic
LIBS=-lboost_unit_test_framework

all: ps1a 
ps1a: test.o FibLFSR.o
	$(CC) $(CFLAGS) -o ps1a test.o FibLFSR.o $(LIBS)

test.o: test.cpp FibLFSR.h
	$(CC) $(CFLAGS) -c test.cpp -o test.o

FibLFSR.o: FibLFSR.cpp FibLFSR.h
	$(CC) $(CFLAGS) -c FibLFSR.cpp -o FibLFSR.o

clean:
	rm ps1a test.o FibLFSR.o
