.SUFFIXES:

EXE := stdio unistd
CC := clang -Weverything -O2 -DNDEBUG

.PHONY: all
all: $(EXE)

$(EXE): %: main.c %.c
	$(CC) $^ -o $@

.PHONY: clean
clean:
	rm -f $(EXE)
