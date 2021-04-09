#ifndef PARSER_H
#define PARSER_H

#include "common.h"
#include "llist.h"
#include "implementations.h"

typedef enum {
    ADD,
    SUB,
    DIV,
    MUL,
} operator;

typedef return_v* (*fn)(llist*);

static const fn function[5] = {
    (fn)add,
};

typedef struct {
    fn fn; // <- replace with searching existing data of functions
    llist* exprs;
} expr;

void free_expr(expr* expr);

expr* parse(llist* lexemes);

#endif
