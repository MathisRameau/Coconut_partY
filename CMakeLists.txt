cmake_minimum_required(VERSION 3.10)

project(Singe)

set(CMAKE_CXX_STANDARD 11)

add_executable(Singe
        main.c
        gameBoard_display.c
        gameBoard_creation.c
        gameBoard_free.c
        gameBoard_smooth.c
        gameBoard_playArea.c
        gameBoard_dimension.c
        path_direction.c
        path_creation.c
        monkeys_creation.c
        crabs_creation.c
        crabs_movement.c
)