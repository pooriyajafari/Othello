#include "stdio.h"
#include "online_data.h"
#ifndef OTHELLO_GAME_ACTIONS_H
#define OTHELLO_GAME_ACTIONS_H
void print_board(char board[8][8]){
    printf("--------------------\n");
    printf("|  1 2 3 4 5 6 7 8 |\n");
    for(int i=0;i<8;i++){
        printf("|%d ",i+1);
        for(int j=0;j<8;j++){
            printf("%c ",board[i][j]);
        }
        printf("|\n");
    }
    printf("--------------------\n");
}
void positioning(char board[8][8],int turn){
    int flag_board[8][8]={0};
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if (board[i][j]=='W'){
                flag_board[i][j]=1;
            }
            if (board[i][j]=='B'){
                flag_board[i][j]=2;
            }
        }
    }

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(turn==1){
                if(flag_board[i][j]==1){
                    if(board[i+1][j]=='B') {
                        for (int k = i + 2; k < 8; k++) {
                            if (board[k][j] == 'W' || board[k][j] == '*') {
                                break;
                            }
                            if (board[k][j] == '.') {
                                board[k][j] = '*';
                                break;
                            }
                        }
                    }
                    if(board[i-1][j]=='B') {
                        for (int k = i - 2; k >= 0; k--) {
                            if (board[k][j] == 'W' || board[k][j] == '*') {
                                break;
                            }
                            if (board[k][j] == '.') {
                                board[k][j] = '*';
                                break;
                            }
                        }
                    }
                    if(board[i][j+1]=='B') {
                        for (int k = j + 2; k < 8; k++) {
                            if (board[i][k] == 'W' || board[i][k] == '*') {
                                break;
                            }
                            if (board[i][k] == '.') {
                                board[i][k] = '*';
                                break;
                            }
                        }
                    }
                    if(board[i][j-1]=='B') {
                        for (int k = j - 2; k >= 0; k--) {
                            if (board[i][k] == 'W' || board[i][k] == '*') {
                                break;
                            }
                            if (board[i][k] == '.') {
                                board[i][k] = '*';
                                break;
                            }
                        }
                    }
                    if(board[i+1][j+1]=='B') {
                        for (int k = 1; i+k < 8 && j+k <8 ; k++) {
                            if (board[i + k][j + k] == 'W' || board[i + k][j + k] == '*') {
                                break;
                            }
                            if (board[i + k][j + k] == '.') {
                                board[i + k][j + k] = '*';
                                break;
                            }
                        }
                    }
                    if(board[i-1][j-1]=='B') {
                        for (int k = 1; i-k >= 0 && j-k>= 0; k++) {
                            if (board[i - k][j - k] == 'W' || board[i - k][j - k] == '*') {
                                break;
                            }
                            if (board[i - k][j - k] == '.') {
                                board[i - k][j - k] = '*';
                                break;
                            }
                        }
                    }
                    if(board[i+1][j-1]=='B') {
                        for (int k = 1; i+k < 8 && j-k >=0; k++) {
                            if (board[i + k][j - k] == 'W' || board[i + k][j - k] == '*') {
                                break;
                            }
                            if (board[i + k][j - k] == '.') {
                                board[i + k][j - k] = '*';
                                break;
                            }
                        }
                    }
                    if(board[i-1][j+1]=='B') {
                        for (int k = 1; i-k >=0 && j+k <8; k++) {
                            if (board[i - k][j + k] == 'W' || board[i - k][j + k] == '*') {
                                break;
                            }
                            if (board[i - k][j + k] == '.') {
                                board[i - k][j + k] = '*';
                                break;
                            }
                        }
                    }
                }
            }
            else if(turn==2){
                if(flag_board[i][j]==2) {
                    if (board[i + 1][j] == 'W') {
                        for (int k = i + 2; k < 8; k++) {
                            if (board[k][j] == 'B' || board[k][j] == '*') {
                                break;
                            }
                            if (board[k][j] == '.') {
                                board[k][j] = '*';
                                break;
                            }
                        }
                    }
                    if (board[i - 1][j] == 'W') {
                        for (int k = i - 2; k >= 0; k--) {
                            if (board[k][j] == 'B' || board[k][j] == '*') {
                                break;
                            }
                            if (board[k][j] == '.') {
                                board[k][j] = '*';
                                break;
                            }
                        }
                    }
                    if (board[i][j + 1] == 'W') {
                        for (int k = j + 2; k < 8; k++) {
                            if (board[i][k] == 'B' || board[i][k] == '*') {
                                break;
                            }
                            if (board[i][k] == '.') {
                                board[i][k] = '*';
                                break;
                            }
                        }
                    }
                    if (board[i][j - 1] == 'W') {
                        for (int k = j - 2; k >= 0; k--) {
                            if (board[i][k] == 'B' || board[i][k] == '*') {
                                break;
                            }
                            if (board[i][k] == '.') {
                                board[i][k] = '*';
                                break;
                            }
                        }
                    }
                    if (board[i + 1][j + 1] == 'W') {
                        for (int k = 1;  i+k < 8 && j+k <8 ; k++) {
                            if (board[i + k][j + k] == 'B' || board[i + k][j + k] == '*') {
                                break;
                            }
                            if (board[i + k][j + k] == '.') {
                                board[i + k][j + k] = '*';
                                break;
                            }
                        }
                    }
                    if (board[i - 1][j - 1] == 'W') {
                        for (int k = 1; i-k >= 0 && j-k>= 0; k++) {
                            if (board[i - k][j - k] == 'B' || board[i - k][j - k] == '*') {
                                break;
                            }
                            if (board[i - k][j - k] == '.') {
                                board[i - k][j - k] = '*';
                                break;
                            }
                        }
                    }
                    if (board[i + 1][j - 1] == 'W') {
                        for (int k = 1;i+k < 8 && j-k >=0; k++) {
                            if (board[i + k][j - k] == 'B' || board[i + k][j - k] == '*') {
                                break;
                            }
                            if (board[i + k][j - k] == '.') {
                                board[i + k][j - k] = '*';
                                break;
                            }
                        }
                    }
                    if (board[i - 1][j + 1] == 'W') {
                        for (int k = 1; i-k >=0 && j+k <8; k++) {
                            if (board[i - k][j + k] == 'B' || board[i - k][j + k] == '*') {
                                break;
                            }
                            if (board[i - k][j + k] == '.') {
                                board[i - k][j + k] = '*';
                                break;
                            }
                        }
                    }
                }
            }
            if(board[i][j]!='*' && board[i][j]!='W' && board[i][j]!='B'){
                board[i][j]='.';
            }
        }
    }
}
int positioncount(char board[8][8]){
    int count=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[i][j]=='*'){
                count++;
            }
        }
    }
    return count;
}
void clear_positioning(char board[8][8]){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[i][j]=='*'){
                board[i][j]='.';
            }
        }
    }
}
void print_number_of_beads(int blacknum,int whitenum){
    printf("black: %d\n",blacknum);
    printf("white: %d\n",whitenum);
}
void reverse_dice(char board[8][8],int x,int y,int turn) {
    if (turn == 1) {
        if (board[x][y] == '*') {
            board[x][y] = 'W';
            if (board[x + 1][y] == 'B') {
                for (int i = x + 1; i < 8; i++) {
                    if (board[i][y] == 'W') {
                        for (int j = x + 1; j < i; j++) {
                            board[j][y] = 'W';
                        }
                    }
                }
            }
            if (board[x - 1][y] == 'B') {
                for (int i = x - 1; i >= 0; i--) {
                    if (board[i][y] == 'W') {
                        for (int j = x - 1; j > i; j--) {
                            board[j][y] = 'W';
                        }
                    }
                }
            }
            if (board[x][y + 1] == 'B') {
                for (int i = y + 1; i < 8; i++) {
                    if (board[x][i] == 'W') {
                        for (int j = y + 1; j < i; j++) {
                            board[x][j] = 'W';
                        }
                    }
                }
            }
            if (board[x][y - 1] == 'B') {
                for (int i = y - 1; i >= 0; i--) {
                    if (board[x][i] == 'W') {
                        for (int j = y - 1; j > i; j--) {
                            board[x][j] = 'W';
                        }
                    }
                }
            }
            if (board[x + 1][y + 1] == 'B') {
                for (int i = 1; i < 8; i++) {
                    if (board[x + i][y + i] == 'W') {
                        for (int j = 1; j < i; j++) {
                            board[x + j][y + j] = 'W';
                        }
                    }
                }
            }
            if (board[x - 1][y - 1] == 'B') {
                for (int i = 1; i < 8; i++) {
                    if (board[x - i][y - i] == 'W') {
                        for (int j = 1; j < i; j++) {
                            board[x - j][y - j] = 'W';
                        }
                    }
                }
            }
            if (board[x + 1][y - 1] == 'B') {
                for (int i = 1; i < 8; i++) {
                    if (board[x + i][y - i] == 'W') {
                        for (int j = 1; j < i; j++) {
                            board[x + j][y - j] = 'W';
                        }
                    }
                }
            }
            if (board[x - 1][y + 1] == 'B') {
                for (int i = 1; i < 8; i++) {
                    if (board[x - i][y + i] == 'W') {
                        for (int j = 1; j < i; j++) {
                            board[x - j][y + j] = 'W';
                        }
                    }
                }
            }
        }
    }
    else if (turn == 2) {
        if (board[x][y] == '*') {
            board[x][y] = 'B';
            if (board[x + 1][y] == 'W') {
                for (int i = x + 1; i < 8; i++) {
                    if (board[i][y] == 'B') {
                        for (int j = x + 1; j < i; j++) {
                            board[j][y] = 'B';
                        }
                    }
                }
            }
            if (board[x - 1][y] == 'W') {
                for (int i = x - 1; i >= 0; i--) {
                    if (board[i][y] == 'B') {
                        for (int j = x - 1; j > i; j--) {
                            board[j][y] = 'B';
                        }
                    }
                }
            }
            if (board[x][y + 1] == 'W') {
                for (int i = y + 1; i < 8; i++) {
                    if (board[x][i] == 'B') {
                        for (int j = y + 1; j < i; j++) {
                            board[x][j] = 'B';
                        }
                    }
                }
            }
            if (board[x][y - 1] == 'W') {
                for (int i = y - 1; i >= 0; i--) {
                    if (board[x][i] == 'B') {
                        for (int j = y - 1; j > i; j--) {
                            board[x][j] = 'B';
                        }
                    }
                }
            }
            if (board[x + 1][y + 1] == 'W') {
                for (int i = 1; i < 8; i++) {
                    if (board[x + i][y + i] == 'B') {
                        for (int j = 1; j < i; j++) {
                            board[x + j][y + j] = 'B';
                        }
                    }
                }
            }
            if (board[x - 1][y - 1] == 'W') {
                for (int i = 1; i < 8; i++) {
                    if (board[x - i][y - i] == 'B') {
                        for (int j = 1; j < i; j++) {
                            board[x - j][y - j] = 'B';
                        }
                    }
                }
            }
            if (board[x + 1][y - 1] == 'W') {
                for (int i = 1; i < 8; i++) {
                    if (board[x + i][y - i] == 'B') {
                        for (int j = 1; j < i; j++) {
                            board[x + j][y - j] = 'B';
                        }
                    }
                }
            }
            if (board[x - 1][y + 1] == 'W') {
                for (int i = 1; i < 8; i++) {
                    if (board[x - i][y + i] == 'B') {
                        for (int j = 1; j < i; j++) {
                            board[x - j][y + j] = 'B';
                        }
                    }
                }
            }
        }
    }
}
void printturn(int turn){
    if(turn==1){
        printf("Turn of White\n");
    }
    else{
        printf("Turn of Black\n");
    }
}

#endif
