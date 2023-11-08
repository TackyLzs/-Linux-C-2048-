#ifndef __INITUI_H__
#define __INITUI_H__
// #include <curses.h>

extern WINDOW * subwindow;
void initborder(WINDOW * subwindow);
void initarray(int array[4][4], WINDOW * subwindow);
int gamestart();

#endif