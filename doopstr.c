#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_char_in_list(char i, char* list);

int main(int argc, char* argv[]) {

  if (argc != 2) {
    perror("no\n");
    exit(1);
  }

  char * str = argv[1];
//printf("%s\n", str);

  char list[100] = {'\0'};

  for (int i = 0; i < strlen(str); i++){
    if(!is_char_in_list(str[i], list)){
      list[strlen(list)] = str[i];
    }
  }

  printf("RESULT: %s\n", list);

  // strings with a semicolon will be run as commands somehow

  return 0;
}

int is_char_in_list(char i, char* list){

  for(int j = 0; j < strlen(list); j++){
    if(i == list[j]) return 1;
  }

  return 0;
}

