#include "common.h"
#include "llist.h"
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

ast* build_tree(ast_tag tag, char* contents)
{
    ast* tree = malloc(sizeof(ast));
    tree->tag = tag;
    tree->contents = contents;
    if (tag == ast_expr) {
	tree->children = llist_create(NULL);
    }
    return tree;
}

ast* parse(llist* lexemes)
{
    struct node* lexeme_list = *lexemes;
    // ignore first empty node
    lexeme_list = lexeme_list->next;

    ast* head = build_tree(ast_expr, NULL);
    ast* curr;
    llist* expr_stack = llist_create(head);

    while (lexeme_list) {
	struct node* last = llist_last(expr_stack);

	curr = (ast*)last->data;

	lexeme* lexeme = lexeme_list->data;
	ast* branch;

	switch (lexeme->type)
	{
	case LEX_INT:;
	    branch = build_tree(ast_num, lexeme->value);
	    llist_push(curr->children, branch);
	    break;
	case LEX_OPR:;
	    branch = build_tree(ast_fn, lexeme->value);
	    llist_push(curr->children, branch);
	    break;
	case LEX_OBR:;
	    branch = build_tree(ast_expr, NULL);
	    llist_push(curr->children, branch);
	    llist_push(expr_stack, branch);
	    break;
	case LEX_CBR:;
	    llist_pop(expr_stack);
	    break;
	case LEX_KEY:;
	    break;
	case LEX_IDT:;
	    break;
	case LEX_INV:;
	    break;
	default:
	    break;
	}

	lexeme_list = lexeme_list->next;
    }

    return head;
}

void print_ast(ast* ast, int indent)
{
    if (ast->tag == ast_expr) {
	printf("%*sexpr:>\n", indent, "");
	struct node* children = *ast->children;
	children = children->next;
	indent += 2;
	while (children) {
	    print_ast(children->data, indent);
	    children = children->next;
	}
    } else {
	printf("%*s%d:%s\n", indent, "", ast->tag, ast->contents);
    }
}

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
