# -*- Makefile -*-

prog: main.c
	gcc main.c -o prog -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g

prog2: scroll.c
	gcc scroll.c -o prog2 -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g

clean:
	rm *.o prog -f
