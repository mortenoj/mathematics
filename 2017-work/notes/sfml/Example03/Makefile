# I am a comment, and I want to say that the variable CC will be
# # the compiler to use.
 CC=g++
# # Hey!, I am comment number 2. I want to say that CFLAGS will be the
# # options I'll pass to the compiler.
 CFLAGS=-c -Wall

all: main.o
	$(CC) main.o -o main.out

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp



clean:
	 rm *o main
