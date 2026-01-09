#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

  char prev_line[256] = {'\0'};
  memset(prev_line, '\0', 256);

  prev_line[0] = 'a';

  if(strlen(prev_line) > 0){
    printf("true");
  } else {
    printf("false");

  }

  return 0;
}
