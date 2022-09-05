main.exe: main.o item.o Btree.o queue.o
	gcc main.o item.o Btree.o queue.o -o main.exe -lm
	
item.o: item.c
	gcc -c item.c
	
Btree.o: Btree.c 
	gcc -c Btree.c

queue.o: queue.c
	gcc -c queue.c

main.o: main.c item.o Btree.o queue.o
	gcc -c main.c item.o Btree.o queue.o
	 
clean:
	rm *o