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
    fn fn;
    llist* args;
} fn_expr;

typedef enum {
    FUNC,
    LIST,
    ATOM
} expr_t;

typedef struct{
    expr_t type;
    union {
	fn_expr* fn_expr;
	llist* list;
	void* atom;
    };
} expr;

void free_expr(expr* expr);

void print_expr(expr* expr);

expr* parse(llist* lexemes);

#endif
