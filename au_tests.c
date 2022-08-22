#include <stdio.h>
#include <stdlib.h>

const char *version = "7.1.2";
const char *url = "https://raw.githubusercontent.com/bartoszpiech/au/master/au_tests.c";
const char *binurl = "http://panamint.ict.pwr.wroc.pl/~bpiech/uploads/au/tests";

#include "au.h"

int main() {

    char *remote_ver = get_remote_version(url);
    printf("local version -- %s\n", version);
    printf("remote version -- %s\n", remote_ver);
    bool needs_update = newer_version(remote_ver, version);
    printf("needs update -- %s\n", needs_update ? "true" : "false");
    if (needs_update) {
        download_new_binary(binurl);
    }
    free(remote_ver);
    return 0;
}
