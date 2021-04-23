#include "test.h"

int t_run = 0;
int t_pass = 0;

bool failed = false;

void result() {
    printf("[%d/%d] tests passed\n", t_pass, t_run);
}

void test(char* name, bool(*test)(void))
{
    if (/*!f_runall &&*/ failed) return;
    bool result = (*test)();
    if (/*!f_runall &&*/ !result) failed = true;

    printf("%s %s\n", result ? SUCCESS : FAILURE, name);
    t_run++;
    t_pass += result;
}

bool test_maths(fn fn, int result, char* a, char* b, char* c)
{
    llist* list = llist_create(a);
    llist_push(list, b);
    if (c) llist_push(list, c);// optional

    return_v* v = fn(list);

    bool passed = true;

    printf("type: %d\n", v->type);
    printf("value:\n");
    printf("  is:   %d\n", *(int*)v->value);
    printf("  want: %d\n", result);

    if (v->type  != INT) passed = false;
    if (*(int*)v->value != result) passed = false;

    llist_free(list);

    free(v->value);
    free(v);

    return passed;
}


bool add_two_positive_ints()
{
    return test_maths(&add, 3, "1", "2", "0");
}

bool add_two_negative_ints()
{
    return test_maths(&add, -3, "-1", "-2", "0");
}

bool add_negative_and_positive_ints()
{
    return test_maths(&add, 1, "-1", "2", "0");
}

bool add_multiple_ints()
{
    return test_maths(&add, 6, "1", "2", "3");
}


/* bool subtract_two_positive_ints(){} */

/* bool subtract_two_negative_ints(){} */

/* bool subtract_negative_and_positive_ints(){} */

/* bool subtract_multiple_ints(){} */


/* bool divide_two_positive_ints(){} */

/* bool divide_two_negative_ints(){} */

/* bool divide_negative_and_positive_ints(){} */

/* bool divide_multiple_ints(){} */


/* bool multiply_two_positive_ints(){} */

/* bool multiply_two_negative_ints(){} */

/* bool multiply_negative_and_positive_ints(){} */

/* bool multiply_multiple_ints(){} */



void run_tests()
{
    /* llist* list = llist_create("1"); */
    /* llist_push(list, "1"); */

    /* llist_print(list, llist_print_int); */

    /* add(list); */

    /* __check(add_two_positive_ints); */
    __check(add_two_negative_ints);
    __check(add_negative_and_positive_ints);
    __check(add_multiple_ints);

    // implementations
    // llist
    // lexer
    // parser
}
