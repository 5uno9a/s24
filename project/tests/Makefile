# Compiler to use
CC=g++
# Compiler flags: -Wall for all warnings, -fPIC for Position Independent Code, necessary for shared libraries
CFLAGS=-Wall -fPIC -std=c++17

# Default target to build both the shared library and the executable
all: libsparrow.so p1 p2

# Rule to build the shared library from its object file
libsparrow.so: sparrow.o
	$(CC) sparrow.o -shared -o libsparrow.so 

# Rule to compile sparrow.cpp into an object file
sparrow.o: sparrow.cpp sparrow.h
	$(CC) $(CFLAGS) -c sparrow.cpp

# Rule to build the executable by directly compiling p1.cpp and linking with the shared library
p1: p1.cpp sparrow.h 
	$(CC) $(CFLAGS) p1.cpp -o p1 -L. -lsparrow

p2: p2.cpp sparrow.h
	$(CC) $(CFLAGS) p2.cpp -o p2 -L. -lsparrow
	
# Rule to clean up generated files
clean:
	rm -f *.o *.so p1 p2

# Mark 'all' and 'clean' as phony targets
.PHONY: all clean
