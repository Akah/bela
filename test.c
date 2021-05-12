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

    if (v->type  != INT) passed = false;
    if (*(int*)v->value != result) passed = false;

    llist_free(list);

    free(v->value);
    free(v);

    return passed;
}

/* ADDITION */

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

/* SUBTRACTION */

bool subtract_two_positive_ints()
{
    return test_maths(&sub, 1, "2", "1", "0");
}

bool subtract_two_negative_ints()
{
    return test_maths(&sub, 1, "-1", "-2", "0");
}

bool subtract_negative_and_positive_ints()
{
    return test_maths(&sub, -3, "-1", "2", "0");
}

bool subtract_multiple_ints()
{
    return test_maths(&sub, 0, "3", "2", "1");
}


/* MULTIPLICATION */

bool multiply_two_positive_ints()
{
    return test_maths(&mul, 4, "2", "2", "1");
}

bool multiply_two_negative_ints()
{
    return test_maths(&mul, 4, "-2", "-2", "1");
}

bool multiply_negative_and_positive_ints()
{
    return test_maths(&mul, -4, "-2", "2", "1");
}

bool multiply_multiple_ints()
{
    return test_maths(&mul, 12, "3", "2", "2");
}


/* bool divide_two_positive_ints(){} */

/* bool divide_two_negative_ints(){} */

/* bool divide_negative_and_positive_ints(){} */

/* bool divide_multiple_ints(){} */

void run_tests()
{
    __check(add_two_positive_ints);
    __check(add_two_negative_ints);
    __check(add_negative_and_positive_ints);
    __check(add_multiple_ints);

    __check(subtract_two_positive_ints);
    __check(subtract_two_negative_ints);
    __check(subtract_negative_and_positive_ints);
    __check(subtract_multiple_ints);

    __check(multiply_two_positive_ints);
    __check(multiply_two_negative_ints);
    __check(multiply_negative_and_positive_ints);
    __check(multiply_multiple_ints);

    result();

    // implementations
    // llist
    // lexer
    // parser
}
