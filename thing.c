#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_helped() {
  printf("Usage:\nasdf\nasdf\nsadf\n");
}

int input_color(char * arg){
  if (strcmp(arg, "black") == 0) {
      return 0;
  } else if (strcmp(arg, "red") == 0) {
      return 1;
  } else if (strcmp(arg, "green") == 0) {
      return 2;
  } else if (strcmp(arg, "yellow") == 0) {
      return 3;
  } else if (strcmp(arg, "blue") == 0) {
      return 4;
  } else if (strcmp(arg, "magenta") == 0) {
      return 5;
  } else if (strcmp(arg, "cyan") == 0) {
      return 6;
  } else if (strcmp(arg, "white") == 0) {
      return 7;
  } else {
      return -1;
  }
}

void error(char * err) {
  printf("%s\n", err);
  exit(1);
}

int main(int argc, char* argv[]) {

  int FOREGROUND = 0;
  int BACKGROUND = 0;

  for (int i = 0; i < argc; i++) {
    if (strcmp(argv[i], "-f") == 0 || strcmp(argv[i], "--foreground") == 0){
      if(i + 1 < argc){
        FOREGROUND = input_color(argv[i + 1]);
        if (FOREGROUND == -1) error("bad arg\n");
      } else {
        get_helped();
        error("bad arg\n");
      }
    } else if (strcmp(argv[i], "-b") == 0 || strcmp(argv[i], "--background") == 0){
      if(i + 1 < argc){
        BACKGROUND = input_color(argv[i + 1]);
        if (BACKGROUND == -1) error("bad arg");
      } else {
        get_helped();
        error("bad arg\n");
      }
    }
  }

  printf("FOREGROUND: %d\n", FOREGROUND );
  printf("BACKGROUND: %d\n", BACKGROUND );

  return 0;
}

