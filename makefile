PROG = projet

SRC = main.c gameBoard_display.c gameBoard_creation.c gameBoard_free.c gameBoard_smooth.c gameBoard_playArea.c gameBoard_dimension.c  path_direction.c path_creation.c monkeys_creation.c crabs_creation.c crabs_movement.c clean_screen.c

all: $(PROG)
	./$(PROG)
$(PROG): $(SRC) gameBoard_display.h gameBoard_creation.h gameBoard_free.h gameBoard_smooth.h gameBoard_playArea.h gameBoard_dimension.h  path_direction.h path_creation.h monkeys_creation.h crabs_creation.h crabs_movement.h clean_screen.h
	gcc -o $(PROG) $(SRC)

clean:
	rm -f $(PROG)
