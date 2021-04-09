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

typedef struct {
    fn fn; // <- replace with searching existing data of functions
    llist* exprs;
} expr;

void free_expr(expr* expr);

expr* parse(llist* lexemes);

#endif
