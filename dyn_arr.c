#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int   *items;
  size_t count;
  size_t capacity;
} Numbers;

#define da_append(xs, x)\
  do {\
    if(xs.count >= xs.capacity){\
      if(xs.capacity == 0) xs.capacity =  256;\
      else xs.capacity *= 2; \
      xs.items =  realloc(xs.items, xs.capacity*sizeof(*xs.items));\
    }\
    xs.items[xs.count++] = i;\
  } while(0)

int main(int argc, char* argv[]) {
  Numbers xs = {0};
//  1,
//  2,
//  3,
//};
  for(int i = 0; i < 10; i++) da_append(xs, i);
  for(int i = 0; i < xs.count; i++) printf("%d ", xs.items[i]);
  printf("%s", "\n");
  return 0;
}
