#include "read.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

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

	assert(get_int(get_head(ast)) == 42);
	assert(get_int(get_head(get_tail(ast))) == 54);
}

void read_parses_list_of_lists(void)
{
	struct s_expr *ast;
	ast = read("(69 (42 54) 0)");

	assert(ast != NULL);
	assert(!is_atom(ast));

	assert(get_int(get_head(ast)) == 69);
	assert(get_int(get_head(get_head(get_tail(ast)))) == 42);
	assert(get_int(get_head(get_tail(get_head(get_tail(ast))))) == 54);
	assert(get_int(get_head(get_tail(get_tail(ast)))) == 0);
}

int main(void)
{
	read_parses_int();
	read_parses_list_of_two_ints();
	read_parses_list_of_lists();

	printf("read tests passed\n");
}
