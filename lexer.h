#include "common.h"
#include "llist.h"

#ifndef LEXER_H
#define LEXER_H

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

char peek(char* string);

void print_lexeme(void* lexeme);

char peek(char* string);;

char peek(char* string);

void print_lexeme(void* pointer);

char peek(char* string);

char consume(char** string);

bool is_digit(char c);

llist* scan(char* string);

#endif
