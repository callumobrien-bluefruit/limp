#include "ast.h"

#include <stdlib.h>

struct s_expr *make_int_expr(int value)
{
	struct s_expr *int_expr = malloc(sizeof(struct s_expr));
	int_expr->is_pair = false;
	int_expr->value.atom.type = ATOM_TYPE_INT;
	int_expr->value.atom.value = value;
	return int_expr;
}

struct s_expr *make_pair_expr(struct s_expr *head, struct s_expr *tail)
{
	struct s_expr *pair_expr = malloc(sizeof(struct s_expr));
	pair_expr->is_pair = true;
	pair_expr->value.pair.head = head;
	pair_expr->value.pair.tail = tail;
	return pair_expr;
}

struct s_expr *make_nil(void)
{
	struct s_expr *nil_expr = malloc(sizeof(struct s_expr));
	nil_expr->is_pair = false;
	nil_expr->value.atom.type = ATOM_TYPE_NIL;
	return nil_expr;
}

void free_expr(struct s_expr *ast)
{
	if (!is_atom(ast)) {
		free_expr(get_head(ast));
		free_expr(get_tail(ast));
	}
	free(ast);
}

bool is_atom(const struct s_expr *ast)
{
	return !ast->is_pair;
}

bool is_int(const struct s_expr *ast)
{
	return ast->value.atom.type == ATOM_TYPE_INT;
}

bool is_nil(const struct s_expr *ast)
{
	return ast->value.atom.type == ATOM_TYPE_NIL;
}

int get_int(const struct s_expr *ast)
{
	return ast->value.atom.value;
}

struct s_expr *get_head(const struct s_expr *ast)
{
	if (is_atom(ast))
		return NULL;
	return ast->value.pair.head;
}

struct s_expr *get_tail(const struct s_expr *ast)
{
	if (is_atom(ast))
		return NULL;
	return ast->value.pair.tail;
}

void append(struct s_expr *list, struct s_expr *elem)
{
	while (!is_atom(list))
		list = get_tail(list);

	list->is_pair = true;
	list->value.pair.head = elem;
	list->value.pair.tail = make_nil();
}
