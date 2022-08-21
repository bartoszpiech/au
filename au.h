#ifndef AU_H
#define AU_H

#include <stdbool.h>

extern char *version;
void print_version();
bool newer_version(const char *v1, const char *v2);
#endif
