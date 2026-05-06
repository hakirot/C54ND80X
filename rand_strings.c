#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_rand_string();

int main(int argc, char* argv[]) {
  srand(time(0));

  for(int i = 0; i < 10; i++){
    print_rand_string();
  }
  return 0;
}

void print_rand_string() {
  int rand_length = rand() % 6 + 3;
  char rand_str[8] = {'\0'};

  for(int i = 0; i < rand_length; i++){
    int rand_char = rand() % 26 + 65;
    rand_str[i] = (char)rand_char;
  }

  printf("%s", rand_str);
  printf("\n");
}
