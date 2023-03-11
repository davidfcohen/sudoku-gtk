CC ?= gcc
PKGCONFIG = $(shell which pkg-config)
CFLAGS = $(shell $(PKGCONFIG) --cflags gtk+-3.0)
LIBS = $(shell $(PKGCONFIG) --libs gtk+-3.0)

SRC = main.c sudoku_app.c sudoku_app_win.c

OBJS = $(SRC:.c=.o)

all: sudoku_app

%.o: %.c
	$(CC) -c -o $(@F) $(CFLAGS) $<

sudoku_app: $(OBJS)
	$(CC) -o $(@F) $(OBJS) $(LIBS)

clean:
	rm -f $(OBJS)
	rm -f sudoku_app