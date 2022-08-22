# AU -- Auto updater written in C
AU is an auto-update library for your programs written in C/C++, it checks for the new version that is hosted on remote server and if local version is older than the remote version, it swaps the binary file with newer one.

This library uses libcurl (curl-easy) to fetch the data from external servers.

## Usage
To be able to use this library, you'll have to download `au.h` and `au.c` files into your project.
Then in your main source file `#include "au.h"`, add the current version, src\_url and the bin\_url.
Here's an example:
```C
#include <stdio.h>
#include <stdlib.h>

// version of the program
const char *version = "7.1.0";
// link to look for the new version info (i'm using github src file)
const char *src_url = "https://raw.githubusercontent.com/bartoszpiech/au/master/au_tests.c";
// an url to pull binary file from (i'm hosting the file on my school's servers)
const char *bin_url = "http://panamint.ict.pwr.wroc.pl/~bpiech/uploads/au/tests";

// very important
#include "au.h"

int main(int argc, char **argv) {
    print_version();    // helper fcn to see what version of program you're running
    ask_and_update(argv[0]);    // ask your users if they want to make an update
    return 0;
}
```

### Compilation
Steps to compile the module (use your compiler instead of $CC):
- `$CC -c au.c -o au.o`
- `$cc main.c au.o -o main`

You also could use a shell script that i prepared, but fiddle around and modify it to meet your needs.
``` sh
#!/bin/sh

CC=gcc
CFLAGS="-Wall -pedantic -std=c11 -g -lcurl"
INC=au.c
OBJ=au.o
SRC=au_tests.c
BIN=tests

$CC $CFLAGS -c $INC -o $OBJ

$CC $CFLAGS $SRC $OBJ -o $BIN

./tests
```


# To keep in mind

You'll have to initialize those consts:
- `extern const char *version;`
- `extern const char *src_url;`
- `extern const char *bin_url;`

You can use those functions to update your program:
- `void update(const char *prog_name);`
- `void ask_and_update(const char *prog_name);`

