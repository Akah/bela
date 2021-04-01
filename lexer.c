#include <assert.h>
#include "lexer.h"

/* typedef enum { */
/*     0 LEX_KEY, // KEYWORD */
/*     1 LEX_IDT, // IDENTIFIER */
/*     2 LEX_OPR, // OPERATOR */
/*     3 LEX_INT, // INTEGER */
/*     4 LEX_OBR, // OPEN BRACKET */
/*     5 LEX_CBR, // CLOSE BRACKET */
/* } lexeme_t; */

/* typedef struct { */
/*     lexeme_t type; */
/*     char* value; */
/* } lexeme; */

/* typedef struct node{ */
/*     lexeme* lexeme; */
/*     struct node* next; */
/* } lex_stack; */

// TODO: move stack code into stack.c/h
lex_stack* stack_new(lexeme* lexeme)
{
    lex_stack* node = malloc(sizeof(lex_stack));
    node->lexeme = lexeme;
    node->next = NULL;
    return node;
}

void stack_push(lex_stack** stack, lexeme* lexeme)
{
    lex_stack* node = stack_new(lexeme);

    if (!stack_is_empty(*stack)) {
	node->next = *stack;
    }
    *stack = node;
}

void stack_push_as_lexeme(lex_stack** stack, lexeme_t type, char* value)
{
    lexeme* lexeme = malloc(sizeof(lexeme));
    lexeme->type  = type;
    lexeme->value = malloc(sizeof(char) * strlen(value));
    strcpy(lexeme->value, value);
    stack_push(stack, lexeme);
}

bool stack_is_empty(lex_stack* stack)
{
    return !stack;
}

void print_lexeme(lexeme* lexeme)
{
    if (lexeme)
	printf("(%d, %s)\n", lexeme->type, lexeme->value);
}

void stack_print(lex_stack* stack)
{
    if (stack_is_empty(stack))
	return;

    print_lexeme(stack->lexeme);

    stack_print(stack->next);
}

lexeme* stack_pop(lex_stack** stack)
{
    if (stack_is_empty(*stack)){
	return NULL;
    }
    lex_stack* temp = *stack;
    *stack = (*stack)->next;
    lexeme* popped = temp->lexeme;
    free(temp);
    return popped;
}

lexeme* stack_peek(lex_stack* stack)
{
    if (stack_is_empty(stack)) {
	return NULL;
    }
    return stack->lexeme;
}

char peek(char* string)
{
    return *string;
}

char consume(char** string)
{
    return *(*string)++;
}

bool is_digit(char c)
{
    return c >= '0' && c <= '9';
}

bool is_char(char c)
{
    return (c >= 'A' && c <= 'Z')
	|| (c >= 'a' && c >= 'z');
}

bool is_operator(char c)
{
    return c == '+'
	|| c == '-'
	|| c == '/'
	|| c == '*';
}

char* as_string(char c){
    return (char[2]){c, '\0'};
}

lexeme* new_lexeme(lexeme_t type, char* value)
{
    lexeme* lexeme = malloc(sizeof(lexeme));
    lexeme->type  = type;
    lexeme->value = malloc(sizeof(char) * strlen(value));
    strcpy(lexeme->value, value);

    return lexeme;
}

void free_lexeme(lexeme* lexeme)
{
    free(lexeme->value);
    free(lexeme);
}

void print_as_lexeme(llist* list)
{
    lexeme* lexeme = list->data; // cast to lexeme*
    print_lexeme(lexeme);
}

void scan(char* string)
{
    char current_value[64] = "";
    lex_stack* stack = stack_new(NULL); // TODO: pass stack into function otherwise it creates a memory leak
    /* llist* list = llist_new(NULL, sizeof(void*)); */

    while (peek(string)) {
	if (peek(string) == ' ') {
	    consume(&string);
	    continue;
	}
	if (peek(string) == '(') {
	    lexeme* lexeme = new_lexeme(LEX_OBR, as_string(consume(&string)));
	    stack_push(&stack, lexeme);
	    /* llist_push(list, lexeme, sizeof(void*)); */
	    continue;
	}
	if (peek(string) == ')') {
	    lexeme* lexeme = new_lexeme(LEX_CBR, as_string(consume(&string)));
	    stack_push(&stack, lexeme);
	    /* llist_push(list, lexeme, sizeof(void*)); */
	    continue;
	}
	if (is_digit(peek(string))) {
	    while(is_digit(peek(string))) {
		strcat(current_value, as_string(consume(&string)));
	    }
	    lexeme* lexeme = new_lexeme(LEX_INT, current_value);
	    print_lexeme(lexeme);
	    stack_push(&stack, lexeme);
	    /* llist_push(list, lexeme, sizeof(void*)); // <- this push is broken; */
	    puts("test");
	    current_value[0] = '\0';
	    continue;
	}
	if (is_operator(peek(string))) {
	    lexeme* lexeme = new_lexeme(LEX_INT, as_string(consume(&string)));
	    stack_push(&stack, lexeme);
	    /* llist_push(list, lexeme, sizeof(void*)); */
	    continue;
	}

	lexeme* lexeme = new_lexeme(LEX_INV, as_string(consume(&string)));
	    stack_push(&stack, lexeme);
	/* llist_push(list, lexeme, sizeof(void*)); */
    }
    stack_print(stack);

    /* llist_print(list, print_as_lexeme); */
}
