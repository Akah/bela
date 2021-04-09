// TODO: convert operator functions to use 64 bit ints
// TODO: compatability for 32 bit systems (ARMv7)

#include "implementations.h"

ret_val* add(llist* args)
{
    struct node* node = *args;
    node = node->next; // skip firsdst null element
    int total = 0;
    while (node->data != NULL) {
	total += atoi(node->data);
	// TODO: fix this shit in the while loop condition
	if (node->next == NULL)
	    break;

	node = node->next;
    }

    printf("-> %d\n", total);

    uint32_t* val_p = malloc(sizeof(uint32_t*));
    memcpy(val_p, &total, sizeof(uint32_t));

    ret_val* ret = malloc(sizeof(ret_val));
    ret->type = INT;
    ret->value = val_p;

    return ret;

    // will need to free return value struct and contained integer after use...
}

uint32_t sub(llist* args)
{
    struct node* node = *args;
    int total = *(int *)node->data;
    while (node->next != NULL) {
	total -= *(int *)node->data;
	node = node->next;
    }
    return total;
}

uint32_t dvd(llist* args)
{
    struct node* node = *args;
    int total = *(int *)node->data;
    while (node->next != NULL) {
	total /= *(int *)node->data;
	node = node->next;
    }
    return total;
}

uint32_t mul(llist* args)
{
    struct node* node = *args;
    int total = *(int *)node->data;
    while (node->next != NULL) {
	total *= *(int *)node->data;
	node = node->next;
    }
    return total;
}
