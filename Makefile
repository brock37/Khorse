#Makefile

CC=g++
CXXFLAGS= -Wall
OBJDIR=./obj
BINDIR=./bin

EXEC= Khorse
DEPS= Case.h constantes.h Joueur.h Jeu.h Pion.h Plateau.h
SRC= Case.cpp Joueur.cpp Jeu.cpp main.cpp Pion.cpp Plateau.cpp
OBJS= $(SRC:%.cpp=$(OBJDIR)/%.o)

$(shell   mkdir -p $(OBJDIR))
$(shell   mkdir -p $(BINDIR))

all:$(BINDIR)/$(EXEC)

$(BINDIR)/$(EXEC): $(OBJS)
	$(CC) -o $@ $(OBJS) $(CXXFLAGS)

main.o: constantes.h

$(OBJDIR)/%.o:%.cpp
	$(CC) -c $< $(CXXFLAGS) -o $@

.PHONY: clean mrproprer

clean:
	rm -f $(OBJDIR)/*.o

mrproprer:
	rm -rf $(EXEC)
