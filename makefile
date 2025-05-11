PROG = projet

SRC = \
      main.c \
      gameBoard_display.c \
      gameBoard_creation.c \
      gameBoard_free.c \
      gameBoard_smooth.c \
      gameBoard_playArea.c \
      gameBoard_dimension.c \
      path_direction.c \
      path_creation.c \
      monkeys_creation.c \
      crabs_creation.c \
      crabs_movement.c \
      clean_screen.c \
      monkey_attack.c \
      menu_display.c \
      ask_monkey_position.c \
      monkeys_store.c \
      ask_players_name.c \
      countdown.c \
      display_crabs_turn.c \
      turn_creation.c \
      turn.c \

all: $(PROG)
	./$(PROG)

$(PROG): $(SRC)
	gcc -o $(PROG) $(SRC) $(LIBS)

clean:
	rm -f $(PROG)