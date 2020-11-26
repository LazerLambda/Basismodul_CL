FLAGS=-Wall

prog: compile clean
		./DEA
	
compile: dea
		gcc -o DEA main.c DEA.o $(FLAGS)

dea: DEA.h DEA.c
		gcc -c DEA.h DEA.c $(FLAGS)

test: compile clean
		valgrind --tool=memcheck ./DEA

clean:
		rm -rf *o *gch all