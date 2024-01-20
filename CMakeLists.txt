cmake_minimum_required(VERSION 3.27)
project(Othello C)

set(CMAKE_C_STANDARD 23)

add_executable(Othello main.c
        game_actions.h
        start_end_game.h
        online_data.h
        cJSON.c
        game_modes_run.h)


