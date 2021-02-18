INCL=./include

final.o: main.cpp mcd.o multipli.o
	g++ main.cpp mcd.o multipli.o -o final.o -O1 -I$(INCL)

mcd.o: mcd.cpp
	g++ mcd.cpp -o mcd.o -01 -c

multipli.o: multipli.cpp $(INCL)
	g++ multipli.cpp -o multipli.o -01 -c

clean:
	 rm final *.o


