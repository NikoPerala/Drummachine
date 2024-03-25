CC=gcc
IDIR=./include

CFLAGS=-Wall -Wextra -I$(IDIR) -g -DDEBUG
FILES=./src/main.c ./src/drummachine.c

desktop:
	$(CC) $(FILES) ./src/display_desktop.c $(CFLAGS) -DDESKTOP -lraylib -o drummachine 
