#include "test.h"
#include "common.h"
#include "llist.h"
#include "lexer.h"
#include "parser.h"
// TODO: move to seperate binary or atleast only include with flag
#include "test.h"
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

void add_history(char* unused) {
    return;
}

#endif

int handle_args(int argc, char* argv[])
{
    for(int i= 0; i<argc; i++) {
	if (argv[i][0] == '-') {
	    if (argv[i][1] == 't') {
		return 1;
	    }
	    if (argv[i][1] == 'h') {
		puts("Usage test [options]");
		puts("Options:");
		puts("  -t      Run tests");
		puts("  -h      Displays this information");
		exit(0);
	    }
	}
    }
    return 0;
}

int main(int argc, char** argv)
{
    if (handle_args(argc, argv) == 1) {
	run_tests();
    	return 0;
    }

    while (1) {
	char* input = readline("repl> ");
	add_history(input);
	llist* tokens = scan(input);
	if (tokens == NULL)
		break;

	parse(tokens);

	/* char* a = "a"; */
	/* char* b = "b"; */
	/* char* c = "c"; */

	/* llist* list = llist_create(a); */

	/* llist_push(list, b); */
	/* llist_push(list, c); */

	/* llist_pop(list); */

	/* llist_print(list, print_string); */

	/* struct node* last = llist_last(list); */

	/* printf("%s\n", (char*)last->data); */

	// evaluation
    //     if (expr->fn){
	//     return_v* val = (return_v*)expr->fn(expr->exprs);
	//      printf("--> %d\n", *(int *)(val->value));
	//  } else {
	//      puts("function pointer was null");
	//  }

	// /* llist_free(tokens); */
	// /* free_expr(expr); */
    }
    return 0;
}
