#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "keyjudge.h"

void Leftrun(int array[4][4]){
   for(int k = 0; k < 4; k++){
    int j, i;
    for (i = 0, j = 1; j < 4; j++) {
        /* 找出k后面第一个不为空的项，下标为j，之后分三种情况 */
        if (array[k][j] > 0) { 
            /* P1情况，合并 */
            if (array[k][i] == array[k][j]) { 
                array[k][i] = 2 * array[k][i];
                array[k][j] = 0;
                i= i + 1;
            } 
            /* P2情况，移动 */
            else if (array[k][i] == 0) { 
                array[k][i] = array[k][j];
                array[k][j] = 0;            
            } 
            /* P3情况，碰撞 */
            else { 
                array[k][i + 1] = array[k][j];
                /* 如果原先两数不挨着 */
                if (j != i + 1) { 
                    array[k][j] = 0;
                }
                i =i + 1;
            }
        }
    }
   
}
}

void Rightrun(int array[4][4]){
   for(int k = 0; k < 4; k++){
    int j, i;
    for (i = 3, j = 2; j >= 0; j--) {
        /* 找出k后面第一个不为空的项，下标为j，之后分三种情况 */
        if (array[k][j] > 0) { 
            /* P1情况，合并 */
            if (array[k][i] == array[k][j]) { 
                array[k][i] = 2 * array[k][i];
                array[k][j] = 0;
                i= i - 1;
            } 
            /* P2情况，移动 */
            else if (array[k][i] == 0) { 
                array[k][i] = array[k][j];
                array[k][j] = 0;            
            } 
            /* P3情况，碰撞 */
            else { 
                array[k][i - 1] = array[k][j];
                /* 如果原先两数不挨着 */
                if (j != i - 1) { 
                    array[k][j] = 0;
                }
                i =i - 1;
            }
        }
    }
   
}
}

void Uprun(int array[4][4]){
   for(int k = 0; k < 4; k++){
    int j, i;
    for (i = 0, j = 1; j < 4; j++) {
        /* 找出k后面第一个不为空的项，下标为j，之后分三种情况 */
        if (array[j][k] > 0) { 
            /* P1情况，合并 */
            if (array[i][k] == array[j][k]) { 
                array[i][k] = 2 * array[i][k];
                array[j][k] = 0;
                i= i + 1;
            } 
            /* P2情况，移动 */
            else if (array[i][k] == 0) { 
                array[i][k] = array[j][k];
                array[j][k] = 0;            
            } 
            /* P3情况，碰撞 */
            else { 
                array[i + 1][k] = array[j][k];
                /* 如果原先两数不挨着 */
                if (j != i + 1) { 
                    array[j][k] = 0;
                }
                i =i + 1;
            }
        }
    }
   
}
}

void Downrun(int array[4][4]){
   for(int k = 0; k < 4; k++){
    int j, i;
    for (i = 3, j = 2; j >= 0; j--) {
        /* 找出k后面第一个不为空的项，下标为j，之后分三种情况 */
        if (array[j][k] > 0) { 
            /* P1情况，合并 */
            if (array[i][k] == array[j][k]) { 
                array[i][k] = 2 * array[i][k];
                array[j][k] = 0;
                i= i - 1;
            } 
            /* P2情况，移动 */
            else if (array[i][k] == 0) { 
                array[i][k] = array[j][k];
                array[j][k] = 0;            
            } 
            /* P3情况，碰撞 */
            else { 
                array[i - 1][k] = array[j][k];
                /* 如果原先两数不挨着 */
                if (j != i - 1) { 
                    array[j][k] = 0;
                }
                i =i - 1;
            }
        }
    }
   
}
}

void key(int array[4][4]){
    // cbreak();
    // noecho();
    keypad(subwindow,true); 
    curs_set(0);
    int ch = wgetch(subwindow);
    switch(ch){
        case (int)'w':case (int)'W':case KEY_UP:
            Uprun(array);
            break;
        case (int)'s':case (int)'S':case KEY_DOWN:
            Downrun(array);
            break;
        case (int)'a':case (int)'A':case KEY_LEFT:
            Leftrun(array);
            break;
        case (int)'d':case (int)'D':case KEY_RIGHT:
            Rightrun(array);
            break;
        case 27:
            clear();
            refresh();
            endwin();
            exit(0);
            break;
        default:
            key(array);
            break;
    }
}

// int main(){
//     initscr();
//     intrflush(stdscr,false);
//     cbreak();
//     keypad(stdscr,true);
//     noecho();  
//     curs_set(0);
    
//     key(a);
// }