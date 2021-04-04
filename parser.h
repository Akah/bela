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

typedef void (*fn)();

static const fn function[5] = {
    (fn)add,
    (fn)sub,
    (fn)div,
    (fn)mul
};

typedef struct {
    fn fn; // <- replace with searching existing data of functions
    llist* exprs;
} expr;


expr* parse(llist* lexemes);

#endif
