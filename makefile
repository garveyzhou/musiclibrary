all: mlist.o driver.o mlist.h
	gcc -g mlist.o driver.o

mlink.o: mlist.c mlist.h
	gcc -c -g mlist.c

driver.o: driver.c mlist.h
	gcc -c -g driver.c

run: all
	./a.out

clean:
	rm *.o -f
	rm a.out -f
	rm *~ 
