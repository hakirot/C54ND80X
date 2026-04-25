#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>

static const char * im[] = {
  "╔══════╗    ╔════╗    ╔═════╗     ╔════╗    ",
  "║ ╔════╝   ╔╝╔══╗╚╗   ║ ╔══╗╚╗   ╔╝╔══╗╚╗   ",
  "║ ╚════╗   ║ ╚══╝ ║   ║ ╚══╝╔╝   ║ ╚══╝ ║   ",
  "╚════╗ ║   ║ ╔══╗ ║   ║ ╔══╗╚╗   ║ ╔══╗ ║   ",
  "╔════╝ ║╔═╗║ ║  ║ ║╔═╗║ ║  ║ ║╔═╗║ ║  ║ ║╔═╗",
  "╚══════╝╚═╝╚═╝  ╚═╝╚═╝╚═╝  ╚═╝╚═╝╚═╝  ╚═╝╚═╝",
};
/* Set empty if desired */
//static const char * im[] = {NULL};

static const char hd[] = "herro";
//static const char hd[] = {'\0'};

int IM_SET;
int HD_SET;

const char * bg[] = {
  "                     -`                     ",
  "                    .o+`                    ",
  "                   `ooo/                    ",
  "                  `+oooo:                   ",
  "                 `+oooooo:                  ",
  "                 -+oooooo+:                 ",
  "               `/:-:++oooo+:                ",
  "              `/++++/+++++++:               ",
  "             `/++++++++++++++:              ",
  "            `/+++ooooooooooooo/`            ",
  "           ./ooosssso++osssssso+`           ",
  "          .oossssso-````/ossssss+`          ",
  "         -osssssso.      :ssssssso.         ",
  "        :osssssss/        osssso+++.        ",
  "       /ossssssss/        +ssssooo/-        ",
  "     `/ossssso+/:-        -:/+osssso+-      ",
  "    `+sso+:-`                 `.-/+oso:     ",
  "   `++:.                           `-/+/    ",
  "   .`                                 `/    ",
};

const char * fg[] = {
  "███████╗    █████╗    ██████╗     █████╗    ",
  "██╔════╝ooo██╔══██╗   ██╔══██╗   ██╔══██╗   ",
  "███████╗   ███████║   ██████╔╝   ███████║   ",
  "╚════██║   ██╔══██║   ██╔══██╗   ██╔══██║   ",
  "███████║██╗██║  ██║██╗██║  ██║██╗██║  ██║██╗",
  "╚══════╝╚═╝╚═╝  ╚═╝╚═╝╚═╝  ╚═╝╚═╝╚═╝  ╚═╝╚═╝",
};

int main(int argc, char* argv[]) {
  setlocale(LC_ALL, "");

  printf("WIDTHS\n");
  int BG_GLYPH_WIDTH = mbstowcs(NULL, bg[0], 0);
  printf("BG length: %d\n", BG_GLYPH_WIDTH);

  int FG_GLYPH_WIDTH = mbstowcs(NULL, fg[0], 0);
  printf("FG length: %d\n\n", FG_GLYPH_WIDTH);

  printf("HEIGHTS\n");
  int BG_GLYPH_LENGTH = sizeof(bg)/sizeof(bg[0]);
  printf("BG height: %d\n", BG_GLYPH_LENGTH);

  int FG_GLYPH_LENGTH = sizeof(fg)/sizeof(fg[0]);
  printf("FG height: %d\n", FG_GLYPH_LENGTH);

//if(im[0] != NULL) IM_SET = true;
  im[0] == NULL ?  printf("true\n") : printf("false\n");
  hd[0] != 0 ? printf("hd true\n") : printf("hd false\n");

  return 0;
}
