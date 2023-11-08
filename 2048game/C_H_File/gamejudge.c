#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "win.h"
#include "lose.h"
#include "randomint.h"
#include "keyjudge.h"
#include "initui.h"

void Gamejudge(int array[4][4]){
    int i;
      for (i = 0; i < 4; ++i) {
          int j;
          for (j = 0; j < 3; ++j) {
              /* 横向和纵向比较挨着的两个元素是否相等，若有相等则游戏不结束 */
              if (array[i][j] == array[i][j + 1] || array[j][i] == array[j + 1][i]) {
                 return;
             }
         }
     }
     for(int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if(array[i][j] == 2048){
                clear();
                refresh();
                endwin();
                Win(array);
            }
        }

    clear();
    refresh();
    endwin();
    Lose(array);
     }    
}

// int main(){
//     int array[4][4] = {0};
//     gamejudge(array);
// }