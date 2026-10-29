#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void crit(char * err);

int main(int argc, char* argv[]) {

  crit(ttyname(0));
  
  return 0;
}

void crit(char * err) {
  printf("\x1b[31m%s\n\x1b[0m", err);
  exit(1);
}
