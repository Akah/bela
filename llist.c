#include "llist.h"

llist* llist_new(void* data, size_t size)
{
    llist* list = malloc(sizeof(llist));
    list->data = malloc(sizeof(size));
    list->data = data;
    return list;
}

bool llist_is_empty(llist* list)
{
    return list == NULL;
}

void llist_print(llist* list, void (*print)(llist*))
{
    (*print)(list);

    if (llist_is_empty(list)) {
	printf("list is empty\n");
    }

    if (list->child == NULL) {
	return;
    }

    return llist_print(list->child, (*print));
}

llist* llist_tail(llist* list)
{
    if (list->child == NULL) {
	return list;
    }
    return llist_tail(list->child);
}

void llist_push(llist* list, void* data, size_t size)
{
    /* llist* current = list; */
    /* while(current->child != NULL) { */
    /* 	current = current->child; */
    /* } */

    /* llist* new = llist_new(data, size); */
    /* current->child = new; */
    /* current->child->child = NULL; */
}

void llist_pop(llist* list)
{
    if (list->child == NULL) {
	free(list);
	return;
    }

    if (list->child->child == NULL) {
	free(list->child);
	list->child = NULL;
	return;
    }

    return llist_pop(list->child);
}
