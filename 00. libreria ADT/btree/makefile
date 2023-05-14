main.exe: main.o item.o Btree.o
	gcc main.o item.o Btree.o -o main.exe -lm
	
item.o: item.c
	gcc -c item.c
	
Btree.o: Btree.c 
	gcc -c Btree.c
	
main.o: main.c item.o Btree.o
	gcc -c main.c item.o Btree.o 
	 
clean:
	rm *o