CC=g++ -std=c++1z

CFLAGS=-c -Wall

all: Decoder

Decoder: Main.o Decoder.o
	$(CC) Main.o Decoder.o -o Decoder

Main.o: Main.cpp
	$(CC) $(CFLAGS) Main.cpp

Decoder.o: Decoder.cpp
	$(CC) $(CFLAGS) Decoder.cpp

clean:
	rm -rf *o Decoder

