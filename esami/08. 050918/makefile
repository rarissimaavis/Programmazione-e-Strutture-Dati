main.exe: main.o PQueue.o list.o item.o
	gcc PQueue.o main.o list.o item.o -o main.exe -lm

main.o: main.c PQueue.o item.o
	gcc -c main.c

PQueue.o: PQueue.c
	gcc -c PQueue.c

list.o: list.c
	gcc -c list.c

item.o: item.c
	gcc -c item.c

clean: 
	rm *o