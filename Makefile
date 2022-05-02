CC=gcc -g -Wall
C_FILES=$(wildcard src/*/*.c)
H_FILES=$(wildcard src/*/include/*.h)
OBJ_FILES=$(C_FILES:.c=.o)
OBJ_PATH=src/objects/
EXE_FILE=bin/main

all:$(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(EXE_FILE) -lm

%.o: %.c $(H_FILES)%.h
	$(CC) -c $(C_FILES) $< -o $@ -lm

vim:
	nvim $(C_FILES) 

vimh:
	nvim $(H_FILES) 

run:
	$(EXEFILE)

debug:
	gdb -q $(EXEFILE)

memcheck:
	valgrind $(EXEFILE) --leak-check=full --read-var-info

git-update:
	git add Makefile README.md documentation/
	git commit -m "update commit"
	git push origin main

clean:
	rm $(OBJ_FILES)
