  
mandatory: main.o mandatory.o
	gcc -o mandatory main.o mandatory.o

main.o: main.c mandatory.h
	gcc -c main.c

mandatory.o: mandatory.c mandatory.h
	gcc -c mandatory.c

clean :
	rm -f *.o mandatory 