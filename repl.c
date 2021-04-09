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

	// evaluation
	if (expr->fn){
	    return_v* val = (return_v*)expr->fn(expr->exprs);
	    printf("--> %d\n", *(int *)(val->value));
	} else {
	    puts("function pointer was null");
	}

	llist_free(tokens);
	free_expr(expr);
    }
    return 0;
}
