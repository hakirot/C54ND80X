CFLAGS=-I -Wall -g -lncurses  -Wimplicit-function-declaration

proc_overwrite: proc_overwrite.c
	gcc proc_overwrite.c -o proc_overwrite
 
string_truths: string_truths.c
	gcc string_truths.c -o string_truths

errno: errno.c
	gcc errno.c -o errno

calc: option_calc.c
	gcc option_calc.c -o calc $(CFLAGS)

thing: thing.c
	gcc thing.c -o thing

mod: mod.c
	gcc mod.c -o mod

doop: doopstr.c
	gcc doopstr.c -o doopstr

main: main.c
	gcc main.c -o main
