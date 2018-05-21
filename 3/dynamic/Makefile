
# Makefile for create shared object lib 

binary: main.o libdata.so
	g++ -o pr3-static main.o -L. -ldata -Wl,-rpath,.

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

libdata.so: data.o
	g++ -shared -o libdata.so data.o
	
data.o: data.cpp
	g++ -std=c++11 -c -fPIC data.cpp
	
clean:
	rm -r *.o
