#include "../inc/libmx.h"

char *mx_file_to_str(const char *file) {
    char c = 0;
    int count = 0;
    int i = 0;
    int df = open(file, O_RDONLY);

    if (df < 0) {
        return NULL;
    }
    while(read(df, &c, 1)) {
        count++;
    }
    char *string = mx_strnew(count);
    close(df);
    df = open(file, O_RDONLY);
    while(read(df, &c, 1)) {
        string[i] = c;
        i++;
    }
    close(df);
    return string;
}

