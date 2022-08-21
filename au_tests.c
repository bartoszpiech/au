#include <stdio.h>
const char *version = "7.0";

#include "au.h"



int main() {
    //print_version();
    printf("%s\n", newer_version("12.3", "1.23") ? "true" : "false");
    printf("%s\n", newer_version("12.3", "1.2345") ? "true" : "false");
    printf("%s\n", newer_version("1", "2") ? "true" : "false");
    printf("%s\n", newer_version("3", "1") ? "true" : "false");
    printf("%s\n", newer_version("1.2.3.4", "1.2.3") ? "true" : "false");
    printf("%s\n", newer_version("1.2.3", "1.2.3.4") ? "true" : "false");
    printf("%s\n", newer_version("1.1", "1.2") ? "true" : "false");
    printf("%s\n", newer_version("1.2", "1.1") ? "true" : "false");

    return 0;
}
