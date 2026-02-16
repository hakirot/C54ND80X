#include <stdio.h>
#include <wait.h>
#include <unistd.h>

int main(int argc, char* argv[]) {

  FILE *proc;
  proc = popen("ueberzug layer", "w");

  if (!proc) return 1;

  usleep(1000000);
  fprintf(proc, "{\"action\":\"add\",\"identifier\":\"preview\",\"max_height\":40,\"max_width\":40,\"path\":\"/home/roe/pix/sara/sara_deck\",\"x\":0,\"y\":0}\n");
  fflush(proc);
  if (ferror(proc)) return 2;

  while(1){
    usleep(10000);
    char input = getchar();
    if (input == 'q') break;
  }

  if (pclose(proc) != 0)
  {
      return 3;
  }
  
  return 0;
}
