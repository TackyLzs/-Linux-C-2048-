#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "initui.h"

void initjudge1(int array[4][4]){
    char key = getch();
    switch (key){
    case 27:
        clear();
        refresh();
        endwin();
        break;
    case '\n':
        clear();
        refresh();
        //endwin();
        //box(stdscr,'+','+');
        gamestart(array);
        break;
    default:
        attron(A_BLINK);
        mvaddstr(LINES * 0.7, COLS * 0.40,"Please try again......");
        attroff(A_BLINK);
        initjudge1(array);
        break;
    }
    //endwin();
}

int init(int array[4][4]){

  initscr();
  intrflush(stdscr,false);
  cbreak();
  keypad(stdscr,true);
  box(stdscr,'+','+');
  noecho();  
  curs_set(0);

  attron(A_UNDERLINE);
  mvaddstr(LINES * 0.3, COLS * 0.4, "Welcome To 2048 Game !!!");
  attroff(A_UNDERLINE); 
  mvaddstr(LINES * 0.45, COLS * 0.45, "Start : (Enter)");
  mvaddstr(LINES * 0.5, COLS * 0.46, "Exist : (Esc)");
  mvaddstr(LINES * 0.6, COLS * 0.35,"Please input string Enter/Esc");

  initjudge1(array);

 return 0;
}



