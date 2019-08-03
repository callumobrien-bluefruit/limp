#include <stdio.h>

#include "print.h"

void print(const struct s_expr *expr, char *buf, int buf_len)
{
	int value = get_int(expr);
	snprintf(buf, buf_len, "%d", value);
}
