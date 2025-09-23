all: tests.exe

tests.exe: sorting_algos.o tests.o
	gcc sorting_algos.o tests.o -o tests.exe

tests.o: tests.c sorting_algos.h
	gcc -c tests.c -o tests.o

sorting_algos.o: sorting_algos.c sorting_algos.h
	gcc -c sorting_algos.c -o sorting_algos.o

clean:
	rm -f *.o *.exe