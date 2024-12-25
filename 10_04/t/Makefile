all: our_program

our_program: main.o fun.o
	@gcc -o our_program main.o fun.o

main.o: main.c
	@gcc -c main.c

fun.o: fun.c
	@gcc -c fun.c

test: our_program
	@./our_program data
	@./our_program data2

clean:
	@rm -rf fun.o main.o our_program
