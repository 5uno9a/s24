# Compiler to use
CC=g++
# Compiler flags: -Wall for all warnings, -fPIC for Position Independent Code, necessary for shared libraries
CFLAGS=-Wall -fPIC

# Default target to build both the shared library and the executable
all: libsparrow.so p1

# Rule to build the shared library from its object file
libsparrow.so: sparrow.o
	$(CC) -shared -o libsparrow.so sparrow.o

# Rule to compile sparrow.cpp into an object file
sparrow.o: sparrow.cpp
	$(CC) $(CFLAGS) -c sparrow.cpp

# Rule to build the executable by directly compiling p1.cpp and linking with the shared library
p1: p1.cpp libsparrow.so
	$(CC) $(CFLAGS) p1.cpp -o p1 -L. -lsparrow

# Rule to clean up generated files
clean:
	rm -f *.o *.so p1

# Mark 'all' and 'clean' as phony targets
.PHONY: all clean
