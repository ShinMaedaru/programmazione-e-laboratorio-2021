hello: hello.o
	g++ hello.o -ohello

hello.o: ciuff.cpp
	g++ ciuff.cpp -c -ohello.o --std=c++11 -Wall -pedantic

clean:
	rm hello.o hello


