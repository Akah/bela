#include "common.h"
#include "llist.h"

#ifndef LEXER_H
#define LEXER_H

#define FOREACH_LEXEME(T) \
    T(LEX_INV) \
    T(LEX_KEY) \
    T(LEX_IDT) \
    T(LEX_OPR) \
    T(LEX_INT) \
    T(LEX_OBR) \
    T(LEX_CBR)

#define GENERATE_ENUM(ENUM) ENUM ,
#define GENERATE_STRING(STRING) #STRING ,

typedef enum {
    FOREACH_LEXEME(GENERATE_ENUM)
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

char consume(char** string);

bool is_digit(char c);

llist* scan(char* string);

static const char* lexeme_t_string[] = {
    FOREACH_LEXEME(GENERATE_STRING)
};

#endif
