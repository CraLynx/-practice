
# Makefile for create archive lib 

binary: main.o libdata.a
	g++ -o pr3-static main.o -L. -ldata

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

libdata.a: data.o
	ar cr libdata.a data.o
	
data.o: data.cpp
	g++ -std=c++11 -c data.cpp
	
clean:
	rm -r *.o
