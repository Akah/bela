#include "common.h"
#include "llist.h"
#include "lexer.h"
#include "parser.h"
#include "eval.h"

#ifdef TEST
#include "test.h"
#endif

#define version_info \
    "REPL 0.1.1\n" \
    "Copyright (c) Robin White.\n" \
    "License GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.\n" \
    "This is free software: you are free to change and redistribute it.\n" \
    "There is NO WARRANTY, to the extent permitted by law.\n"

int handle_args(int argc, char* argv[])
{
    for(int i= 0; i<argc; i++) {
	if (argv[i][0] == '-') {
	    if (argv[i][1] == 'v') {
		#ifdef build
		printf("%s\nBuilt on: %s\nBuilt at: %s\n", version_info, build, time);
		#endif
		exit(0);
	    }
	    if (argv[i][1] == 'h') {
		puts("Usage test [OPTION]... [FILE]...");
		puts("Options:");
		puts("  -h      display this information");
		puts("  -v      display version information");
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

	ast* ast = parse(tokens);
	if (ast == NULL) {
	    puts("abstract sytax tree return from parser is NULL");
	    break;
	}

	long result = eval(ast);

	printf("%ld\n", result);
    }
#endif

    return 0;
}
