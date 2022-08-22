#include "au.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <curl/curl.h>

void print_version() {
    printf("Current version :%s\n", version);
}

bool is_delimiter(const char c) {
    // TODO: add more delimiters, or user can choose delimiter he likes
    return c == '.' || c == '\0';
}

/*
 * this function takes two char * as arguments and checks if v1 is newer than v2
 */
bool newer_version(const char *v1, const char *v2) {
    size_t index = -1;
    for (size_t i = 0; i == 0 || (v1[i-1] != '\0' && v2[i-1]) != '\0'; i++) {
        bool del1 = is_delimiter(v1[i]);
        bool del2 = is_delimiter(v2[i]);
        if (del1 ^ del2) {  // xor gate (one of them is delimiter)
            return del2;
        } else if (del1 && del2) {
            int l1 = strtol(&v1[index + 1], NULL, 0);
            int l2 = strtol(&v2[index + 1], NULL, 0);
            if (l1 > l2) {
                return true;
            } else if (l2 > l1) {
                return false;
            } else {
                index = i;
            }
        }
    }
    if (strlen(v1) > strlen(v2)) {
        return true;
    }
    return false;
}

static size_t 
write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
    char *udata = (char *)userdata;
    size_t bytes = size * nmemb;
    char *version = strstr(ptr, "const char *version");
    if (version != NULL) {
        // find apostrophes
        char *firstapost = index(version, '"');
        char *secondapost = index(firstapost + 1, '"');
        int len = secondapost - firstapost - 1;
        strncpy(udata, firstapost + 1, len);
        udata[len] = 0;
    }
    return bytes;
}

char *get_remote_version(const char *url) {
    CURL *curl = curl_easy_init();
    char *data = malloc(sizeof(char) * 1024);
    if(curl) {
        CURLcode res;
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, data);
        res = curl_easy_perform(curl);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        if (res != CURLE_OK) {
            free(data);
            return NULL;
        }
    }
    return data;
}

static size_t 
download_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
    FILE *fp = (FILE *)userdata;
    size_t bytes = size * nmemb;
    printf("received %ld bytes\n", bytes);
    fwrite(ptr, size, nmemb, fp);

    return bytes;
}

void download_new_binary(const char *url, const char *file_name) {
    FILE *file = fopen(file_name, "wb");
    CURL *curl = curl_easy_init();
    if(curl) {
        //CURLcode res;
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, download_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
        //res = curl_easy_perform(curl);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    fclose(file);
}

void check_for_updates() {
    char *remote_ver = get_remote_version(url);
    if (remote_ver == NULL) {
        fprintf(stderr, "Error, could not check for updates\n");
        return;
    }
    bool needs_update = newer_version(remote_ver, version);
    if (needs_update) {
        download_new_binary(binurl, binname);
        printf("updated the software from version %s to %s, please restart the program\n", version, remote_ver);
    }
    free(remote_ver);
}
