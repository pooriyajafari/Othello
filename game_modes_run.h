#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "game_actions.h"
#include "online_data.h"
#include "start_end_game.h"
#ifndef OTHELLO_NORMAL_GAME_H
#define OTHELLO_NORMAL_GAME_H
int normal_game(char names[2][20],char board[8][8],int turn,int p1score,int p2score){
    init_board(board);
    positioning(board,turn);
    print_number_of_beads(blacknum(board),whitenum(board));
    print_board(board);
    int x,y;
    int end=0;

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
int timing_game(char names[2][20],char board[8][8],int turn,int p1score,int p2score){
    init_board(board);
    positioning(board,turn);
    print_number_of_beads(blacknum(board),whitenum(board));
    print_board(board);
    print_time(240,240);
    int x,y;
    int end=0;
    time_t p1time1= time(NULL),p2time1= time(NULL);
    time_t p1time2= time(NULL),p2time2= time(NULL);
    time_t remainingtime1=240,remainingtime2=240;

    while(1){
        printf("enter x and y:\n");
        printturn(turn);
        if (turn==1){
            p1time1=time(NULL);
            localtime(&p1time1);
        }
        else{
            p2time1=time(NULL);
            localtime(&p2time1);
        }
        scanf("%d %d",&x,&y);
        if(turn==1){
            p1time2=time(NULL);
            localtime(&p1time2);
            remainingtime1-=difftime(p1time2,p1time1);
        }
        else{
            p2time2=time(NULL);
            localtime(&p2time2);
            remainingtime2-=difftime(p2time2,p2time1);
        }
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
                print_time(remainingtime1,remainingtime2);
                break;
            }
        }
        else{
            end=0;
        }
        system("cls");
        print_number_of_beads(blacknum(board),whitenum(board));
        print_board(board);
        print_time(remainingtime1,remainingtime2);
    }
    ending(names,board);
    return 0;

}
#endif
