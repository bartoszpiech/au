#include <stdio.h>
#include <stdlib.h>

const char *version = "7.1.0";
const char *url = "https://raw.githubusercontent.com/bartoszpiech/au/master/au_tests.c";
const char *binurl = "http://panamint.ict.pwr.wroc.pl/~bpiech/uploads/au/tests";
const char *binname = "tests";

#include "au.h"

int main() {
    print_version();
    check_for_updates();
    return 0;
}
