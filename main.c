#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <regex.h>

#define str_is(a, b) strcmp(a,b)==0

char* version = "0.0.0";

char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    while (*tmp) {
        if (a_delim == *tmp) {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    count += last_comma < (a_str + strlen(a_str) - 1);
    count++;

    result = malloc(sizeof(char*) * count);

    if (result) {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token) {
	    if (idx > count) {
		return NULL;
	    }
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
	if (idx != count -1) {
	    return NULL;
	}
        *(result + idx) = 0;
    }

    return result;
}

int read_console()
{
    for (;;) {
	char input[128];

	printf("$ ");
	fgets(input, 128, stdin);
	//dirty fix to remove \n from end of last input

	char** split_lf = str_split(input, (char)10);
	if (split_lf[0] == NULL) continue;

	char** buffer = str_split(split_lf[0], ' ');
	if (buffer == NULL) continue;

	/* DEBUG TOKENS: */
	int i;
        for (i = 0; *(buffer + i); i++) {
            printf("[%d]%s\n", i, *(buffer + i));
            //free(*(buffer + i));
        }

	char msg[40];
	if (str_is(buffer[0], "add")) {
	    if (buffer[1] && buffer[2]) {
		printf("%d + %d = %d\n",
		       atoi(buffer[1]),
		       atoi(buffer[2]),
		       atoi(buffer[1]) + atoi(buffer[2]));
	    } else {
		printf("not enough parameters passed for function\n");
	    }
	    continue;
	}

	sprintf(msg, "No command called %s", buffer[0]);
	puts(msg);
    }

    return 0;
}

void print_result(int value)
{

    // If pattern found
    if (value == 0) {
        printf("found.\n");
    }

    // If pattern not found
    else if (value == REG_NOMATCH) {
        printf("not found.\n");
    }

    // If error occured during Pattern
    // matching
    else {
        printf("An error occured.\n");
    }
}

int main()
{
    //printf("REPL Version %s\n", version);

    regex_t regex;
    // ^([a-zA-Z_-])+\w* variable name

    // char *operator = "^(\\+|\\-|\\/|\\*) +";
    // char number[] = "^-?[0-9]+$";
    // char

    int value;
    value = regcomp(&regex, operator, REG_EXTENDED);

    if (value == 0)
	printf("Regular expression compiled successfully.\n");
    else {
        printf("Compilation error.\n");
	return 1;
    }

    value = regexec(&regex, "+ ", 0, NULL, 0);
    print_result(value);


    return 0;
}

/*

number:   -?[0-9]+
operator: (\+|\-|\/|\*) +

expr:     number | \(operator expr+.*\)
(*LIMIT_RECURSION=100)(-?[0-9]+|\((\+|\-|\/|\*) +(?R) \))

*/
