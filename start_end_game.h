#include "stdio.h"
#include "online_data.h"
#include "game_actions.h"
#ifndef OTHELLO_START_END_GAME_H
#define OTHELLO_START_END_GAME_H
void opening(){
    printf("    ******     ***********   **    **   ********   **        **          ******\n");
    printf("   *      *        **        **    **   **         **        **         *      *\n");
    printf("  *        *       **        ********   ********   **        **        *        *\n");
    printf("  *        *       **        ********   ********   **        **        *        *\n");
    printf("   *      *        **        **    **   **         **        **         *      *\n");
    printf("    ******         **        **    **   ********   *******   *******     ******\n");
}
void input_name(char name[2][20]){
    printf("Enter name of player 1:\n");
    scanf("%s",name[0]);
    printf("Enter name of player 2:\n");
    scanf("%s",name[1]);
}
void init_board(char board[8][8]){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            board[i][j]='.';
        }
    }
    board[3][3]='W';
    board[3][4]='B';
    board[4][3]='B';
    board[4][4]='W';
}
void main_menu(){
    printf("1. Start new game\n");
    printf("2. Load game\n");
    printf("3. Scoreboard\n");
    printf("4. Exit\n");
}
void game_menu(){
    printf("1. Normal\n");
    printf("2. Timing\n");
    printf("3. Return to main menu\n");
}

void ending(char name[2][20],char board[8][8]){
    if(blacknum(board)<whitenum(board)){
        printf("%s won\n",name[0]);
    }
    else if(blacknum(board)>whitenum(board)){
        printf("%s won\n",name[1]);
    }
    else{
        printf("draw\n");
    }
}
#endif
