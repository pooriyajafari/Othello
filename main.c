#include <stdio.h>
#include <stdlib.h>
#include "game_actions.h"
#include "online_data.h"
#include "start_end_game.h"

int main(){
    char names[2][20];
    opening();
    printf("Press any key to continue...\n");
    getchar();
    system("cls");
    input_name(names);
    system("cls");
    char board[8][8];
    int turn=1;
    init_board(board);
    positioning(board,turn);
    print_number_of_beads(blacknum(board),whitenum(board));
    print_board(board);
    int x,y;
    while(1){
        printf("enter x and y:\n");
        scanf("%d %d",&x,&y);
        x--;
        y--;
        if(board[x][y]!='*'){
            printf("invalid input\n");
            continue;
        }
        reverse_dice(board,x,y,turn);
        turn=turn%2+1;
        clear_positioning(board);
        positioning(board,turn);
        system("cls");
        print_number_of_beads(blacknum(board),whitenum(board));
        print_board(board);

    }
    return 0;
}