#include <stdio.h>
#include <stdlib.h>

const char *version = "7.2.1";

#include "au.h"

int main() {
    const char *url = "https://raw.githubusercontent.com/bartoszpiech/au/master/au_tests.c";

    char *remote_ver = get_remote_version(url);
    printf("%s\n", remote_ver);
    free(remote_ver);
    return 0;
}
