#ifndef _AST_H_
#define _AST_H_

#include <stdbool.h>

enum atom_type { ATOM_TYPE_INT, ATOM_TYPE_NIL };

struct atom {
	enum atom_type type;
	int value;
};

struct pair {
	struct s_expr *head;
	struct s_expr *tail;
};

struct s_expr {
	bool is_pair;
	union {
		struct pair pair;
		struct atom atom;
	} value;
};

struct s_expr *make_int_expr(int value);
struct s_expr *make_pair_expr(struct s_expr *head, struct s_expr *tail);
struct s_expr *make_nil(void);
void free_expr(struct s_expr *ast);

bool is_atom(const struct s_expr *ast);
bool is_int(const struct s_expr *ast);
bool is_nil(const struct s_expr *ast);

int get_int(const struct s_expr *ast);
struct s_expr *get_head(const struct s_expr *ast);
struct s_expr *get_tail(const struct s_expr *ast);
void append(struct s_expr *list, struct s_expr *elem);

#endif
