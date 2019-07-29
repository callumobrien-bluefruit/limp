#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "read.h"

static struct s_expr *parse_s_expr(const char **s);
static struct s_expr *parse_atom(const char **s);
static int parse_int(const char **s);

struct s_expr *read(const char *line)
{
	return parse_s_expr(&line);
}

static struct s_expr *parse_s_expr(const char **s)
{
	while (isspace(**s))
		++*s;

	if (**s == '(') {
		++*s;
		struct s_expr *expr = make_nil();
		while (**s != ')') {
			struct s_expr *sub_expr = parse_s_expr(s);
			append(expr, sub_expr);
		}
		return expr;
	} else {
		return parse_atom(s);
	}
}

static struct s_expr *parse_atom(const char **s)
{
	if (isdigit(**s)) {
		int value = parse_int(s);
		return make_int_expr(value);
	} else if (strncmp(*s, "nil", strlen("nil")) == 0) {
		*s += strlen("nil");
		return make_nil();
	}

	return NULL;
}

static int parse_int(const char **s)
{
	int value = 0;
	while (isdigit(**s)) {
		value *= 10;
		value += **s - '0';
		++*s;
	}

	return value;
}
