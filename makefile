OBJS := $(patsubst %.c,%.o,$(wildcard *.c))
WARN := -Werror -Wall -Wextra
TARG := repl
OS   := linux
CC   := gcc

ifeq ($(OS),windows)
	#LIBS 	:= -lm -mwindows
	D 	:= -DWINDOWS
	SUFFIX	:= .exe
else
	LIBS 	:= -ledit -lm
endif

$(info OS target: $(OS))
$(info Cross compiling: $(XC))
ifeq ($(OS), windows)
$(info Macros defined: $(D))
endif

repl: $(OBJS)
	@echo OS target: $(OS)
ifeq ($(OS),windows)
	@echo Macros defined: $(D)
endif
	$(CC) $(WARN) -o $(TARG) $(OBJS) $(LIBS)
	@echo Sucessfully built file: $(TARG)$(SUFFIX)

lib: $(OBJS)
	$(CC) -shared -o $(TARG) $(OBJS) $(LIBS)

clean:
	rm -rf $(OBJS) $(TARG)
