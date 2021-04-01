#include "common.h"
#include "llist.h"

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
} lexeme_t;

typedef struct {
    lexeme_t type;
    char* value;
} lexeme;

char peek(char* string);

void print_lexeme(void* lexeme);

char peek(char* string);

char consume(char** string);

bool is_digit(char c);

llist* scan(char* string);

#endif