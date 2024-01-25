#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "game_actions.h"
#include "online_data.h"
#include "start_end_game.h"
#include "cryptdata.h"
#include "save_actions.h"
#include "cryptdata.h"


#ifndef OTHELLO_NORMAL_GAME_H
#define OTHELLO_NORMAL_GAME_H
int new_normal_game(char names[2][20],char board[8][8],int turn,int p1score,int p2score,int normal_games_count,struct saved_normal_game *games){
    init_board(board);
    positioning(board,turn);
    print_number_of_beads(blacknum(board),whitenum(board));
    print_board(board);
    int x,y;
    int end=0;

    while(1){
        printturn(turn);
        int temp;
        printf("enter x and y(xy):\n");
        scanf("%d",&temp);
        if(temp==100){
            //Getting confirmation from the opponent
            if (turn==1){
                printf("Black! Do you also want to save the game? (y/n)\n");
                char c;
                scanf(" %c",&c);
                if (c=='y'){
                    encryptAffinecipherFile(convert_normal_game_to_json(games,normal_games_count),"normaldata.json",5,7);
                    //system("cls");
                    printf("game saved\n");
                    return 0;
                }
                else{
                    //system("cls");
                    printf("game not saved\n");
                    continue;
                }
            }
            else{
                printf("White! Do you also want to save the game? (y/n)\n");
                char c;
                scanf(" %c",&c);
                if (c=='y'){

                    encryptAffinecipherFile(convert_normal_game_to_json(games,normal_games_count),"normaldata.json",5,7);
                    //system("cls");
                    printf("game saved\n");
                    return 0;
                }
                else{
                    //system("cls");
                    printf("game not saved\n");
                    continue;
                }
            }
        }
        x=temp/10;
        y=temp%10;
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
                //system("cls");
                print_number_of_beads(blacknum(board),whitenum(board));
                print_board(board);
                break;
            }
        }
        else{
            end=0;
        }
        //system("cls");
        print_number_of_beads(blacknum(board),whitenum(board));
        print_board(board);
    }
    ending(names,board);
    return 0;

}
int new_timing_game(char names[2][20],char board[8][8],int turn,int p1score,int p2score,int timing_games_count,struct saved_time_game *games){
    init_board(board);
    positioning(board,turn);
    print_number_of_beads(blacknum(board),whitenum(board));
    print_board(board);
    print_backs(2,2);
    print_time(240,240);
    int x,y;
    int end=0;
    time_t p1time1= time(NULL),p2time1= time(NULL);
    time_t p1time2= time(NULL),p2time2= time(NULL);
    time_t remainingtime1=240,remainingtime2=240;
    char Wboardcpy1[8][8];
    char Bboardcpy1[8][8];
    int p1scorecpy,p2scorecpy;
    int Wback=2,Bback=2;
    time_t p1timecpy,p2timecpy;
    while(1) {
        if (remainingtime1 <= 0) {
            printf("%s won\n", names[1]);
            break;
        }
        if (remainingtime2 <= 0) {
            printf("%s won\n", names[0]);
            break;
        }
        printf("enter x and y(xy):\n");
        printturn(turn);
        if (turn == 1) {
            p1time1 = time(NULL);
            localtime(&p1time1);
        } else {
            p2time1 = time(NULL);
            localtime(&p2time1);
        }
        int temp;
        scanf("%d", &temp);
        if (temp == 100) {
            //Getting confirmation from the opponent
            if (turn==1){
                printf("Black! Do you also want to save the game? (y/n)\n");
                char c;
                scanf(" %c",&c);
                if (c=='y'){
                    encryptAffinecipherFile(convert_time_game_to_json(games,timing_games_count),"timingdata.json",5,7);
                    //system("cls");
                    printf("game saved\n");
                    return 0;
                }
                else{
                    //system("cls");
                    printf("game not saved\n");
                    continue;
                }
            }
            else{
                printf("White! Do you also want to save the game? (y/n)\n");
                char c;
                scanf(" %c",&c);
                if (c=='y'){

                    encryptAffinecipherFile(convert_time_game_to_json(games,timing_games_count),"timingdata.json",5,7);
                    //system("cls");
                    printf("game saved\n");
                    return 0;
                }
                else{
                    //system("cls");
                    printf("game not saved\n");
                    continue;
                }
            }
        }

        if (temp == -1) {
            if (turn == 1) {
                if (Wback == 0) {
                    printf("you can't back\n");

                } else if (Wback == 2) {

                    Wback--;
                    remainingtime1 -= 30;
                    p1score -= p1scorecpy;
                    //system("cls");
                    print_number_of_beads(blacknum(board), whitenum(board));
                    print_board(Wboardcpy1);
                    for(int i=0;i<8;i++){
                        for(int j=0;j<8;j++){
                            board[i][j]=Wboardcpy1[i][j];
                        }
                    }
                    print_backs(Wback, Bback);
                    print_time(remainingtime1, remainingtime2);
                    continue;

                } else if (Wback == 1) {

                    Wback--;
                    remainingtime1 -= 60;
                    p1score -= p1scorecpy;
                    remainingtime2 += p1timecpy + p2timecpy;
                    //system("cls");
                    print_number_of_beads(blacknum(board), whitenum(board));
                    print_board(Wboardcpy1);
                    for(int i=0;i<8;i++){
                        for(int j=0;j<8;j++){
                            board[i][j]=Wboardcpy1[i][j];
                        }
                    }
                    print_backs(Wback, Bback);
                    print_time(remainingtime1, remainingtime2);
                    continue;

                }
            } else {
                if (Bback == 0) {
                    printf("you can't back\n");

                } else if (Bback == 2) {

                    Bback--;
                    remainingtime2 -= 30;
                    p2score -= p2scorecpy;
                    //system("cls");
                    print_number_of_beads(blacknum(board), whitenum(board));
                    print_board(Bboardcpy1);
                    for(int i=0;i<8;i++){
                        for(int j=0;j<8;j++){
                            board[i][j]=Bboardcpy1[i][j];
                        }
                    }
                    print_backs(Wback, Bback);
                    print_time(remainingtime1, remainingtime2);
                    continue;


                } else if (Bback == 1) {

                    Bback--;
                    remainingtime2 -= 60;
                    p2score -= p2scorecpy;
                    remainingtime1 += p1timecpy + p2timecpy;
                    //system("cls");
                    print_number_of_beads(blacknum(board), whitenum(board));
                    print_board(Bboardcpy1);
                    for(int i=0;i<8;i++){
                        for(int j=0;j<8;j++){
                            board[i][j]=Bboardcpy1[i][j];
                        }
                    }

                    print_backs(Wback, Bback);
                    print_time(remainingtime1, remainingtime2);
                    continue;
                }
            }

        }
        x=temp/10;
        y=temp%10;
        if(turn==1){
            p1time2=time(NULL);
            localtime(&p1time2);
            remainingtime1-=difftime(p1time2,p1time1);
            p1timecpy=difftime(p1time2,p1time1);
        }
        else{
            p2time2=time(NULL);
            localtime(&p2time2);
            remainingtime2-=difftime(p2time2,p2time1);
            p2timecpy=difftime(p2time2,p2time1);
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
        if(turn==1){
            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                    Wboardcpy1[i][j]=board[i][j];
                }
            }
        }
        else{
            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                    Bboardcpy1[i][j]=board[i][j];
                }
            }
        }
        reverse_dice(board,x,y,turn);
        if(turn==1){
            p1score+=whitenum(board)-Wnumcpy;
            p1scorecpy=whitenum(board)-Wnumcpy;
        }
        else{
            p2score+=blacknum(board)-Bnumcpy;
            p2scorecpy=blacknum(board)-Bnumcpy;
        }
        turn=turn%2+1;
        clear_positioning(board);
        positioning(board,turn);
        if(positioncount(board)==0) {
            turn = turn % 2 + 1;
            positioning(board, turn);
            end++;
            if (end == 2) {
                //system("cls");
                print_number_of_beads(blacknum(board),whitenum(board));
                print_board(board);
                print_backs(Wback,Bback);
                print_time(remainingtime1,remainingtime2);
                break;
            }
        }
        else{
            end=0;
        }
        //system("cls");
        print_number_of_beads(blacknum(board),whitenum(board));
        print_board(board);
        print_backs(Wback,Bback);
        print_time(remainingtime1,remainingtime2);
    }
    ending(names,board);
    return 0;

}
int load_normal_game(char names[2][20],char board[8][8],int turn,int p1score,int p2score){
    print_number_of_beads(blacknum(board),whitenum(board));
    print_board(board);
    int x,y;
    int end=0;
    while(1){
        printturn(turn);
        int temp;
        printf("enter x and y(xy):\n");
        scanf("%d",&temp);
        if(temp==100){
            //system("cls");
            printf("game saved\n");
            return 0;
        }
        x=temp/10;
        y=temp%10;
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
                //system("cls");
                print_number_of_beads(blacknum(board),whitenum(board));
                print_board(board);
                break;
            }
        }
        else{
            end=0;
        }
        //system("cls");
        print_number_of_beads(blacknum(board),whitenum(board));
        print_board(board);
    }
    ending(names,board);
    return 0;

}
int load_timing_game(char names[2][20],char board[8][8],int turn,int p1score,int p2score) {
    print_number_of_beads(blacknum(board), whitenum(board));
    print_board(board);
    print_backs(2, 2);
    print_time(240, 240);
    int x, y;
    int end = 0;
    time_t p1time1 = time(NULL), p2time1 = time(NULL);
    time_t p1time2 = time(NULL), p2time2 = time(NULL);
    time_t remainingtime1 = 240, remainingtime2 = 240;
    char Wboardcpy1[8][8];
    char Bboardcpy1[8][8];
    int p1scorecpy, p2scorecpy;
    int Wback = 2, Bback = 2;
    time_t p1timecpy, p2timecpy;
    while (1) {
        if (remainingtime1 <= 0) {
            printf("%s won\n", names[1]);
            break;
        }
        if (remainingtime2 <= 0) {
            printf("%s won\n", names[0]);
            break;
        }
        printf("enter x and y(xy):\n");
        printturn(turn);
        if (turn == 1) {
            p1time1 = time(NULL);
            localtime(&p1time1);
        } else {
            p2time1 = time(NULL);
            localtime(&p2time1);
        }
        int temp;
        scanf("%d", &temp);
        if (temp == 100) {
            //system("cls");
            printf("game saved\n");
            return 0;
        }
        if (temp == -1) {
            if (turn == 1) {
                if (Wback == 0) {
                    printf("you can't back\n");

                } else if (Wback == 2) {

                    Wback--;
                    remainingtime1 -= 30;
                    p1score -= p1scorecpy;
                    //system("cls");
                    print_number_of_beads(blacknum(board), whitenum(board));
                    print_board(Wboardcpy1);
                    for (int i = 0; i < 8; i++) {
                        for (int j = 0; j < 8; j++) {
                            board[i][j] = Wboardcpy1[i][j];
                        }
                    }
                    print_backs(Wback, Bback);
                    print_time(remainingtime1, remainingtime2);
                    continue;
                } else if (Wback == 1) {

                    Wback--;
                    remainingtime1 -= 60;
                    p1score -= p1scorecpy;
                    remainingtime2 += p1timecpy + p2timecpy;
                    //system("cls");
                    print_number_of_beads(blacknum(board), whitenum(board));
                    print_board(Wboardcpy1);
                    for (int i = 0; i < 8; i++) {
                        for (int j = 0; j < 8; j++) {
                            board[i][j] = Wboardcpy1[i][j];
                        }
                    }
                    print_backs(Wback, Bback);
                    print_time(remainingtime1, remainingtime2);
                    continue;
                }
            } else {
                if (Bback == 0) {
                    printf("you can't back\n");

                } else if (Bback == 2) {

                    Bback--;
                    remainingtime2 -= 30;
                    p2score -= p2scorecpy;
                    //system("cls");
                    print_number_of_beads(blacknum(board), whitenum(board));
                    print_board(Bboardcpy1);
                    for (int i = 0; i < 8; i++) {
                        for (int j = 0; j < 8; j++) {
                            board[i][j] = Bboardcpy1[i][j];
                        }
                    }
                    print_backs(Wback, Bback);
                    print_time(remainingtime1, remainingtime2);
                    continue;
                } else if (Bback == 1) {

                    Bback--;
                    remainingtime2 -= 60;
                    p2score -= p2scorecpy;
                    remainingtime1 += p1timecpy + p2timecpy;
                    //system("cls");
                    print_number_of_beads(blacknum(board), whitenum(board));
                    print_board(Bboardcpy1);
                    for (int i = 0; i < 8; i++) {
                        for (int j = 0; j < 8; j++) {
                            board[i][j] = Bboardcpy1[i][j];
                        }
                    }

                    print_backs(Wback, Bback);
                    print_time(remainingtime1, remainingtime2);
                    continue;
                }
            }
        }
        x = temp / 10;
        y = temp % 10;
        if (turn == 1) {
            p1time2 = time(NULL);
            localtime(&p1time2);
            remainingtime1 -= difftime(p1time2, p1time1);
            p1timecpy = difftime(p1time2, p1time1);
        } else {
            p2time2 = time(NULL);
            localtime(&p2time2);
            remainingtime2 -= difftime(p2time2, p2time1);
            p2timecpy = difftime(p2time2, p2time1);
        }
        if (x > 8 || y > 8 || x < 1 || y < 1) {
            printf("invalid input\n");
            continue;
        }
        x--;
        y--;

        if (board[x][y] != '*') {
            printf("invalid input\n");
            continue;
        }
        int Bnumcpy = blacknum(board);
        int Wnumcpy = whitenum(board);
        if (turn == 1) {
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    Wboardcpy1[i][j] = board[i][j];
                }
            }
        } else {
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    Bboardcpy1[i][j] = board[i][j];
                }
            }
        }
        reverse_dice(board, x, y, turn);
        if (turn == 1) {
            p1score += whitenum(board) - Wnumcpy;
            p1scorecpy = whitenum(board) - Wnumcpy;
        } else {
            p2score += blacknum(board) - Bnumcpy;
            p2scorecpy = blacknum(board) - Bnumcpy;
        }
        turn = turn % 2 + 1;
        clear_positioning(board);
        positioning(board, turn);
        if (positioncount(board) == 0) {
            turn = turn % 2 + 1;
            positioning(board, turn);
            end++;
            if (end == 2) {
                //system("cls");
                print_number_of_beads(blacknum(board), whitenum(board));
                print_board(board);
                print_backs(Wback, Bback);
                print_time(remainingtime1, remainingtime2);
                break;
            }
        } else {
            end = 0;
        }
        //system("cls");
        print_number_of_beads(blacknum(board), whitenum(board));
        print_board(board);
        print_backs(Wback, Bback);
        print_time(remainingtime1, remainingtime2);
    }
    ending(names, board);
    return 0;
}

#endif
