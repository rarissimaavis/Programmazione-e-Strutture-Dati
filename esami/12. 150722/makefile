main.exe: main.o item.o Btree.o stack.o
	gcc main.o item.o Btree.o stack.o -o main.exe -lm
	
item.o: item.c
	gcc -c item.c
	
Btree.o: Btree.c 
	gcc -c Btree.c

stack.o: stack.c
	gcc -c stack.c

main.o: main.c item.o Btree.o stack.o
	gcc -c main.c item.o Btree.o stack.o
	 
clean:
	rm *o