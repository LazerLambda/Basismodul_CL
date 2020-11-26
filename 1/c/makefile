FLAGS=-Wall

prog: compile clean
		./DEA
	
compile: dea
		gcc -o DEA main.c DEA.o $(FLAGS)

dea: DEA.h DEA.c
		gcc -c DEA.h DEA.c $(FLAGS)

test: compile
		valgrind --tool=memcheck ./app

clean:
		rm -rf *o *gch all