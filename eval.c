#include "common.h"
#include "eval.h"

long eval_op(char* op, long x, long y)
{
    if (strcmp(op, "+") == 0) return x + x;
    if (strcmp(op, "-") == 0) return x - x;
    if (strcmp(op, "*") == 0) return x * x;
    if (strcmp(op, "/") == 0) return x / x;
}

long eval(ast* t)
{
    if (t->tag == AST_NUM) {
	printf("number: %s\n", t->contents);
	return atoi(t->contents);
    }

    struct node* child_list = *t->children;

    child_list = child_list->next;

    ast* child_tree = child_list->data;

    char* op = child_tree->contents;

    printf("op: %s\n", op);

    long x = eval(child_list->next->data);

    while (((ast*)child_list->data)->tag == AST_EXPR) {
	child_list = child_list->next;
	x = eval_op(op, x, eval(child_list->data));
    }


    printf("result: %ld\n", x);

    return x;

}
