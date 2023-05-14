main.exe: main.o stack.o item.o
	gcc main.o stack.o item.o -o main.exe -lm

main.o: main.c
	gcc main.c -c

stack.o: stack.c
	gcc stack.c -c

item.o: item.c
	gcc item.c -c

clean: 
	rm *.o