CC=gcc -g -Wall -Wextra
CFILES_ONE=$(wildcard src/*/*.c)
CFILES_TWO=$(wildcard src/*/*/*.c)
CFILES_THREE=$(wildcard src/*/*/*/*.c)
HFILES_ONE=$(wildcard src/*/include/*.h)
HFILES_TWO=$(wildcard src/*/*/include/*.h)
HFILES_THREE=$(wildcard src/*/*/*/include/*.h)
OBJFILES_ONE=$(CFILES_ONE:.c=.o)
OBJFILES_TWO=$(CFILES_TWO:.c=.o)
OBJFILES_THREE=$(CFILES_THREE:.c=.o)
OBJPATH=src/objects/
EXEFILE=bin/main

all:$(OBJFILES_ONE) $(OBJFILES_TWO) $(OBJFILES_THREE)
	$(CC) src/main.c $(OBJFILES_ONE) $(OBJFILES_TWO) $(OBJFILES_THREE) -o $(EXEFILE) -lm

%.o: %.c $(HFILES_ONE)%.h
	TWO
	$(CC) -c $(CFILES_ONE) $< -o $@ -lm

TWO: %.c $(HFILES_TWO)%.h
	THREE
	$(CC) -c $(CFILES_TWO) $< -o $@ -lm

THREE: %.c $(HFILES_THREE)%.h
	$(CC) -c $(CFILES_THREE) $< -o $@ -lm

vim:
	nvim $(CFILES_ONE) $(CFILES_TWO) $(CFILES_THREE)

run:
	$(EXEFILE)

debug:
	gdb -q $(EXEFILE)

memcheck:
	valgrind $(EXEFILE) --leak-check=full --read-var-info

plant:
	plantuml documentation/uml_figure.txt

git-update:
	git add Makefile README.md src/ documentation/
	git commit -m "update commit"
	git push origin main

clean:
	rm $(OBJFILES_ONE) $(OBJFILES_TWO) $(OBJFILES_THREE)
