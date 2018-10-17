all: mlist.o driver.o mlist.h
	gcc mlist.o driver.o

mlink.o: mlist.c mlist.h
	gcc -c mlist.c

driver.o: driver.c mlist.h
	gcc -c driver.c

run: all
	./a.out

clean:
	rm *.o -f
	rm a.out -f
	rm *~ 
