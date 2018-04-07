#Makefile for jogar by David
EXE=jogar
CC=g++
CPPFLAGS=-Wall -pedantic -std=c++11
OBJS = main.o jogo.o jogador.o dado.o
INC=./includes
SRC=./src

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJS)
	mkdir build bin
	mv *.o ./build
	mv jogar ./bin

main.o:
	$(CC) $(CPPFLAGS) -c $(SRC)/main.cpp
jogo.o:
	$(CC) $(CPPFLAGS) -c $(SRC)/jogo.cpp
jogador.o:
	$(CC) $(CPPFLAGS) -c $(SRC)/jogador.cpp
dado.o:
	$(CC) $(CPPFLAGS) -c $(SRC)/dado.cpp
clean:
	rm -R ./bin ./build
