#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <locale.h>
#include <unistd.h>

//int SELECTABLE = 0; //debug
//int HITS = 0; //debug

const int BLACK         = 1;
const int RED           = 2;
const int WHITE         = 3;
const int BLACK_RED     = 4;
const int BLACK_WHITE   = 5;
const int GREEN         = 6;

struct Option {
  int selected;
  int selectable;
  char name[256];
  char line[256];
  int price;
  struct Option * next;
  struct Option * prev;
  int line_selected;
};

void error(char * err);
struct Option *init_list();
int is_char_in_search(char * search_str);
void cleanup(struct Option * list);
void print_list(struct Option * list);

int main(int argc, char* argv[]) {

  setlocale(LC_ALL, "");
  initscr();
  start_color();
  use_default_colors();
  init_pair(BLACK, COLOR_BLACK, -1);
  init_pair(RED, COLOR_RED, -1);
  init_pair(WHITE, COLOR_WHITE, -1);
  init_pair(BLACK_RED, COLOR_BLACK, COLOR_RED);
  init_pair(BLACK_WHITE, COLOR_BLACK, COLOR_WHITE);
  init_pair(GREEN, COLOR_GREEN, -1);
  cbreak();
  noecho();
  nodelay(stdscr, TRUE);
  keypad(stdscr, TRUE);
  curs_set(FALSE);

  clear();

  int row, col = 0;
  getmaxyx(stdscr, row, col);

  struct Option *list = init_list();
  print_list(list);

//mvprintw(40, 2, "%s: %d", "SELECTABLE", SELECTABLE);
//mvprintw(41, 2, "%s: %d", "HITS", HITS);

  struct Option * line_selector = list->next;
  while(line_selector->line_selected != 1){
    line_selector = line_selector->next;
  }

  int cache = row + col;
  char input = {'\0'};
  int total = 0;
  while(1){

    // exit on resize
    getmaxyx(stdscr, row, col);
    if(cache != row + col){
      clear();
      print_list(list);
    }

    input = getch();

    if (input != ERR && input != EOF && input > 19 && input < 127 || input == '\n') {
      if(input == 'q'){
        endwin();
        exit(0);
      } else if (input == 'j'){
        struct Option * temp = line_selector->next;
        int i = 0;
        while(temp != NULL){
          if(temp->selectable){
            line_selector->line_selected = 0;
            temp->line_selected = 1;
            line_selector = temp;
            break;
          }

          temp = temp->next;
          i++;
        }
      } else if (input == 'k'){
        struct Option * temp = line_selector->prev;
        while(temp != NULL){
          if(temp->selectable){
            temp->line_selected = 1;
            line_selector->line_selected = 0;
            line_selector = temp;
            break;
          }
          temp = temp->prev;
        }

      } else if (input == '\n'){
        line_selector->selected == 1 ? line_selector->selected = 0 : (line_selector->selected = 1);
      }
      clear();
      print_list(list);
    }

    usleep(10000);
  }

  endwin();
  cleanup(list);
  return 0;
}

void error(char * err) {
  endwin();
  printf("%s\n", err);
  exit(1);
}

struct Option * init_list() {
  FILE *file = fopen("/home/roe/dox/.notes/projects/cyberdeck/cost", "r");

  if (file == NULL){
    error("ERROR: file");
  }

  char line[256];
  int position = 0;
  struct Option *head = NULL;
  struct Option *prev = NULL;
  struct Option *next = NULL;

  int lines = 0;
  int selectable_found = 0;
  while(fgets(line, sizeof(line), file)){

    if (lines == 0){
      struct Option* option =  (struct Option*)malloc(sizeof(struct Option));
      prev = option;
      option->prev = NULL;
      option->next = NULL;

      head = option;
      head->selected = 0;
      head->selectable = 0;
      strcpy(option->name, line);
      option->prev = NULL;
      option->line_selected = 0;

    } else if (lines > 1) {
      struct Option* option =  (struct Option*)malloc(sizeof(struct Option));
      strcpy(option->line, line);
      option->prev = prev;
      option->prev->next = option;
      prev = option;
      option->next = NULL;
      option->line_selected = 0;

      if(is_char_in_search(line)){
        char* tok = strtok(line, "$");
        strcpy(option->name, tok);

        tok = strtok(0, " \n");
        int price = atoi(tok);
        option->price = price;
        if(line[0] == ' '){
          option->selectable = 1;
//        SELECTABLE += 1; //debug

          if(option->prev->name[0] != ' '){
            option->selected = 1;
          }  else {
            option->selected = 0;
          }

          if (selectable_found == 0) {
            option->line_selected = 1;
            selectable_found = 1;
          }
        } else {
          option->selected = 1;
          option->selectable = 0;
        }
      } else {
        char * tok = strtok(line, "\n");
        strcpy(option->name, tok);
      }
    }
    lines++;
  }

  fclose(file);
  refresh();
  return head;
}

void cleanup(struct Option * list) {

}

int is_char_in_search(char * search_str) {

    char search_item = '$';
    for (int i = 0; i < strlen(search_str); i++) {
        if (search_item == search_str[i]) {
            return 1; // Character found
        }
    }
    return 0; // Not found
}

void print_list(struct Option * list){
  struct Option * walker = list;
  int total = 0;

  mvprintw(1, 2, "%s", walker->name);

  struct CUR_POS {
    int x;
    int y;
  };

  struct CUR_POS cur_pos;

  walker = walker->next;

  int i = 0;
  while(walker != NULL){
    if(walker->price > 0){
      if(walker->selectable){
        if(walker->selected){
          total += walker->price;
          attron(COLOR_PAIR(RED));
        } else {
          attron(COLOR_PAIR(BLACK));
        }
      } else {
        if (walker->selected){
          total += walker->price;
        }
        attron(COLOR_PAIR(RED));
      }
      if(walker->line_selected && !walker->selected){attron(COLOR_PAIR(BLACK_RED));}
      if(walker->line_selected && walker->selected){attron(COLOR_PAIR(BLACK_WHITE));}
      if(walker->line_selected){
        cur_pos.x = 2;
        cur_pos.y = 3 + i;
      }
      mvprintw(3 + i, 2, "%s", walker->name);
      mvprintw(3 + i, 26, "%s", "$");
      mvprintw(3 + i, 27, "%d", walker->price);
      attroff(COLOR_PAIR(BLACK));
      attroff(COLOR_PAIR(RED));
    } else {
      mvprintw(3 + i, 2, "%s", walker->name);
    }

    if(strlen(walker->line) > 29 && walker->line[34] == '-'){
      for(int j = 34; j < strlen(walker->line); j++ ){
        mvaddch(3 + i, j + 2, walker->line[j]);
      }
//    HITS += 1;
    }

    walker = walker->next;
    i++;
  }

  attron(COLOR_PAIR(GREEN));
  mvprintw(4 + i, 2, "%s", "TOTAL");
  mvprintw(4 + i, 27, "%s%d", "$", total);
  move(cur_pos.y, cur_pos.x + 2);
  attroff(COLOR_PAIR(GREEN));

  refresh();
}
