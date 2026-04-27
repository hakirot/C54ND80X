CFLAGS=-I -Wall -g -lncurses  -Wimplicit-function-declaration
BIN=string_sizes ueberzug calc proc_overwrite string_truths errno thing ncurses_color_test

all: $(BIN)

ncurses_color_test: ncurses_color_test.c
	gcc ncurses_color_test.c -o ncurses_color_test $(CFLAGS) -lncursesw -DNCURSES_WIDECHAR=1

string_sizes: string_sizes.c
	gcc string_sizes.c -o string_sizes $(CFLAGS)

ueberzug: ueberzug.c
	gcc ueberzug.c -o ueberzug $(CFLAGS)

calc: option_calc.c
	gcc option_calc.c -o calc $(CFLAGS)

proc_overwrite: proc_overwrite.c
	gcc proc_overwrite.c -o proc_overwrite
 
string_truths: string_truths.c
	gcc string_truths.c -o string_truths

errno: errno.c
	gcc errno.c -o errno

thing: thing.c
	gcc thing.c -o thing

clean:
	rm $(BIN)
