#include <../inc/pathfinder.h>

int find_size(char *s) {
    int file = open(s, O_RDONLY);
    char c;
    
    if(file < 0) {
        error_output(s, 1, 0);
    }
    if (read(file, &c, 1) == 0) {
        error_output(s, 2, 0);
    }
    close(file);
    char **str = mx_strsplit(mx_file_to_str(s), '\n');
    const int size = mx_atoi(*str);
    mx_strdel(str);
    if (size == -1) {
        error_output(s, 3, 0);
    }
    return size;
}

