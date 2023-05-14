main.exe: main.o queue.o item.o
	gcc main.o queue.o item.o -o main.exe -lm

main.o: main.c
	gcc main.c -c

queue.o: queue.c
	gcc queue.c -c

item.o: item.c
	gcc item.c -c

clean: 
	rm *.o