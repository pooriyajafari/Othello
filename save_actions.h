#include "stdio.h"
#include "cJSON.h"
#include "stdlib.h"
#ifndef OTHELLO_SAVE_ACTIONS_H
#define OTHELLO_SAVE_ACTIONS_H
struct saved_normal_game{
    int gameid;
    char board[8][8];
    int turn;
    int p1score;
    int p2score;
    char names[2][20];
    int state;
};
struct saved_time_game{
    int gameid;
    char board[8][8];
    int turn;
    int p1score;
    int p2score;
    char names[2][20];
    int r1time;
    int r2time;
    int back1;
    int back2;
    int state;
};
char *BoardToString(char board[8][8]){
    char *boardstring = (char *) malloc(sizeof(char) * 65);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8 ; j++) {
            boardstring[i * 8 + j] = board[i][j];
        }
    }
    return boardstring;
}
char *convert_normal_game_to_json(struct saved_normal_game *game,int gamescount){
    cJSON *root = cJSON_CreateArray();
    for(int i=0;i<gamescount;i++) {
        cJSON *gameobject = cJSON_CreateObject();
        cJSON_AddNumberToObject(gameobject, "gameid", game[i].gameid);
        cJSON_AddStringToObject(gameobject, "board", BoardToString(game[i].board));
        cJSON_AddNumberToObject(gameobject, "turn", game[i].turn);
        cJSON_AddNumberToObject(gameobject, "p1score", game[i].p1score);
        cJSON_AddNumberToObject(gameobject, "p2score", game[i].p2score);
        cJSON_AddStringToObject(gameobject, "name1", game[i].names[0]);
        cJSON_AddStringToObject(gameobject, "name2", game[i].names[1]);
        cJSON_AddItemToArray(root, gameobject);
    }
    char *jsonstring = cJSON_Print(root);
    cJSON_Delete(root);
    return jsonstring;
}
struct saved_normal_game * convert_json_to_normal_game(char *jsonstring,int *gamescount){
    cJSON *root = cJSON_Parse(jsonstring);

    *gamescount = cJSON_GetArraySize(root);
    struct saved_normal_game *games = (struct saved_normal_game *) malloc(sizeof(struct saved_normal_game) * (*gamescount+1));
    for (int i = 0; i < *gamescount; i++) {
        cJSON *gameobject = cJSON_GetArrayItem(root, i);
        cJSON *gameid = cJSON_GetObjectItem(gameobject, "gameid");
        cJSON *board = cJSON_GetObjectItem(gameobject, "board");
        cJSON *turn = cJSON_GetObjectItem(gameobject, "turn");
        cJSON *p1score = cJSON_GetObjectItem(gameobject, "p1score");
        cJSON *p2score = cJSON_GetObjectItem(gameobject, "p2score");
        cJSON *name1 = cJSON_GetObjectItem(gameobject, "name1");
        cJSON *name2 = cJSON_GetObjectItem(gameobject, "name2");
        games[i].gameid = gameid->valueint;
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; ++k) {
                games[i].board[j][k] = board->valuestring[j * 8 + k];
            }
        }
        games[i].turn = turn->valueint;
        games[i].p1score = p1score->valueint;
        games[i].p2score = p2score->valueint;
        for (int j = 0; j < 20; j++) {
            games[i].names[0][j] = name1->valuestring[j];
            games[i].names[1][j] = name2->valuestring[j];
        }
    }
    cJSON_Delete(root);
    return games;
}
char *convert_time_game_to_json(struct saved_time_game *game,int gamescount){
    cJSON *root = cJSON_CreateArray();
    for(int i=0;i<gamescount;i++) {
        cJSON *gameobject = cJSON_CreateObject();
        cJSON_AddStringToObject(gameobject, "board", BoardToString(game[i].board));
        cJSON_AddNumberToObject(gameobject, "turn", game[i].turn);
        cJSON_AddNumberToObject(gameobject, "p1score", game[i].p1score);
        cJSON_AddNumberToObject(gameobject, "p2score", game[i].p2score);
        cJSON_AddStringToObject(gameobject, "name1", game[i].names[0]);
        cJSON_AddStringToObject(gameobject, "name2", game[i].names[1]);
        cJSON_AddNumberToObject(gameobject, "r1time", game[i].r1time);
        cJSON_AddNumberToObject(gameobject, "r2time", game[i].r2time);
        cJSON_AddNumberToObject(gameobject, "back1", game[i].back1);
        cJSON_AddNumberToObject(gameobject, "back2", game[i].back2);
        cJSON_AddItemToArray(root, gameobject);
    }
    char *jsonstring = cJSON_Print(root);
    cJSON_Delete(root);
    return jsonstring;
}
struct saved_time_game * convert_json_to_time_game(char *jsonstring,int *gamescount){
    cJSON *root = cJSON_Parse(jsonstring);

    *gamescount = cJSON_GetArraySize(root);
    struct saved_time_game *games = (struct saved_time_game *) malloc(sizeof(struct saved_time_game) * (*gamescount+1));
    for (int i = 0; i < *gamescount; i++) {
        cJSON *gameobject = cJSON_GetArrayItem(root, i);
        cJSON *board = cJSON_GetObjectItem(gameobject, "board");
        cJSON *turn = cJSON_GetObjectItem(gameobject, "turn");
        cJSON *p1score = cJSON_GetObjectItem(gameobject, "p1score");
        cJSON *p2score = cJSON_GetObjectItem(gameobject, "p2score");
        cJSON *name1 = cJSON_GetObjectItem(gameobject, "name1");
        cJSON *name2 = cJSON_GetObjectItem(gameobject, "name2");
        cJSON *r1time = cJSON_GetObjectItem(gameobject, "r1time");
        cJSON *r2time = cJSON_GetObjectItem(gameobject, "r2time");
        cJSON *back1 = cJSON_GetObjectItem(gameobject, "back1");
        cJSON *back2 = cJSON_GetObjectItem(gameobject, "back2");
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; ++k) {
                games[i].board[j][k] = board->valuestring[j * 8 + k];
            }
        }
        games[i].turn = turn->valueint;
        games[i].p1score = p1score->valueint;
        games[i].p2score = p2score->valueint;
        for (int j = 0; j < 20; j++) {
            games[i].names[0][j] = name1->valuestring[j];
            games[i].names[1][j] = name2->valuestring[j];
        }
        games[i].r1time = r1time->valueint;
        games[i].r2time = r2time->valueint;
        games[i].back1 = back1->valueint;
        games[i].back2 = back2->valueint;
    }
    cJSON_Delete(root);
    return games;
}
void find_print_names(struct saved_normal_game *normalgames,struct saved_time_game *timegames,char *name,int gamescount) {
    int j=1;
    for (int i = 0; i < gamescount; i++) {

        if (strcmp(normalgames[i].names[0], name) == 0 && strcmp(normalgames[i].names[1], name) == 0&&normalgames[i].state==1) {
            printf("%d.%s vs %s White=%d Black=%d\n",j, normalgames[i].names[0], normalgames[i].names[1], whitenum(normalgames[i].board), blacknum(normalgames[i].board));
            printf("id:%d\n",normalgames[i].gameid);
            j++;
        }
    }
    int k=j;
    for (int i = 0; i < gamescount; i++) {
        if (strcmp(timegames[i].names[0], name) == 0 && strcmp(timegames[i].names[1], name) == 0&&timegames[i].state==1) {
            printf("%d.%s vs %s White=%d Black=%d\n",j, timegames[i].names[0], timegames[i].names[1], whitenum(timegames[i].board), blacknum(timegames[i].board));
            printf("id:%d\n",timegames[i].gameid);
            k++;
        }
    }
}
struct saved_normal_game *find_normal_game(struct saved_normal_game *normalgames,int gamescount,int gameid){
    for(int i=0;i<gamescount;i++){
        if(normalgames[i].gameid==gameid){
            return &normalgames[i];
        }
    }
    return NULL;
}
struct saved_time_game *find_time_game(struct saved_time_game *timegames,int gamescount,int gameid){
    for(int i=0;i<gamescount;i++){
        if(timegames[i].gameid==gameid){
            return &timegames[i];
        }
    }
    return NULL;
}
#endif