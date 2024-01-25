#include <stdio.h>
#include <stdlib.h>
#include "ctype.h"
#include "cJSON.h"
#include "game_modes_run.h"
#include "game_actions.h"
#include "online_data.h"
#include "start_end_game.h"
#include "cryptdata.h"
#include "save_actions.h"
#include "string.h"


int main(){
    int normal_games_count = 0;
    int timing_games_count = 0;
    while(1) {
        int a=0;
        char names[2][20];
        strlwr(names[0]);
        strlwr(names[1]);
        char board[8][8];
        int turn = 1;
        int p1score = 0;
        int p2score = 0;
        char *normaljson = NULL;
        char *timingjson = NULL;
        struct saved_normal_game *normalgames = convert_json_to_normal_game(normaljson, &normal_games_count);
        struct saved_time_game *timegames = convert_json_to_time_game(timingjson, &timing_games_count);
        opening();
        printf("Press any key to continue...\n");
        getchar();
        //system("cls");
        main_menu();
        int choice;
        scanf("%d", &choice);
        //system("cls");
        if (choice == 1) {
            while(1) {
                input_name(names);
                //system("cls");
                game_menu();
                scanf("%d", &choice);
                //system("cls");
                if (choice == 1) {
                    normal_games_count++;
                    new_normal_game(names, board, turn, p1score, p2score, normal_games_count, normalgames);
                    break;
                } else if (choice == 2) {
                    timing_games_count++;
                    new_timing_game(names, board, turn, p1score, p2score, timing_games_count, timegames);
                    break;
                } else if (choice == 3) {
                    a=1;
                    break;
                } else {
                    printf("invalid input\n");
                    continue;
                }
            }
            if (a==1){
                continue;
            }
        } else if (choice == 2) {
            decryptAffinecipherFile("normaldata.json",normaljson,5,7);
            decryptAffinecipherFile("timingdata.json",timingjson,5,7);
            input_name(names);
            //system("cls");
            find_print_names(normalgames, timegames, names[0], normal_games_count+timing_games_count);
            int gameid;
            scanf("%d", &gameid);
            //system("cls");
            struct saved_normal_game *normalgame = find_normal_game(normalgames, normal_games_count, gameid);
            struct saved_time_game *timegame = find_time_game(timegames, timing_games_count, gameid);
        }
        else if(choice==4){
            break;
        }
        else{
            printf("invalid input\n");
            continue;
        }
    }
    return 0;
}