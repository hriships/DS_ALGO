OS = $(shell uname -s)
CC = gcc

ifeq ($(OS), Darwin)
	LIB_NAME = libsort.dylib
	CCFLAGS = -dynamiclib -o $(LIB_NAME)
	CCBFLAGS =  -Wall /usr/lib/libsort.dylib
else
	LIB_NAME = libsort.so 
	CCFLAGS = -shared -o $(LIB_NAME) -fPIC
	CCBFLAGS = -lc -lsort
endif

SORING_MAKE:
	@$(CC) $(CCFLAGS) insertion_sort.c heap_sort.c merge_sort.c -dynamiclib
	@sudo cp $(LIB_NAME) /usr/lib/
	@rm $(LIB_NAME)
	@sudo cp sorting.h /usr/include/
	@$(CC) $(CCBFLAGS) -o sorting sorting_framework.c
	@./sorting 10
	@sudo cp sorting /usr/bin/
	@echo "Sorting compiled successfully, build with <3 core programming academy"
	@echo "https://www.facebook.com/coreprogrammingacademy/"