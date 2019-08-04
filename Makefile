SRC = ast.c eval.c print.c read.c repl.c
OBJ = $(SRC:.c=.o)

CFLAGS += -Wall -Wextra -std=c99 -pedantic

.DEFAULT: repl
.PHONY: clean format lint

eval.o print.o read.o repl.o: ast.o
repl.o: eval.o print.o read.o

repl: $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJ)

%_tests: %_tests.o %.o ast.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

clean:
	rm -f repl *_tests *.o

format:
	for f in $(SRC); do clang-format -i "$$f"; done

lint:
	clang-tidy $(SRC) -- $(CFLAGS)
