#ifndef IMPLEMENTATIONS_H
#define IMPLEMENTATIONS_H

#include "llist.h"

typedef enum {
    CHAR,
    SHORT,
    INT,
    FLOAT,
    STRING,
} return_t;

typedef struct {
    return_t type;
    void* value;
} ret_val;

ret_val* add(llist* args);

uint32_t sub(llist* args);

uint32_t dvd(llist* args);

uint32_t mul(llist* args);

#endif
