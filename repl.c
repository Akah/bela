#include "common.h"
#include "llist.h"
#include "lexer.h"
#include "parser.h"

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
	parse(tokens);

	llist* lexemes = scan(input);

	parse(lexemes);

	llist_free(lexemes);
    }
    return 0;
}
