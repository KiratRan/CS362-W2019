CFLAGS= -Wall -fpic -coverage -lm -g -std=c99

testme: testme.c
	gcc -o testme testme.c $(CFLAGS)
	./testme
	
clean:
	rm -f testme testme.gcda testme.gcno