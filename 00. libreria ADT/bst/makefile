main.exe: main.o item.o queue.o BST.o
	gcc main.o item.o queue.o BST.o -o main.exe 
	
item.o: item.c
	gcc -c item.c

BST.o: BST.c
	gcc -c BST.c

queue.o: queue.c
	gcc -c queue.c
	
main.o: main.c item.o queue.o BST.o
	gcc -c main.c item.o queue.o BST.o
	 
clean:
	rm *o