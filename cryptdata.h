#include "stdio.h"
#include "string.h"
#ifndef OTHELLO_CRYPTDATA_H
#define OTHELLO_CRYPTDATA_H

void encryptAffinecipherFile(char *input,char *file,int a,int b){

    FILE *fp = fopen(file, "wb");
    int length = strlen(input);
    for (int i = 0; i < length; ++i) {
        fputc((char)((a*(input[i])+b)%256),fp);
    }
    fclose(fp);
}
void decryptAffinecipherFile(char *file,char *output,int a,int b){
    FILE *fp = fopen(file, "rb");
    char *text = NULL;
    int len = 0;
    if (fp != NULL)
    {
        fseek(fp, 0, SEEK_END);
        len = ftell(fp);
        rewind(fp);

        text = (char *)malloc(sizeof(char) * (len + 1));
        if (text != NULL)
        {
            fread(text, sizeof(char), len, fp);
            text[len] = '\0';
        }
        fclose(fp);
    }

    int z;
    a= a % 256;
    for (int i = 1; i < 256; i++) {
        if ((a * i) % 256 == 1) {
            z=i;
        }
    }
    for (int i = 0; i < len; ++i) {
        output[i]= (z * (text[i] - b + 256)) % 256;
    }
    output[len]='\0';
}
#endif