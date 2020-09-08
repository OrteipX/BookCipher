CC=g++ -std=c++1z

CFLAGS=-c -Wall

all: Encoder

Encoder: Main.o Encoder.o
	$(CC) Main.o Encoder.o -o Encoder

Main.o: Main.cpp
	$(CC) $(CFLAGS) Main.cpp

Encoder.o: Encoder.cpp
	$(CC) $(CFLAGS) Encoder.cpp

clean:
	rm -rf *o Encoder

