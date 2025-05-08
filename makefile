PROG = projet

SRC = main.c gameBoard_display.c gameBoard_creation.c gameBoard_free.c gameBoard_smooth.c gameBoard_playArea.c gameBoard_dimension.c path_direction.c path_creation.c monkeys_creation.c crabs_creation.c crabs_movement.c clean_screen.c generate_crab.c filter_active_crabs.c

all: $(PROG)
	./$(PROG)

$(PROG): $(SRC)
	gcc -o $(PROG) $(SRC) $(LIBS)

clean:
	rm -f $(PROG)