CC=gcc
CFLAGS=-Wall
#LIBS=-lcurses

OBJ=read_file_in_color.c

all: color

color: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f color
