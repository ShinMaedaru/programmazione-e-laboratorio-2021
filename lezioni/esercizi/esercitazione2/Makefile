hello: hello.o
	g++ hello.o -ohello

hello.o: negozio2.cpp
	g++ negozio2.cpp -c -ohello.o --std=c++11 -Wall -pedantic

clean:
	rm hello.o hello


