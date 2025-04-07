# Makefile for Square Root without Library Challenge 
# Chris K Cockrum

default: main.c
	gcc -g -o main main.c
	./main

test: main.c
	gcc -g -DTEST -o maintest main.c -lm
	./maintest

clean:
	rm main
	rm maintest       

