#include <stdio.h>
#include <stdlib.h>

const char *version = "7.0.0";
const char *src_url = "https://raw.githubusercontent.com/bartoszpiech/au/master/au_tests.c";
const char *bin_url = "http://panamint.ict.pwr.wroc.pl/~bpiech/uploads/au/tests";

#include "au.h"

int main(int argc, char **argv) {
    print_version();
    ask_and_update(argv[0]);
    return 0;
}
