#ifndef AU_H
#define AU_H

#include <stdbool.h>

extern const char *version;
extern const char *src_url;
extern const char *bin_url;

void print_version();
bool newer_version(const char *v1, const char *v2);
char *get_remote_version(const char *url);
void download_new_binary(const char *url, const char *file_name);
void update(const char *prog_name);
void ask_and_update(const char *prog_name);

#endif
