#include "common.h"
#include "lexer.h"
#include "llist.h"

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
		// parse(tokens);
    }
    return 0;
}
