#include "common.h"
#include "llist.h"
#include "lexer.h"
#include "parser.h"
#include "eval.h"

#ifdef TEST
#include "test.h"
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
#ifdef TEST
    run_tests();
    return 0;
#else

    handle_args(argc, argv);

    while (1) {
	char* input = readline("repl> ");
	add_history(input);

	llist* tokens = scan(input);
	if (tokens == NULL) {
	    puts("tokens list recieved from lexer is NULL");
	    break;
	}
	llist_print(tokens, print_lexeme);

	ast* ast = parse(tokens);
	if (ast == NULL) {
	    puts("abstract sytax tree return from parser is NULL");
	    break;
	}
	print_ast(ast, 0);

	long result = eval(ast);
    }
#endif

    return 0;
}
