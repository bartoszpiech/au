#ifndef AU_H
#define AU_H

#include <stdbool.h>

extern const char *version;

void print_version();
bool newer_version(const char *v1, const char *v2);
char *get_remote_version(const char *url);
void download_new_binary(const char *url);

#endif
