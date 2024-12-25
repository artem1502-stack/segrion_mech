all: main.o fun.o
	@gcc -o res main.o fun.o

main.o: main.c
	@gcc -c main.c

fun.o: fun.c
	@gcc -c fun.c

clean:
	@rm fun.o main.o

fclean:
	@make clean
	@rm res

re:
	@make fclean
	@make all
