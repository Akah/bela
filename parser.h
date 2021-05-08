#ifndef PARSER_H
#define PARSER_H

#include "common.h"
#include "llist.h"
#include "implementations.h"

//TODO: generate enum and function array from macro
typedef enum {
// arithmetic
    ADD,
    SUB,
    DIV,
    MUL,
    MOD,
    EXP,
// incremenation
    INC,
    DEC,
// binary
    BAND,
    BNOT,
    BXOR,
    BOR,
    BLS,
    BRS,
// relational
    EQL,
    NEQ,
    GRT,
    LST,
// logical
    AND,
    OR,
    NOT,
} operator;

typedef return_v* (*fn)(llist*);

static const fn function[5] = {
    (fn)add,
    (fn)sub,
    (fn)dvd,
    (fn)mul
};

typedef enum {
    ast_list,
    ast_num,
    ast_expr,
    ast_fn,
} ast_tag;

typedef struct ast_t{
    ast_tag tag;
    char* contents;
    int children_num;
    // struct ast_t** children;
    llist* children;
} ast;


void print_expr();

void print_fn_expr();

void print_atom_expr();

void free_expr(ast* expr);

void print_ast(ast* expr, int indent);

ast* parse(llist* lexemes);

#endif
