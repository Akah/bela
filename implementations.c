#include "implementations.h"

uint32_t add(llist* args)
{
    struct node* node = *args;
    int total = *(int *)node->data;
    while (node->next != NULL) {
	total += *(int *)node->data;
	node = node->next;
    }
    return total;
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
