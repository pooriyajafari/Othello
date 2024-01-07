#include <stdio.h>
#include <stdlib.h>
#include "ctype.h"

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
    int end=0;
    int p1score=0;
    int p2score=0;

    while(1){
        printturn(turn);
        printf("enter x and y:\n");
        scanf("%d %d",&x,&y);
        if(x>8||y>8||x<1||y<1){
            printf("invalid input\n");
            continue;
        }
        x--;
        y--;

        if(board[x][y]!='*'){
            printf("invalid input\n");
            continue;
        }
        int Bnumcpy=blacknum(board);
        int Wnumcpy=whitenum(board);
        reverse_dice(board,x,y,turn);
        if(turn==1){
            p1score+=whitenum(board)-Wnumcpy;
        }
        else{
            p2score+=blacknum(board)-Bnumcpy;
        }
        turn=turn%2+1;
        clear_positioning(board);
        positioning(board,turn);
        if(positioncount(board)==0) {
            turn = turn % 2 + 1;
            positioning(board, turn);
            end++;
            if (end == 2) {
                system("cls");
                print_number_of_beads(blacknum(board),whitenum(board));
                print_board(board);
                break;
            }
        }
        else{
            end=0;
        }
        system("cls");
        print_number_of_beads(blacknum(board),whitenum(board));
        print_board(board);
    }
    ending(names,board);
    return 0;
}