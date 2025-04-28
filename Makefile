PROG = projet

SRC = main.c chemin.c direction.c creation_singes_crabes.c deplacement_crab.c

all: $(PROG)
   ./$ (PROG)
$(PROG): $(SRC) head.h
       gcc -o $(PROG) $(SRC)

clean:
     rm -f $(PROG)
