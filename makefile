print.o: print.cpp print.h
	g++ -c print.cpp
save.o: save.cpp save.h
	g++ -c save.cpp
make.o: make.cpp make.h
	g++ -c make.cpp
main.o: main.cpp print.h save.h make.h
	g++ -c main.cpp
sudoku: main.o make.o save.o print.o
	g++ main.o make.o save.o print.o -o sudoku
