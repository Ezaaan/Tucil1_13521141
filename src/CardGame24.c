#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <unistd.h>
#include "CardGame24.h"

int main(){
    //Begin time1
    double time1 = 0.0;
    clock_t begin1 = clock();
    printf(".------..------.        .------..------..------..------.        .------..------..------..------..------.\n");
    printf("|2.--. ||4.--. | .-.    |C.--. ||A.--. ||R.--. ||D.--. | .-.    |G.--. ||A.--. ||M.--. ||E.--. ||!.--. |\n");
    printf("| (\\/) || :/\\: |(( ))   | :/\\: || (\\/) || :(): || :/\\: |(( ))   | :/\\: || (\\/) || (\\/) || (\\/) || (\\/) |\n");
    printf("| :\\/: || :\\/: | '-.-.  | :\\/: || :\\/: || ()() || (__) | '-.-.  | :\\/: || :\\/: || :\\/: || :\\/: || :\\/: |\n");
    printf("| '--'2|| '--'4|  (( )) | '--'C|| '--'A|| '--'R|| '--'D|  (( )) | '--'G|| '--'A|| '--'M|| '--'E|| '--'!|\n");
    printf("`------'`------'   '-'  `------'`------'`------'`------'   '-'  `------'`------'`------'`------'`------'\n");
    printf("\n");
    printf("|------------------------------------------------------------------------------------------------------|\n");
    printf("| Welcome to the 24 Card Game!                                                                         |\n");
    printf("|------------------------------------------------------------------------------------------------------|\n");
    printf("| How do you want to play the game?                                                                    |\n");
    printf("| 1. Random cards                                                                                      |\n");
    printf("| 2. Custom cards                                                                                      |\n");
    printf("|------------------------------------------------------------------------------------------------------|\n");
    printf("| Your input: ");
    
    //End time1
    clock_t end1 = clock();
    time1 += (double)(end1 - begin1) / CLOCKS_PER_SEC;

    int input;
    scanf("%d", &input);
    while(input < 1 || input > 2){
        printf("| Masukan tidak sesuai. Silahkan coba lagi                                                             |\n");
        printf("| Your input: ");
        scanf("%d", &input);
    }
    
    //Begin time2
    double time2 = 0.0;
    double time2_5 = 0.0;
    clock_t begin2 = clock();

    int num1, num2, num3, num4;
    char *card1 = malloc(sizeof(char) * 2);
    char *card2 = malloc(sizeof(char) * 2);
    char *card3 = malloc(sizeof(char) * 2);
    char *card4 = malloc(sizeof(char) * 2);
    if(input == 1){
        srand(time(NULL));

        num1 = (rand() % 12) + 1;
        num2 = (rand() % 12) + 1;
        num3 = (rand() % 12) + 1;
        num4 = (rand() % 12) + 1;

        // printf("THESE: %d %d %d %d\n", num1,num2,num3,num4);

        card1 = convertToCard(num1);
        card2 = convertToCard(num2);
        card3 = convertToCard(num3);
        card4 = convertToCard(num4);

        //End time2
        clock_t end2 = clock();
        time2 += (double)(end2 - begin2) / CLOCKS_PER_SEC;
        //printf("%s %s %s %s\n", card1, card2, card3, card4);

    }

    else{
        printf("|------------------------------------------------------------------------------------------------------|\n");
        printf("| Please input 4 cards: ");

        //End time2
        clock_t end2 = clock();
        time2 += (double)(end2 - begin2) / CLOCKS_PER_SEC;

        scanf("%s %s %s %s", card1, card2, card3, card4);

        //Begin time2_5
        clock_t begin2_5 = clock();
        num1 = convertToNum(card1);
        num2 = convertToNum(card2);
        num3 = convertToNum(card3);
        num4 = convertToNum(card4);
        //End time2_5
        clock_t end2_5 = clock();
        time2_5 += (double)(end2_5 - begin2_5) / CLOCKS_PER_SEC;

    }

    //Begin time3
    double time3 = 0.0;
    clock_t begin3 = clock();
    
    printf("|------------------------------------------------------------------------------------------------------|\n");
    printf("|------------------------------------------------------------------------------------------------------|\n");
    printf("| Your cards: |                               %s     %s     %s     %s                                      |\n", card1, card2, card3, card4);
    int count = 0;
    double nums[4];
    nums[0] = num1;
    nums[1] = num2;
    nums[2] = num3;
    nums[3] = num4;
    int pos[4];
    int posOP[4];
    Buffer buff;
    buff.len = 0;
    int current = 0;
    process(nums, pos, posOP, &buff);

    printf("|------------------------------------------------------------------------------------------------------|\n");

    if(buff.len == 0){
        printf("|                                           There are no solutions!                                    |\n");
    }
    else{
        printf("|                                             %d solutions found                                       ||\n", buff.len);
        printf("|------------------------------------------------------------------------------------------------------|\n");
        displayOps(buff);
    }
    printf("|------------------------------------------------------------------------------------------------------|\n");
    printf("| Do you want to save the results to a text file? (y/n)                                                |\n");
    printf("|------------------------------------------------------------------------------------------------------|\n");
    char yon;
    printf("| Your input: ");
    
    //End time3
    clock_t end3 = clock();
    time3 += (double)(end3 - begin3) / CLOCKS_PER_SEC;
    
    scanf(" %c", &yon);
    //scanf("%c", &yon);
    while(yon != 'Y' && yon != 'y' && yon != 'N' && yon != 'n'){
        printf("| Invalid input. Please try again\n");
        printf("| Your input: ");
        scanf("%c", &yon);
    }
    
    double timeAmount = time1 + time2 + time2_5 + time3;
    
    if((yon == 'Y' || yon == 'y') && buff.len == 0){
        printf("|------------------------------------------------------------------------------------------------------|\n");
        printf("| There are no solutions available, do you still want to save the results? (y/n)                       |\n");
        printf("|------------------------------------------------------------------------------------------------------|\n");
        printf("| Your input: ");
        scanf(" %c", &yon);
        while(yon != 'Y' && yon != 'y' && yon != 'N' && yon != 'n'){
            printf("| Invalid input. Please try again\n");
            printf("| Your input: ");
            scanf("%c", &yon);
        }
    }
    if(yon == 'Y' || yon == 'y'){
        saveToText(buff, timeAmount);
    }
    printf("|------------------------------------------------------------------------------------------------------|\n");
    printf("|------------------------------------------------------------------------------------------------------|\n");
    printf("|                                 Thank you for playing the 24 Card Game!                              |\n");
    printf("|------------------------------------------------------------------------------------------------------|\n");
    printf("| Execution time: %f                                                                             |\n", timeAmount);
    printf("|------------------------------------------------------------------------------------------------------|\n");
    sleep(3);
    return 0;
}

char* convertToCard(int num){
    if(num == 1){
        return "A";
    }
    if(num == 2){
        return "2";
    }
    if(num == 3){
        return "3";
    }
    if(num == 4){
        return "4";
    }
    if(num == 5){
        return "5";
    }
    if(num == 6){
        return "6";
    }
    if(num == 7){
        return "7";
    }
    if(num == 8){
        return "8";
    }
    if(num == 9){
        return "9";
    }
    if(num == 10){
        return "10";
    }
    if(num == 11){
        return "J";
    }
    if(num == 12){
        return "Q";
    }
    if(num == 13){
        return "K";
    }
}

int convertToNum(char* card){
    if(strcmp(card, "A") == 0 || strcmp(card, "1") == 0){
        return 1;
    }
    if(strcmp(card, "2") == 0){
        return 2;
    }
    if(strcmp(card, "3") == 0){
        return 3;
    }
    if(strcmp(card, "4") == 0){
        return 4;
    }
    if(strcmp(card, "5") == 0){
        return 5;
    }
    if(strcmp(card, "6") == 0){
        return 6;
    }
    if(strcmp(card, "7") == 0){
        return 7;
    }
    if(strcmp(card, "8") == 0){
        return 8;
    }
    if(strcmp(card, "9") == 0){
        return 9;
    }
    if(strcmp(card, "10") == 0){
        return 10;
    }
    if(strcmp(card, "J") == 0 || strcmp(card, "11") == 0){
        return 11;
    }
    if(strcmp(card, "Q") == 0 || strcmp(card, "12") == 0){
        return 12;
    }
    if(strcmp(card, "K") == 0 || strcmp(card, "13") == 0){
        return 13;
    }
}

void displayOps(Buffer buff){
    int res1, res2, res;
    char ops[4];
    ops[0] = '+'; ops[1] = '-'; ops[2] = '*'; ops[3] = '/';

    for(int i = 0; i < buff.len; i++){
        if(buff.buf[i].type == 1){
            printf("| (%d %c %d) %c (%d %c %d)\n", buff.buf[i].nums[0], buff.buf[i].ops[0], buff.buf[i].nums[1], buff.buf[i].ops[1], buff.buf[i].nums[2], buff.buf[i].ops[2], buff.buf[i].nums[3]);
        }

        if(buff.buf[i].type == 2){
            printf("| ((%d %c %d) %c %d) %c %d\n", buff.buf[i].nums[0], buff.buf[i].ops[0], buff.buf[i].nums[1], buff.buf[i].ops[1], buff.buf[i].nums[2], buff.buf[i].ops[2], buff.buf[i].nums[3]);
        }

        if(buff.buf[i].type == 3){
            printf("| (%d %c (%d %c %d)) %c %d\n", buff.buf[i].nums[0], buff.buf[i].ops[0], buff.buf[i].nums[1], buff.buf[i].ops[1], buff.buf[i].nums[2], buff.buf[i].ops[2], buff.buf[i].nums[3]);
        }

        if(buff.buf[i].type == 4){
            printf("| %d %c ((%d %c %d) %c %d)\n", buff.buf[i].nums[0], buff.buf[i].ops[0], buff.buf[i].nums[1], buff.buf[i].ops[1], buff.buf[i].nums[2], buff.buf[i].ops[2], buff.buf[i].nums[3]);
        }

        if(buff.buf[i].type == 5){
            printf("| %d %c (%d %c (%d %c %d))\n", buff.buf[i].nums[0], buff.buf[i].ops[0], buff.buf[i].nums[1], buff.buf[i].ops[1], buff.buf[i].nums[2], buff.buf[i].ops[2], buff.buf[i].nums[3]);
        }
    }
}

void process(double nums[], int pos[], int posop[], Buffer *buff){
    char ops[4];
    ops[0] = '+'; ops[1] = '-'; ops[2] = '*'; ops[3] = '/';
    for(int i = 0; i < 4; i++){
        pos[0] = nums[i];
        for(int j = 0; j < 4; j++){
            if(j!= i){
                pos[1] = nums[j];
                for(int k = 0; k < 4; k++){
                    if(k != i && k != j){
                        pos[2] = nums[k];
                        for(int l = 0; l < 4; l++){
                            if(l != i && l != j && l !=k){
                                pos[3] = nums[l];

                                for(int z = 0; z < 4; z++){
                                    posop[0] = z;
                                    for(int x = 0; x < 4; x++){
                                        posop[1] = x;
                                        for(int c = 0; c < 4; c++){
                                            posop[2] = c;
                                            int res1, res2, res;
                                            char ops[4];
                                            ops[0] = '+'; ops[1] = '-'; ops[2] = '*'; ops[3] = '/';

                                            //TYPE 1
                                            //RES1
                                            if(posop[0] == 0){
                                                res1 = pos[0] + pos[1];
                                            }
                                            if(posop[0] == 1){
                                                res1 = pos[0] - pos[1];
                                            }
                                            if(posop[0] == 2){
                                                res1 = pos[0] * pos[1];
                                            }
                                            if(posop[0] == 3){
                                                if(pos[1] != 0 && pos[0] % pos[1] == 0){
                                                    res1 = pos[0] / pos[1];
                                                }
                                                else{
                                                    res1 = 1000;
                                                }
                                            }

                                            //RES2
                                            if(posop[2] == 0){
                                                res2 = pos[2] + pos[3];
                                            }
                                            if(posop[2] == 1){
                                                res2 = pos[2] - pos[3];
                                            }
                                            if(posop[2] == 2){
                                                res2 = pos[2] * pos[3];
                                            }
                                            if(posop[2] == 3){
                                                if(pos[3] != 0 && pos[2] % pos[3] == 0){
                                                    res2 = pos[2] / pos[3];
                                                }
                                                else{
                                                    res2 = 1000;
                                                }
                                            }

                                            //RESULT
                                            if(posop[1] == 0){
                                                res = res1 + res2;
                                            }
                                            if(posop[1] == 1){
                                                res = res1 - res2;
                                            }
                                            if(posop[1] == 2){
                                                res = res1 * res2;
                                            }
                                            if(posop[1] == 3){
                                                if(res2 != 0 && res1 % res2 == 0){
                                                    res = res1 / res2;
                                                }
                                                else{
                                                    res = 1000;
                                                }
                                            }

                                            //check
                                            if(res == 24){
                                                checkDuplicate(1, pos, posop, &(*buff));
                                            }

                                            //TYPE 2
                                            //printf("TYPE 2 TEST\n");
                                            //RES1
                                            if(posop[0] == 0){
                                                res1 = pos[0] + pos[1];
                                            }
                                            if(posop[0] == 1){
                                                res1 = pos[0] - pos[1];
                                            }
                                            if(posop[0] == 2){
                                                res1 = pos[0] * pos[1];
                                            }
                                            if(posop[0] == 3){
                                                if(pos[1] != 0 && pos[0] % pos[1] == 0){
                                                    res1 = pos[0] / pos[1];
                                                }
                                                else{
                                                    res1 = 1000;
                                                }
                                            }

                                            //RES2
                                            if(posop[1] == 0){
                                                res2 = res1 + pos[2];
                                            }
                                            if(posop[1] == 1){
                                                res2 = res1 - pos[2];
                                            }
                                            if(posop[1] == 2){
                                                res2 = res1 * pos[2];
                                            }
                                            if(posop[1] == 3){
                                                if(pos[2] != 0 && res1 % pos[2] == 0){
                                                    res2 = res1 / pos[2];
                                                }
                                                else{
                                                    res2 = 1000;
                                                }
                                            }

                                            //RESULT
                                            if(posop[2] == 0){
                                                res = res2 + pos[3];
                                            }
                                            if(posop[2] == 1){
                                                res = res2 - pos[3];
                                            }
                                            if(posop[2] == 2){
                                                res = res2 * pos[3];
                                            }
                                            if(posop[2] == 3){
                                                if(pos[3] != 0 && res2 % pos[3] == 0){
                                                    res = res2 / pos[3];
                                                }
                                                else{
                                                    res = 1000;
                                                }
                                            }

                                            //CHECK
                                            if(res == 24){
                                                checkDuplicate(2, pos, posop, &(*buff));
                                            }

                                            //TYPE 3
                                            //printf("TYPE 3 TEST\n");
                                            //RES1
                                            if(posop[1] == 0){
                                                res1 = pos[1] + pos[2];
                                            }
                                            if(posop[1] == 1){
                                                res1 = pos[1] - pos[2];
                                            }
                                            if(posop[1] == 2){
                                                res1 = pos[1] * pos[2];
                                            }
                                            if(posop[1] == 3){
                                                if(pos[2] != 0 && pos[1] % pos[2] == 0){
                                                    res1 = pos[1] / pos[2];
                                                }
                                                else{
                                                    res1 = 1000;
                                                }
                                            }

                                            //RES2
                                            if(posop[0] == 0){
                                                res2 = pos[0] + res1;
                                            }
                                            if(posop[0] == 1){
                                                res2 = pos[0] - res1;
                                            }
                                            if(posop[0] == 2){
                                                res2 = pos[0] * res1;
                                            }
                                            if(posop[0] == 3){
                                                if(res1 != 0 && pos[0] % res1 == 0){
                                                    res2 = pos[0] / res1;
                                                }
                                                else{
                                                    res2 = 1000;
                                                }
                                            }

                                            //RESULT
                                            if(posop[2] == 0){
                                                res = res2 + pos[3];
                                            }
                                            if(posop[2] == 1){
                                                res = res2 - pos[3];
                                            }
                                            if(posop[2] == 2){
                                                res = res2 * pos[3];
                                            }
                                            if(posop[2] == 3){
                                                if(pos[3] != 0 && res2 % pos[3] == 0){
                                                    res = res2 / pos[3];
                                                }
                                                else{
                                                    res = 1000;
                                                }
                                            }

                                            //CHECK
                                            if(res == 24){
                                                checkDuplicate(3, pos, posop, &(*buff));
                                            }

                                            //TYPE 4
                                            //printf("TYPE 4 TEST\n");
                                            //RES1
                                            if(posop[1] == 0){
                                                res1 = pos[1] + pos[2];
                                            }
                                            if(posop[1] == 1){
                                                res1 = pos[1] - pos[2];
                                            }
                                            if(posop[1] == 2){
                                                res1 = pos[1] * pos[2];
                                            }
                                            if(posop[1] == 3){
                                                if(pos[2] != 0 && pos[1] % pos[2] == 0){
                                                    res1 = pos[1] / pos[2];
                                                }
                                                else{
                                                    res1 = 1000;
                                                }
                                            }

                                            //RES2
                                            if(posop[2] == 0){
                                                res2 = res1 + pos[3];
                                            }
                                            if(posop[2] == 1){
                                                res2 = res1 - pos[3];
                                            }
                                            if(posop[2] == 2){
                                                res2 = res1 * pos[3];
                                            }
                                            if(posop[2] == 3){
                                                if(pos[3] != 0 && res1 % pos[3] == 0){
                                                    res2 = res1 / pos[3];
                                                }
                                                else{
                                                    res2 = 1000;
                                                }
                                            }

                                            //RESULT
                                            if(posop[0] == 0){
                                                res = pos[0] + res2;
                                            }
                                            if(posop[0] == 1){
                                                res = pos[0] - res2;
                                            }
                                            if(posop[0] == 2){
                                                res = pos[0] * res2;
                                            }
                                            if(posop[0] == 3){
                                                if(res2 != 0 && pos[0] % res2 == 0){
                                                    res = pos[0] / res2;
                                                }
                                                else{
                                                    res = 1000;
                                                }
                                            }

                                            //CHECK
                                            if(res == 24){
                                                checkDuplicate(4, pos, posop, &(*buff));
                                            }

                                            //TYPE 5
                                            //printf("TYPE 5 TEST\n");
                                            //RES1
                                            if(posop[2] == 0){
                                                res1 = pos[2] + pos[3];
                                            }
                                            if(posop[2] == 1){
                                                res1 = pos[2] - pos[3];
                                            }
                                            if(posop[2] == 2){
                                                res1 = pos[2] * pos[3];
                                            }
                                            if(posop[2] == 3){
                                                if(pos[3] != 0 && pos[2] % pos[3] == 0){
                                                    res1 = pos[2] / pos[3];
                                                }
                                                else{
                                                    res1 = 1000;
                                                }
                                            }

                                            //RES2
                                            if(posop[1] == 0){
                                                res2 = pos[1] + res1;
                                            }
                                            if(posop[1] == 1){
                                                res2 = pos[1] - res1;
                                            }
                                            if(posop[1] == 2){
                                                res2 = pos[1] * res1;
                                            }
                                            if(posop[1] == 3){
                                                if(res1 != 0 && pos[1] % res1 == 0){
                                                    res2 = pos[1] / res1;
                                                }
                                                else{
                                                    res2 = 1000;
                                                }
                                            }

                                            //RESULT
                                            if(posop[0] == 0){
                                                res = pos[0] + res2;
                                            }
                                            if(posop[0] == 1){
                                                res = pos[0] - res2;
                                            }
                                            if(posop[0] == 2){
                                                res = pos[0] * res2;
                                            }
                                            if(posop[0] == 3){
                                                if(res2 != 0 && pos[0] % res2 == 0){
                                                    res = pos[0] / res2;
                                                }
                                                else{
                                                    res = 1000;
                                                }
                                            }

                                            //CHECK
                                            if(res == 24){
                                                checkDuplicate(5, pos, posop, &(*buff));
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void checkDuplicate(int type, int pos[], int posop[], Buffer *buff){
    //printf("TEST HERE\n%d\n", (*buff).len);
    char ops[4];
    ops[0] = '+'; ops[1] = '-'; ops[2] = '*'; ops[3] = '/';
    
    if((*buff).len == 0){
        for(int i = 0; i < 4; i++){
            (*buff).buf[0].nums[i] = pos[i];
        }
        for(int i = 0; i < 3; i++){
            (*buff).buf[0].ops[i] = ops[posop[i]];
        }
        (*buff).buf[0].type = type;
        (*buff).len++;
    }
        
    else{
        int flag1;
        int flag2;
        for(int i = 0; i < (*buff).len; i++){
            flag1 = 1;
            flag2 = 1;
            //Check if it's the same type
            if((*buff).buf[i].type == type){
                for(int j = 0; j < 4; j++){
                    if((*buff).buf[i].nums[j] != pos[j]){
                        flag1 = 0;
                        break;
                    }
                }
                for(int j = 0; j < 3; j++){
                    if((*buff).buf[i].ops[j] != ops[posop[j]]){
                        flag2 = 0;
                        break;
                    }
                }
            }else{
                flag1 = 0;
                flag2 = 0;
            }

            if(flag1 == 1 && flag2 == 1){
                //printf("fail\n");
                break;
            }
        }

        //If there's no duplicates, then add
        if(flag1 == 0 || flag2 == 0){
            //printf("Succeed\n");
            for(int i = 0; i < 4; i++){
                (*buff).buf[(*buff).len].nums[i] = pos[i];
            }
            for(int i = 0; i < 3; i++){
                (*buff).buf[(*buff).len].ops[i] = ops[posop[i]];
            }
            (*buff).buf[(*buff).len].type = type;
            (*buff).len++;
        }
    }
}

void saveToText(Buffer buff, double time){
    printf("|------------------------------------------------------------------------------------------------------|\n");
    char name[100];
    printf("| Type a name for the file: ");
    scanf(" %[^\n]%*c", name);
    char text[5] = ".txt";
    char filename[100];
    int i = 0; int j = 0;
    
    while (name[i] != '\0') {
        filename[j] = name[i];
        i++;
        j++;
    }
   
    i = 0;
    while (text[i] != '\0') {
        filename[j] = text[i];
        i++;
        j++;
    }
    filename[j] = '\0';


    FILE *file = fopen(filename, "w");

    if(buff.len != 0){
        fprintf(file, "%d solutions found\n", buff.len);
        for(int i = 0; i < buff.len; i++){
            if(buff.buf[i].type == 1){
                fprintf(file, "(%d %c %d) %c (%d %c %d)\n", buff.buf[i].nums[0], buff.buf[i].ops[0], buff.buf[i].nums[1], buff.buf[i].ops[1], buff.buf[i].nums[2], buff.buf[i].ops[2], buff.buf[i].nums[3]);
            }else if(buff.buf[i].type == 2){
                fprintf(file, "((%d %c %d) %c %d) %c %d\n", buff.buf[i].nums[0], buff.buf[i].ops[0], buff.buf[i].nums[1], buff.buf[i].ops[1], buff.buf[i].nums[2], buff.buf[i].ops[2], buff.buf[i].nums[3]);
            }else if(buff.buf[i].type == 3){
                fprintf(file, "(%d %c (%d %c %d)) %c %d\n", buff.buf[i].nums[0], buff.buf[i].ops[0], buff.buf[i].nums[1], buff.buf[i].ops[1], buff.buf[i].nums[2], buff.buf[i].ops[2], buff.buf[i].nums[3]);
            }else if(buff.buf[i].type == 4){
                fprintf(file, "%d %c ((%d %c %d) %c %d)\n", buff.buf[i].nums[0], buff.buf[i].ops[0], buff.buf[i].nums[1], buff.buf[i].ops[1], buff.buf[i].nums[2], buff.buf[i].ops[2], buff.buf[i].nums[3]);
            }else{
                fprintf(file, "%d %c (%d %c (%d %c %d))\n", buff.buf[i].nums[0], buff.buf[i].ops[0], buff.buf[i].nums[1], buff.buf[i].ops[1], buff.buf[i].nums[2], buff.buf[i].ops[2], buff.buf[i].nums[3]);
            }
        }
    }else{
        fprintf(file, "There are no solutions!\n");
    }
    fprintf(file, "Execution time: %f\n", time);
    fclose(file);
    printf("|------------------------------------------------------------------------------------------------------|\n");
    printf("|                              The solutions have been successfully saved!                             |\n");
}