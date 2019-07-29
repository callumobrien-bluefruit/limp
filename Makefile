SRC = ast.c eval.c print.c read.c repl.c
OBJ = $(SRC:.c=.o)

CFLAGS += -Wall -Wextra -std=c99 -pedantic

.DEFAULT: repl
.PHONY: clean

eval.o print.o read.o repl.o: ast.o
repl.o: eval.o print.o read.o

repl: $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJ)

%_tests: %_tests.o %.o ast.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

clean:
	rm -f repl *_tests *.o