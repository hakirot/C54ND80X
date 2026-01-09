#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

FILE * open_filew(char * path);
FILE * open_filer(char * path);

int main(int argc, char* argv[]) {

  printf("%s", errno);

// 1   Operation not permitted
// 2   No such file or directory
// 3   No such process
// 4   Interrupted system call
// 5   I/O error
// 6   No such device or address
// 7   The argument list is too long
// 8   Exec format error
// 9   Bad file number
// 10  No child processes
// 11  Try again
// 12  Out of memory
// 13  Permission denied

//char * file_path = "/sys/class/backlight/intel_backlight/brightness";
//char * file_path = "/sys/class/backlight/intel_backlight/brightness";
  char * file_path = "./txt";
//FILE *fptr = fopen(file_path, "w");
  FILE * file = open_filew(file_path);
  if (ENOENT == errno) printf("\nENOENTW\n");
  fprintf(file, "%d", errno);
  fclose(file);

  char * new_path = "./fake";
  FILE * fakeptr = open_filer(new_path);
  
  if (ENOENT == errno) printf("\nENOENTR\n");
  return 0;
}

FILE * open_filew(char * path){
  FILE * file_ptr = fopen(path, "w");
  return file_ptr;
}

FILE * open_filer(char * path){
  FILE * file_ptr = fopen(path, "r");
  return file_ptr;

}
