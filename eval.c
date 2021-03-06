#include "common.h"
#include "eval.h"

long eval_op(char* op, long x, long y)
{
    if (strcmp(op, "+") == 0) return x + y;
    if (strcmp(op, "-") == 0) return x - y;
    if (strcmp(op, "*") == 0) return x * y;
    if (strcmp(op, "/") == 0) return x / y;
    return 0;
}

long eval(ast* t)
{
    if (t->tag == AST_NUM) {
	return atoi(t->contents);
    }

    struct node* child_list = (*t->children)->next;

    ast* child_tree = child_list->data;

    char* op = child_tree->contents;

    long result = eval(child_list->next->data);

    child_list = child_list->next->next;;

    while (((ast*)child_list->data)->tag == AST_EXPR
	   || ((ast*)child_list->data)->tag  == AST_NUM) {

	result = eval_op(op, result, eval(child_list->data));

	if (child_list->next != NULL) {
	    child_list = child_list->next;
	} else {
	    break;
	}
    }

    return result;

}
