prog:main.o  enigme.o
	gcc main.o   enigme.o -o prog -lSDL -lSDL_image -lSDL_ttf -lm
main.o:main.c
	gcc -c main.c  -g

enigme.o:enigme.c
	gcc -c enigme.c  -g

