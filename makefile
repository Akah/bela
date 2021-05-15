OBJS 	:= $(patsubst %.c,%.o,$(wildcard *.c))
WARN 	:= -Werror -Wall -Wextra
TARG 	:= repl
OS   	:= $(shell uname)

ifeq ($(OS),$(filter $(OS),Windows_NT CYGWIN_NT-10.0))
# LIBS 	:= -lm -mwindows
	SUFFIX	:= .exe
	CC	:= gcc
else
	LIBS 	:= -ledit -lm
endif

ifeq ($(TARGET),Windows_NT)
ifeq ($(OS),Linux))
	CC	:= x86_64-w64-mingw32-gcc
endif
endif

$(info OS target: $(OS))
ifdef ($(TARGET))
	$(info Cross compiling: $(XC))
endif

repl: $(OBJS)
ifdef ($(D))
	@echo Macros defined: $(D)
endif
	$(CC) $(CFLAGS) $(WARN) -o $(TARG) $(OBJS) $(LIBS)
	@echo Sucessfully built file: $(TARG)$(SUFFIX)

lib: $(OBJS)
	$(CC) -shared -o $(TARG) $(OBJS) $(LIBS)

clean:
	rm -rf $(OBJS) $(TARG)

install:
	sudo cp repl /usr/bin

uninstall:
	sudo rm /usr/bin/repl

.PHONY: repl clean lib install uninstall
