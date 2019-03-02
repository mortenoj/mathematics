CC=g++
CFLAGS= -std=c++11 -Wall -w -g
INCLUDE:= -I/usr/local/Cellar/sfml/2.4.2/include
SOURCE:= $(wildcard src/*.cpp)

EXE=main.out

all: clean $(EXE)

$(EXE):
	$(CC) $(CFLAGS) $(INCLUDE) $(SOURCE) -o $(EXE) -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -rf $(EXE)
	rm -rf main.out.dSYM
