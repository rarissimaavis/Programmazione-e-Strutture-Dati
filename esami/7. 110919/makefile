main.exe: main.o item.o BST.o
	gcc main.o item.o BST.o -o main.exe -lm
	
item.o: item.c
	gcc -c item.c

BST.o: BST.c
	gcc -c BST.c
	
main.o: main.c item.o BST.o
	gcc -c main.c item.o BST.o
	 
clean:
	rm *o