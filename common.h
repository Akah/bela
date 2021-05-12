#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#ifndef _WIN32
#include <editline/readline.h>
#include <editline/history.h>
#endif

#define GENERATE_ENUM(ENUM) ENUM ,
#define GENERATE_STRING(STRING) #STRING ,
