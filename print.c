#include "print.h"

#include <stdio.h>

static int print_list_inner(const struct s_expr *expr, char *buf, int buf_len);

int print(const struct s_expr *expr, char *buf, int buf_len)
{
	if (is_int(expr)) {
		int value = get_int(expr);
		return snprintf(buf, buf_len, "%d", value);
	} else {
		int pos = 0;
		if (buf_len - pos < 1)
			return -1;
		buf[pos++] = '(';

		int n = print_list_inner(expr, buf + pos, buf_len - pos);
		if (n < 0)
			return -1;
		pos += n;

		if (buf_len - pos < 2)
			return -1;
		buf[pos++] = ')';

		buf[pos] = '\0';
		return pos;
	}
}

static int print_list_inner(const struct s_expr *expr, char *buf, int buf_len)
{
	struct s_expr *head, *tail;
	int n, pos = 0;

	if (is_nil(expr))
		return 0;

	head = get_head(expr);
	n = print(head, buf, buf_len);
	if (n < 0)
		return -1;
	pos += n;

	tail = get_tail(expr);
	if (!is_nil(tail)) {
		buf[pos++] = ' ';
		n = print_list_inner(tail, buf + pos, buf_len - pos);
		if (n < 0)
			return -1;
		pos += n;
	}

	buf[pos] = '\0';
	return pos;
}
