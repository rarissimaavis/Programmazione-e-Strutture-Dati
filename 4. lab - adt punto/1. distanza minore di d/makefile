main.exe: main.o punto.o punto.h
	gcc  main.o punto.o punto.h -o main.exe -lm

main.o:  main.c
	gcc main.c -c

punto.o: punto.c
	gcc punto.c -c -lm

clear:
	rm *.o	
