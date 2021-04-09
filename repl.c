#include "common.h"
#include "llist.h"
#include "lexer.h"
#include "parser.h"

// TODO: move windows readline to seperate file
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
	llist* tokens = scan(input);

	expr* expr = parse(tokens);

	// causes warning because type was void* despite having correct value...
	// TODO: instead of returning void* return a struct containing the value and it's expected type

	puts("of course");
	//ret_val* value = (ret_val*)(expr->fn(expr->exprs));

	if (expr->fn){
	    expr->fn(expr->exprs);
	}

	puts("its here");

	// printf("returned result %d\n", *(int*)value->value);

	llist_free(tokens);
	free_expr(expr);
    }
    return 0;
}
