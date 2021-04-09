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
} return_v;

//OPTIMISATIONS:
//  replace with inline?
//  replace with bitwise operations

return_v* calc(char op, llist* args);

return_v* add(llist* args);

return_v* sub(llist* args);

return_v* dvd(llist* args);

return_v* mul(llist* args);


#endif
