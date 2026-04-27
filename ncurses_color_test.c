#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <locale.h>
#include <string.h>

#define BLUE             2

int main(int argc, char* argv[]) {

  setlocale(LC_ALL, "");
  initscr();
  start_color();
  use_default_colors();
  init_pair(BLUE, COLOR_BLUE, COLOR_BLACK);

  cbreak();
  noecho();
  nodelay(stdscr, TRUE);
  keypad(stdscr, TRUE);
  curs_set(FALSE);
  clear();

  int row, col;
  getmaxyx(stdscr, row, col);

  attron(COLOR_PAIR(BLUE));
  attron(A_BOLD);
  char * str = "I am a string";
  mvprintw(row/2, col/2 - strlen(str)/2, "%s", str);
  refresh();
  attroff(COLOR_PAIR(BLUE));

  getchar();  
  endwin();
  return 0;
}
