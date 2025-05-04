PROG = projet

SRC = main.c gameBoard_display.c gameBoard_creation.c gameBoard_free.c gameBoard_smooth.c gameBoard_playArea.c gameBoard_dimension.c  path_direction.c path_creation.c monkeys_creation.c crabs_creation.c crabs_movement.c

all: $(PROG)
   ./$ (PROG)
$(PROG): $(SRC) head.h
       gcc -o $(PROG) $(SRC)

clean:
     rm -f $(PROG)
