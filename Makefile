PROG = projet

SRC = main.c projet.c affichage.c

all: $(PROG)
   ./$ (PROG)
$(PROG): $(SRC) head.h
       gcc -o $(PROG) $(SRC)

clean:
     rm -f $(PROG)
