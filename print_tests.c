#include "ast.h"
#include "print.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

static void an_integer_can_be_printed(void)
{
	char buf[100];
	struct s_expr *s;

	s = make_int_expr(42);
	print(s, buf, 100);
	assert(strcmp(buf, "42") == 0);

	s = make_int_expr(69);
	print(s, buf, 100);
	assert(strcmp(buf, "69") == 0);
}

int main(void)
{
	an_integer_can_be_printed();

	printf("print_tests passed\n");
}
