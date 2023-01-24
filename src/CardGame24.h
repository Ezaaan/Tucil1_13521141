#ifndef CARDGAME_H
#define CARDGAME_H

typedef struct
{   
    int type;
    char ops[3];
    int nums[4];
}Combination;

typedef struct 
{
    Combination buf[255];
    int len;
}Buffer;

char* convertToCard(int num);

int convertToNum(char* card);

void displayOps(Buffer buff);

void process(double nums[], int pos[], int posop[], Buffer *buff);

void checkDuplicate(int type, int pos[], int posop[], Buffer *buff);

void saveToText(Buffer buff, double time);

#endif