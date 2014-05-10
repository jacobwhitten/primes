

CC=gcc
CFLAGS= -g -Wall

FILES = primearray.o oldprime.o

all: new old 

	


new: primearray.o
	gcc -g -Wall -o prime_new primearray.o -lm

old: oldprime.o
	gcc -g -Wall -o prime_old oldprime.o -lm
