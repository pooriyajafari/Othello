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
    char names[2][20];
    char board[8][8];
    int turn=1;
    int p1score=0;
    int p2score=0;
    int normal_games_count=0;
    opening();
    printf("Press any key to continue...\n");
    getchar();
    system("cls");
    input_name(names);
    system("cls");
//    char * output =NULL;
//    decryptAffinecipherFile("data.json",output,5,7);
//    struct saved_normal_game *games= convert_json_to_normal_game(output,&normal_games_count);
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
    return 0;
}