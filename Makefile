#Makefile

CC=g++
CXXFLAGS= -Wall
OBJDIR=./obj/
BINDIR=./bin/

EXEC= Khorse
DEPS= Case.h constantes.h Joueur.h Jeu.h Pion.h Plateau.h
SRC= Case.cpp Joueur.cpp Jeu.cpp main.cpp Pion.cpp Plateau.cpp 
OBJS= $(SRC:.cpp=.o)

$(shell   mkdir -p $(OBJDIR))
$(shell   mkdir -p $(BINDIR))

all:$(EXEC)

$(EXEC): $(OBJS)
	$(CC) -o $@ $(OBJS) $(CXXFLAGS)

main.o: constantes.h

%.o:%.cpp
	$(CC) -o $@ -c $< $(CXXFLAGS)

.PHONY: clean mrproprer

clean:
	rm -f *.o

mrproprer:
	rm -rf $(EXEC)
