#include "common.h"

typedef struct lnode {
    struct lnode *parent;
    struct lnode *child;
    void* data;
} llist;

llist* llist_new(void* data, size_t size);

llist* llist_tail(llist* list);

bool llist_is_empty(llist* list);

void llist_print(llist* list, void (*print)(llist*));

void llist_push(llist* list, void* data, size_t size);

void llist_pop(llist* list);
