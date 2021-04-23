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
    switch(*operator) {
    case '+':
	return 0;
    case '-':
	return 1;
    case '/':
	return 2;
    case '*':
	return 3;
    }
    return -1;
}

/* void free_expr(expr* expr) */
/* { */
/*     llist_free(expr->exprs); */
/*     free(expr); */
/* } */

expr* new_expr(expr_t type, void* data)
{
    expr* expr = malloc(sizeof(expr));
    if (type == LIST) {
	expr->list = llist_create(NULL);
    }

    if (type == LIST) {
	expr->fn_expr->args = llist_create(NULL);
    }

    if (type == ATOM) {
	expr->atom = data;
    }
    return expr;
}

expr* parse(llist* lexemes)
{
    llist_print(lexemes, print_lexeme);
    return NULL;
}

/* void print_expr(expr* expr) */
/* { */
/*     int indent = 0; */
/*     //printf("%*s%s", expr->fn) // TODO: expr->fn as  struct containing function pointer and function name */
/*     printf("%*sexpr:>\n", indent, ""); */
/*     indent += 4; */

/*     llist* cur_expr = expr->exprs; */
/*     struct node* a = *cur_expr; */




/*     while (cur_expr) { */
/* 	printf("%*stype:%s:%s", indent, "", b->type); */
/*     } */

/* } */

/* expr* parse(llist* lexemes) */
/* { */
/*     expr *expr, *cur_expr, *sub_expr; */
/*     expr = new_expr(); */
/*     cur_expr = expr; */

/*     llist* expr_ptrs = llist_create(expr); */

/*     struct node* curr_lexeme_p = *lexemes; */

/*     while (curr_lexeme_p != NULL) { */
/* 	// first pointer position has null data/type but has a child */
/* 	// TODO: decided whether to delete or ignore first pointer in list. */
/* 	lexeme* lexeme = curr_lexeme_p->data; */
/* 	if (lexeme) { */
/* 	    switch (lexeme->type) { */
/* 	    case LEX_INV: */
/* 		printf("invalid input: %s\n", lexeme->value); */
/* 		break; */
/* 	    case LEX_OPR:; */
/* 		expr->fn = function[operator_from_string(lexeme->value)]; */
/* 		break; */
/* 	    case LEX_INT:; // ; is actually required here */
/* 		llist_push(expr->exprs, lexeme->value); */
/* 		break; */
/* 	    case LEX_OBR: */
/* 		sub_expr = new_expr(); */
/* 		llist_push(expr_ptrs, sub_expr); */
/* 		cur_expr = sub_expr; */
/* 		break; */
/* 	    case LEX_CBR: */
/* 		cur_expr = llist_pop(expr_ptrs); */
/* 		break; */
/* 	    case LEX_KEY: */
/* 	    case LEX_IDT: */
/* 	    default: */
/* 		printf("no implementation for lexeme type: %s\n", */
/* 		       lexeme_t_string[lexeme->type]); */
/* 	    } */
/* 	} */
/* 	curr_lexeme_p = curr_lexeme_p->next; */
/*     } */

/*     return expr; */
/* } */
