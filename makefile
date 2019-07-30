all: KPTS

KPTS: KPTS.o main.o 
	g++ -ggdb -o KPTS KPTS.o main.o

KPTS.o: KPTS.cpp
	g++ -ggdb -c KPTS.cpp

main.o: main.cpp
	g++ -ggdb -c main.cpp

plot: 
	gnuplot pic.gp

dep:
	echo "Do nothing"

clean:
	rm -f KPTS KPTS *.o

cleanDat:
	rm -f *.dat
