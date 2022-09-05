main.exe: main.o item.o Btree.o PQueue.o
	gcc main.o item.o Btree.o PQueue.o -o main.exe -lm
	
item.o: item.c
	gcc -c item.c
	
Btree.o: Btree.c 
	gcc -c Btree.c

PQueue.o: PQueue.c
	gcc -c PQueue.c

main.o: main.c item.o Btree.o PQueue.o
	gcc -c main.c item.o Btree.o PQueue.o
	 
clean:
	rm *o