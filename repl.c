#include "lexer.h"

#ifdef _WIN32

static char buffer[2048];

char* readline(char* prompt) {
    fputs(prompt, stdout);
    fgets(buffer, 2048, stdin);
    char* cpy = malloc(strlen(buffer)+1);
    strcpy(cpy, buffer);
    cpy[strlen(cpy)-1] = '\0';
    return cpy;
}

void add_history(char* unused) {}

#endif

int main(int argc, char** argv)
{
    while (1) {

	char* input = readline("lispy> ");
	add_history(input);

	scan(input);

	/* lexeme* x = malloc(sizeof(lexeme)); */
	/* x->type = LEX_INT; */
	/* x->value = "1"; */


	/* lexeme* y = malloc(sizeof(lexeme)); */
	/* y->type = LEX_INT; */
	/* y->value = "2"; */


	/* lexeme* z = malloc(sizeof(lexeme)); */
	/* z->type = LEX_INT; */
	/* z->value = "3"; */

	/* llist* list = llist_new(NULL, sizeof(void*)); */


	/* llist_push(list, y, sizeof(void*)); */
	/* llist_push(list, z, sizeof(void*)); */

	/* llist_print(list, print_as_lexeme); */

	/* puts(""); */

	/* llist_pop(list); */
	/* llist_pop(list); */

	/* llist_print(list, print_as_lexeme); */
	/* return 0; */

    }

    return 0;
}
