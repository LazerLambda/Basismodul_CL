FLAGS=-Wall -g

prog: compile clean
		./main
	
compile: compare list freeElem
		gcc -o main test.c compare.o freeElem.o list.o $(FLAGS)
		
list: list.h list.c
		gcc -c list.h list.c $(FLAGS)

compare: compare.h compare.c
		gcc -c compare.h compare.c $(FLAGS)

freeElem: freeElem.h freeElem.c 
		gcc -c freeElem.h freeElem.c $(FLAGS)

test: compile clean
		valgrind --tool=memcheck ./main

clean:
		rm -rf *.o *.gch all