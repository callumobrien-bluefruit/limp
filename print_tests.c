#include "ast.h"
#include "print.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define ASSERT_STREQ(s, t, n)                                  \
	do {                                                       \
		if (strncmp(s, t, n) != 0) {                           \
			fprintf(stderr, "FAIL: \"%s\" != \"%s\"\n", s, t); \
			assert(false);                                     \
		}                                                      \
	} while (false)

#define BUF_SIZE 100

static void an_integer_can_be_printed(void)
{
	char buf[BUF_SIZE];
	struct s_expr *s;

	s = make_int_expr(42);
	print(s, buf, BUF_SIZE);
	ASSERT_STREQ(buf, "42", BUF_SIZE);

	s = make_int_expr(69);
	print(s, buf, BUF_SIZE);
	ASSERT_STREQ(buf, "69", BUF_SIZE);
}

static void a_list_can_be_printed(void)
{
	char buf[BUF_SIZE];
	struct s_expr *s;

	s = make_nil();
	append(s, make_int_expr(42));
	append(s, make_int_expr(69));

	print(s, buf, BUF_SIZE);
	ASSERT_STREQ(buf, "(42 69)", BUF_SIZE);
}

static void nested_lists_can_be_printed(void)
{
	char buf[BUF_SIZE];
	struct s_expr *s, *t;

	s = make_nil();
	append(s, make_int_expr(42));
	append(s, make_int_expr(69));

	t = make_nil();
	append(t, make_int_expr(54));
	append(t, s);
	append(t, make_int_expr(1337));

	print(t, buf, BUF_SIZE);
	ASSERT_STREQ(buf, "(54 (42 69) 1337)", BUF_SIZE);
}

int main(void)
{
	an_integer_can_be_printed();
	a_list_can_be_printed();
	nested_lists_can_be_printed();

	printf("print_tests passed\n");
}
