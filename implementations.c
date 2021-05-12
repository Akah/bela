// TODO: convert operator functions to use 64 bit ints
// TODO: compatability for 32 bit systems (ARMv7)
// TODO: create function to malloc return value struct
// TODO: free function for return value struct

#include "implementations.h"
#include "parser.h"

// NOTE: list of arguements should be strings
return_v* calc(char op, llist* args)
{
    struct node* node = *args;
    // node = node->next; // skip firsdst null element
    int total = atoi(node->data);
    node = node->next;
    while (node->data != NULL) {
	switch(op) {
	case '+':
	    total += atoi(node->data);
	    break;
	case '-':
	    total -= atoi(node->data);
	    break;
	case '/':
	    total /= atoi(node->data);
	    break;
	case '*':
	    total *= atoi(node->data);
	    break;
	}

	// TODO: fix this shit in the while loop condition
	if (node->next == NULL)
	    break;

	node = node->next;
    }

    uint32_t* val_p = malloc(sizeof(uint32_t*));
    memcpy(val_p, &total, sizeof(uint32_t));

    return_v* ret = malloc(sizeof(return_v));
    ret->type = INT;
    ret->value = val_p;

    return ret;
}

return_v* add(llist* args)
{
    return calc('+', args);
}

return_v* sub(llist* args)
{
    return calc('-', args);
}

return_v* dvd(llist* args)
{
    return calc('/', args);
}

return_v* mul(llist* args)
{
    return calc('*', args);
}
