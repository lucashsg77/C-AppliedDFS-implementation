  
townCounter: main.o townCounter.o
	gcc -o townCounter main.o townCounter.o

main.o: main.c townCounter.h
	gcc -c main.c

townCounter.o: townCounter.c townCounter.h
	gcc -c townCounter.c

clean :
	rm -f *.o townCounter