<<<<<<< HEAD
TARGET 	:= repl

OBJS := main.o \

$(TARGET): $(OBJS)
	$(CC) -Wall -o $(TARGET) $(OBJS)
	@echo Sucessfully built file: $(TARGET)

%.o: %.c
	$(CC) -Wall -c $< $(INC) $(LIBS) -o $@

clean:
	rm -f $(TARGET)
	find  -name "*.o" -type f -delete

rebuild: clean $(target)
=======
LIBS := -ledit -lm
OBJS := $(patsubst %.c,%.o,$(wildcard *.c))
# WARN := -Werror -Wall -Wextra
TARG := repl
CC := gcc

repl: $(OBJS)
	$(CC) $(WARN) -o $(TARG) $(OBJS) $(LIBS)

clean:
	rm -rf $(OBJS) $(TARG)
>>>>>>> added lexer
