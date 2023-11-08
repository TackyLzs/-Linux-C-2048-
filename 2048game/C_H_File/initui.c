#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "keyjudge.h"
#include "gamejudge.h"
#include "randomint.h"

void initborder(WINDOW * subwindow){
    wmove(subwindow, 4, 1);
    whline(subwindow, '-', 27);
    wmove(subwindow, 8, 1);
    whline(subwindow, '-', 27);
    wmove(subwindow, 12, 1);
    whline(subwindow, '-', 27);
    wmove(subwindow, 16, 1);
    whline(subwindow, '-', 27);

    wmove(subwindow, 1, 7);
    wvline(subwindow, '|', 15);
    wmove(subwindow, 1, 14);
    wvline(subwindow, '|', 15);
    wmove(subwindow, 1, 21);
    wvline(subwindow, '|', 15);
}

void initarray(int array[4][4], WINDOW * subwindow){
    for(int i = 1; i <= 4; i++){
        for(int j = 1; j <= 4; j++){
            if(array[i-1][j-1] != 0){
                wmove(subwindow, (4 * i) - 2, (7 * j) - 5);
                wprintw(subwindow, "%-5d", array[i-1][j-1]);
            }
        }
    }

}

WINDOW *subwindow = NULL;
int oldarray[4][4] = {0};

void gamestart(int array[4][4]){
    
    
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    subwindow = subwin(stdscr, 24, 29, LINES * 0.07, COLS * 0.35);
    initborder(subwindow);
    box(subwindow,'|','-');
    wmove(subwindow,17, 7);
    wprintw(subwindow, "[W]:up [S]:down");
    wmove(subwindow,19, 5);
    wprintw(subwindow, "[L]:left [D]:right");
    wmove(subwindow,22, 8);
    wprintw(subwindow, "Exit : (Esc)");
    RandomNum(array);
    RandomNum(array);
    initarray(array, subwindow);
    
    while(1){
        
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++)
            {
                oldarray[i][j] = array[i][j];
            }
            
        }
        key(array);
        Gamejudge(array);
        int flag = 0;
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++)
            {
                if(oldarray[i][j] != array[i][j]){
                    flag = 1;
                }
            }
        }
        if(flag){
            RandomNum(array);
        }
        else{
            
        }
        clear();
        wmove(subwindow,17, 7);
        wprintw(subwindow, "[W]:up [S]:down");
        wmove(subwindow,19, 5);
        wprintw(subwindow, "[L]:left [D]:right");
        wmove(subwindow,22, 8);
        wprintw(subwindow, "Exit : (Esc)");
        box(subwindow,'|','-');
        initborder(subwindow);
        initarray(array, subwindow);
        
    }

    //endwin();
}



