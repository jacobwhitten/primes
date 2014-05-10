

CC=gcc
CFLAGS= -g -Wall

FILES = primearray.o oldprime.o

all: new old 

clean:
	rm -r prime_new prime_old $(FILES)
	


new: primearray.o
	gcc -g -Wall -o prime_new primearray.o -lm

old: oldprime.o
	gcc -g -Wall -o prime_old oldprime.o -lm
