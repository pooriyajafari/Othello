#include <stdio.h>
#include <stdlib.h>
#include "ctype.h"
#include "cJSON.h"
#include "game_modes_run.h"
#include "game_actions.h"
#include "online_data.h"
#include "start_end_game.h"
struct saved_normal_game{
    char board[8][8];
    int turn;
    int p1score;
    int p2score;
    char names[2][20];
};
struct saved_time_game{
    char board[8][8];
    int turn;
    int p1score;
    int p2score;
    char names[2][20];
    int time;
};

int main(){
    char names[2][20];
    char board[8][8];
    int turn=1;
    int p1score=0;
    int p2score=0;
    opening();
    printf("Press any key to continue...\n");
    getchar();
    input_name(names);
    system("cls");
    main_menu();
    int choice;
    scanf("%d",&choice);
    system("cls");
    if(choice==1){
        game_menu();
        scanf("%d",&choice);
        system("cls");
        if(choice==1){
            normal_game(names,board,turn,p1score,p2score);
        }
        else if(choice==2){
            timing_game(names,board,turn,p1score,p2score);
        }
        else if(choice==3){
            main();
        }
        else {
            printf("invalid input\n");
            main();
        }
    }

    system("cls");

    timing_game(names,board,turn,p1score,p2score);
    return 0;
}