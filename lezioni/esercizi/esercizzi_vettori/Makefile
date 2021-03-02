hello: hello.o
	g++ hello.o -ohello

hello.o: vector.cpp
	g++ vector.cpp -c -ohello.o --std=c++11 -Wall -pedantic

clean:
	rm hello.o hello


