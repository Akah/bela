#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#include "common.h"

#include "lexer.h"
#include "llist.h"
#include "implementations.h"
#include "parser.h"

#define SUCCESS "\x1B[32m[SUCCESS]\x1B[0m"
#define FAILURE "\x1B[1m\x1B[31m[FAILURE]\x1B[0m"
#define WARNING "\x1B[1m\x1B[33m[WARNING]\x1B[0m"

#define __check(name) test(#name, &name)

void result();

void test(char* name, bool(*test)(void));

/* bool compare_int(int a, int b) { */
/*     return a == b; */
/* } */

/* bool compare_str(char* str1, char* str2) { */
/*     return strcmp(str1, str2) == 0; */
/* } */

void run_tests();


bool test_maths(fn fn, int result, char* a, char* b, char* c);


bool add_two_positive_ints();
bool add_two_negative_ints();
bool add_negative_and_positive_ints();
bool add_multiple_ints();

#endif
