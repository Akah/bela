#include "common.h"
#include "llist.h"
#include "parser.h"
#include "lexer.h"
#include "implementations.h"

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
    if (tag == AST_EXPR) {
	tree->children = llist_create(NULL);
    }
    return tree;
}

ast* parse(llist* lexemes)
{
    struct node* lexeme_list = *lexemes;
    // ignore first empty node
    lexeme_list = lexeme_list->next;

    ast* head = build_tree(AST_EXPR, NULL);
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
	    branch = build_tree(AST_NUM, lexeme->value);
	    llist_push(curr->children, branch);
	    break;
	case LEX_OPR:;
	    branch = build_tree(AST_FN, lexeme->value);
	    llist_push(curr->children, branch);
	    break;
	case LEX_OBR:;
	    branch = build_tree(AST_EXPR, NULL);
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
    if (ast->tag == AST_EXPR) {
	printf("%*sEXPR:>\n", indent, "");
	struct node* children = *ast->children;
	children = children->next;
	indent += 2;
	while (children) {
	    print_ast(children->data, indent);
	    children = children->next;
	}
    } else {
	printf("%*s%s:%s\n", indent, "", ast_tag_string[ast->tag], ast->contents);
    }
}
