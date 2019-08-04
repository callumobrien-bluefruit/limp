#include "eval.h"
#include "print.h"
#include "read.h"

#include <stdio.h>

#define MAX_LINE_LENGTH 128

static bool get_line(char *line)
{
	int c, pos = 0;

	while ((c = getchar()) != '\n') {
		if (c == EOF)
			return false;

		line[pos++] = (char)c;
	}

	line[pos] = '\0';
	return true;
}

int main(void)
{
	char line_buffer[MAX_LINE_LENGTH];
	struct s_expr *in_expr, *out_expr;

	while (get_line(line_buffer)) {
		in_expr = read(line_buffer);
		out_expr = eval(in_expr);
		print(out_expr, line_buffer, MAX_LINE_LENGTH);
		printf("%s\n", line_buffer);
	}

	return 0;
}
