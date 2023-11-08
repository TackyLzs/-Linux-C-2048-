#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "initui.h"

void initjudge2(int array[4][4]){
    int newarray[4][4] = {0};
    char key = getch();
    switch (key){
    case 27:
        clear();
        refresh();
        endwin();
        exit(0);
        break;
    case '\n':
        clear();
        refresh();
        endwin();
        gamestart(newarray);
        break;
    default:
        attron(A_BLINK);
        mvaddstr(LINES * 0.7, COLS * 0.40,"Please try again......");
        attroff(A_BLINK);
        initjudge2(array);
        break;
    }
    
}

int Lose(int array[4][4]){
  initscr();
  cbreak();
  keypad(stdscr,true);
  box(stdscr,'+','+');
  noecho(); 
  curs_set(0);

  mvaddstr(LINES * 0.3, COLS * 0.47, "You Lose !!!");
  mvaddstr(LINES * 0.45, COLS * 0.45, "Again : (Enter)");
  mvaddstr(LINES * 0.5, COLS * 0.46, "Exist : (Esc)");
  mvaddstr(LINES * 0.6, COLS * 0.35,"Please input string Enter/Esc");
  move(LINES - 1,COLS * 0.5);

  initjudge2(array);

 return 0;
}



