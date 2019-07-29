#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "ast.h"

static void value_of_an_int_can_be_got(void)
{
	struct s_expr *ast = make_int_expr(42);

	assert(is_atom(ast));
	assert(is_int(ast));
	assert(get_int(ast) == 42);

	free_expr(ast);
}

static void head_and_tail_of_a_list_can_be_got(void)
{
	struct s_expr *head = make_int_expr(42);
	struct s_expr *tail = make_int_expr(54);
	struct s_expr *pair = make_pair_expr(head, tail);

	assert(!is_atom(pair));	
	assert(get_head(pair) == head);
	assert(get_tail(pair) == tail);

	free_expr(pair);
}

static void nil_is_nil(void)
{
	struct s_expr *expr = make_nil();
	assert(is_nil(expr));
	free_expr(expr);
}

static void can_append_to_a_list(void)
{
	struct s_expr *list = make_nil();
	append(list, make_int_expr(42));
	append(list, make_int_expr(54));
	append(list, make_int_expr(69));

	assert(get_int(get_head(list)) == 42);
	assert(get_int(get_head(get_tail(list))) == 54);
	assert(get_int(get_head(get_tail(get_tail(list)))) == 69);

	free_expr(list);
}

int main(void) {
	value_of_an_int_can_be_got();
	head_and_tail_of_a_list_can_be_got();
	nil_is_nil();
	can_append_to_a_list();

	printf("ast tests passed\n");
}
