main.exe: main.o item.o list.o
	gcc main.o item.o list.o -o main.exe -lm
	
item.o: item.c
	gcc item.c -c
	
list.o: list.c
	gcc list.c -c
	
main.o: main.c item.o list.o
	gcc main.c -c item.o list.o 
	 
clean:
	rm .f *o *.exe