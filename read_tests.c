#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "read.h"

void read_parses_int()
{
	struct s_expr *ast;
	ast = read("42");

	assert(ast != NULL);
	assert(is_atom(ast));
	assert(is_int(ast));
	assert(get_int(ast) == 42);
}

void read_parses_list_of_two_ints(void)
{
	struct s_expr *ast;
	ast = read("(42 54)");

	assert(ast != NULL);
	assert(!is_atom(ast));
}

int main(void) {
	read_parses_int();
	read_parses_list_of_two_ints();

	printf("read tests passed\n");
}
