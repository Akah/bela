#include "lexer.h"
#include "llist.h"

void print_lexeme(void* lex)
{
    lexeme* casted = (lexeme *)lex;
    if (casted)
	    printf("(%s, %s)\n", lexeme_t_string[casted->type], casted->value);

}

char peek(char* string)
{
    return *string;
}

char consume(char** string)
{
    return *(*string)++;
}

// OPTIMISATION: replace with macro
bool is_digit(char c)
{
    return c >= '0' && c <= '9';
}

// OPTIMISATION: replace with macro
bool is_char(char c)
{
    return (c >= 'A' && c <= 'Z')
	|| (c >= 'a' && c >= 'z');
}

// OPTIMISATION: replace with macro
bool is_operator(char c)
{
    return c == '+'
	|| c == '-'
	|| c == '/'
	|| c == '*';
}

char* as_string(char c){
    char* cout = (char[2]){c, '\0'};
    return cout;
}

lexeme* new_lexeme(lexeme_t type, char* value)
{
    lexeme* lexeme = malloc(sizeof(lexeme));
    lexeme->type  = type;
    lexeme->value = malloc(sizeof(char) * strlen(value));
    strcpy(lexeme->value, value);
    return lexeme;
}

void free_lexeme(lexeme* lexeme)
{
    free(lexeme->value);
    free(lexeme);
}

llist* scan(char* string)
{
    char current_value[64] = "";
    llist* list = llist_create(NULL);

    while (peek(string)) {
        if (peek(string) == ' ') {
            consume(&string);
            continue;
        }
        if (peek(string) == '(') {
            lexeme* lexeme = new_lexeme(LEX_OBR, as_string(consume(&string)));
            llist_push(list, lexeme);
            continue;
        }
        if (peek(string) == ')') {
            lexeme* lexeme = new_lexeme(LEX_CBR, as_string(consume(&string)));
            llist_push(list, lexeme);
            continue;
        }
        if (is_operator(peek(string))) {
            lexeme* lexeme = new_lexeme(LEX_OPR, as_string(consume(&string)));
            llist_push(list, lexeme);
            continue;
        }
        if (is_digit(peek(string))) {
            while(is_digit(peek(string))) {
		        strcat(current_value, as_string(consume(&string)));
            }
            lexeme* lexeme = new_lexeme(LEX_INT, current_value);
            llist_push(list, lexeme);
            current_value[0] = '\0';
            continue;
        }

	lexeme* lexeme = new_lexeme(LEX_INV, as_string(consume(&string)));
        llist_push(list, lexeme);
    }

    return list;
}
