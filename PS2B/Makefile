C= g++
CFLAGS= -Wall -Werror -ansi -pedantic
GFLAGS= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
c11 = -std=c++11

all:	
	make NBody
NBody: NBody.o main.o
	g++ NBody.o main.o -o NBody $(GFLAGS) $(c11)
Nbody.o: NBody.cpp NBody.hpp 
	g++ -c NBody.cpp -o NBody.o $(CFLAGS) $(c11)
main.o: main.cpp NBody.hpp
	g++ -c main.cpp -o main.o $(CFLAGS) $(c11)
clean:
	rm *.o *NBody 

