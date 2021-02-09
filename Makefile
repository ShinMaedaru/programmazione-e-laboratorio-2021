hello: hello.o
	g++ hello.o -ohello

hello.o: hello.cpp
	g++ hello.cpp -c -ohello.o --std=c++11 -Wall -pedantic

clean:
	rm hello.o hello


