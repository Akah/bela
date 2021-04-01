LIBS := -ledit -lm
OBJS := $(patsubst %.c,%.o,$(wildcard *.c))
# WARN := -Werror -Wall -Wextra
TARG := repl
CC := gcc

repl: $(OBJS)
	$(CC) $(WARN) -o $(TARG) $(OBJS) $(LIBS)

clean:
	rm -rf $(OBJS) $(TARG)
