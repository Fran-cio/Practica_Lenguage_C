CC=gcc
CFLAGS=-Wall -Werror -pedantic
PATHout=./out/
PATHh=./headers/
PATHrec=./rec/

main: main.o libtp1.a 
	$(CC) $(CFLAGS) -o $(PATHout)main main.o -L./lib -ltp1

main.o: main.c $(PATHh)function.h
	$(CC) $(CFLAGS) -c main.c 

punto1.o: $(PATHrec)punto1.c $(PATHh)function.h
	$(CC) $(CFLAGS) -c $(PATHrec)punto1.c 

punto2.o: $(PATHrec)punto2.c $(PATHh)function.h
	$(CC) $(CFLAGS) -c $(PATHrec)punto2.c 

punto3.o: $(PATHrec)punto3.c $(PATHh)function.h
	$(CC) $(CFLAGS) -c $(PATHrec)punto3.c 

libtp1.a: punto1.o punto2.o punto3.o
	ar cr ./lib/libtp1.a punto1.o punto2.o punto3.o

clean:
	rm -f *.o $(PATHout)main




