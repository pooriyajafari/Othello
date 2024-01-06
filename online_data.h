#include "stdio.h"
#ifndef OTHELLO_ONLINE_DATA_H
#define OTHELLO_ONLINE_DATA_H
int blacknum(char board[8][8]){
    int blacknum=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[i][j]=='B'){
                blacknum++;
            }
        }
    }
    return blacknum;
}
int whitenum(char board[8][8]){
    int whitenum=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[i][j]=='W'){
                whitenum++;
            }
        }
    }
    return whitenum;
}
#endif
