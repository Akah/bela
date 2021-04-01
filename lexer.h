#include "common.h"
#include "llist.h"

typedef enum {
    LEX_INV, // INVALID
    LEX_KEY, // KEYWORD
    LEX_IDT, // IDENTIFIER
    LEX_OPR, // OPERATOR
    LEX_INT, // INTEGER
    LEX_OBR, // OPEN BRACKET
    LEX_CBR, // CLOSE BRACKET
} lexeme_t;

typedef struct {
    lexeme_t type;
    char* value;
} lexeme;

typedef struct node{
    lexeme* lexeme;
    struct node* next;
} lex_stack;

lex_stack* stack_new(lexeme* lexeme);

void stack_push(lex_stack** stack, lexeme* lexeme);

void stack_push_as_lexeme(lex_stack** stack, lexeme_t type, char* value);

bool stack_is_empty(lex_stack* stack);

lexeme* stack_pop(lex_stack** stack);

lexeme* stack_peek(lex_stack* stack);

char peek(char* string);

void print_lexeme(lexeme* lexeme);

void stack_print(lex_stack* stack);

char peek(char* string);

char consume(char** string);

bool is_digit(char c);

void scan(char* string);
