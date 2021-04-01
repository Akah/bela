#include "common.h"
#include "llist.h"

<<<<<<< HEAD
#ifndef LEXER_H
#define LEXER_H

typedef enum {
    LEX_INV, // 0 INVALID
    LEX_KEY, // 1 KEYWORD
    LEX_IDT, // 2 IDENTIFIER
    LEX_OPR, // 3 OPERATOR
    LEX_INT, // 4 INTEGER
    LEX_OBR, // 5 OPEN BRACKET
    LEX_CBR, // 6 CLOSE BRACKET
=======
typedef enum {
    LEX_INV, // INVALID
    LEX_KEY, // KEYWORD
    LEX_IDT, // IDENTIFIER
    LEX_OPR, // OPERATOR
    LEX_INT, // INTEGER
    LEX_OBR, // OPEN BRACKET
    LEX_CBR, // CLOSE BRACKET
>>>>>>> added lexer
} lexeme_t;

typedef struct {
    lexeme_t type;
    char* value;
} lexeme;

<<<<<<< HEAD
char peek(char* string);

void print_lexeme(void* lexeme);
=======
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
>>>>>>> added lexer

char peek(char* string);

char consume(char** string);

bool is_digit(char c);

<<<<<<< HEAD
llist* scan(char* string);

#endif
=======
void scan(char* string);
>>>>>>> added lexer
