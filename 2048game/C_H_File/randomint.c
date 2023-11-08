#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

void Random(int array[4][4]){
    int flag = 0;
    int num[10] = {2,2,2,2,2,2,2,2,2,4};
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if(array[i][j]  == 0){flag++;}
        }
    }

    if(flag == 0){

    }
    else{
        flag = random() % flag;
        int key = 1;
        int k = 0;
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++){
                if(key == 1){
                    if(array[i][j]  == 0 && k != flag){
                    k++;
                    }
                else if (array[i][j]  == 0 && k == flag){
                    array[i][j] = num[random() % 10];
                    key = 0;
                    }
                }
            }
        }
    }
}

int RandomNum(int array[4][4]){
    int i, j;
    srandom(time(NULL));
    Random(array);
}