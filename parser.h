#ifndef PARSER_H
#define PARSER_H

#include "common.h"
#include "llist.h"
#include "implementations.h"

#define FOREACH_AST_TAG(T) \
    T(AST_LIST) \
    T(AST_NUM) \
    T(AST_EXPR) \
    T(AST_FN) \

typedef enum {
    FOREACH_AST_TAG(GENERATE_ENUM)
} ast_tag;

static const char* ast_tag_string[] = {
    FOREACH_AST_TAG(GENERATE_STRING)
};

typedef struct ast_t{
    ast_tag tag;
    char* contents;
    int children_num;
    // struct ast_t** children;
    llist* children;
    int position[2];
} ast;

typedef return_v* (*fn)(llist*);

static const fn function[5] = {
    (fn)add,
    (fn)sub,
    (fn)dvd,
    (fn)mul
};

void print_expr();

void print_fn_expr();

void print_atom_expr();

void free_expr(ast* expr);

void print_ast(ast* expr, int indent);

ast* parse(llist* lexemes);

#endif
