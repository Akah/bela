#include "common.h"
#include "parser.h"
#include "lexer.h"
#include "implementations.h"

/**
 * example:
 *  (+ 1 (- 3 2))
 * lexed:
 *  (5, ()
 *  (4, +)
 *  (4, 1)
 *  (5, ()
 *  (4, -)
 *  (4, 3)
 *  (4, 2)
 *  (6, ))
 *  (6, ))
 *
 * returns:
 * expr:>
 *   fn:operator: +
 *   atom:integer:  1
 *   expr:>
 *     fn:operator: -
 *     atom:integer: 3
 *     atom:integer: 4
 */

int operator_from_string(char* operator)
{
    if (strcmp(operator, "+") == 0) return 0;
    if (strcmp(operator, "-") == 0) return 1;
    if (strcmp(operator, "/") == 0) return 2;
    if (strcmp(operator, "*") == 0) return 3;
    return -1;
}

void print_int(void* pointer)
{
    if (pointer == NULL)
	return;
    char* num = pointer;
    printf("%d\n", atoi(num));
}

void free_expr(expr* expr)
{
    llist_free(expr->exprs);
    free(expr);
}

expr* parse(llist* lexemes)
{
    expr* expr = malloc(sizeof(expr));

    llist* exprs = llist_create(NULL);
    expr->exprs = exprs;

    struct node* curr_lexeme_p = *lexemes;

    while (curr_lexeme_p != NULL) {
	// first pointer position has null data/type but has a child
	// TODO: decided whether to delete or ignore first pointer in list.
	lexeme* lexeme = curr_lexeme_p->data;
	if (lexeme) {
	    switch (lexeme->type) {
	    case LEX_INV:
		printf("invalid input: %s", lexeme->value);
		break;
	    case LEX_OPR:
		expr->fn = function[operator_from_string(lexeme->value)];
		break;
	    case LEX_INT:; // ; is actually required here
		llist_push(expr->exprs, lexeme->value);
		break;
	    case LEX_OBR:
	    case LEX_CBR:
	    case LEX_KEY:
	    case LEX_IDT:
	    default:
		printf("no implementation for lexeme type: %s\n",
		       lexeme_t_string[lexeme->type]);
	    }
	}
	curr_lexeme_p = curr_lexeme_p->next;
    }

    return expr;
}
