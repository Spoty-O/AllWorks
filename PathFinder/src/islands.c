#include "../inc/pathfinder.h"

void islands(char *s, finder_data *finder) {
    finder->graph = (int **)malloc(sizeof(int *) * finder->size);
    finder->dist = (int **)malloc(sizeof(int *) * finder->size);
    finder->a = (char **)malloc(sizeof(char *) * finder->size);
    for (int i = 0; i < finder->size; i++) {
        finder->graph[i] = (int *)malloc(sizeof(int *) * finder->size);
        finder->dist[i] = (int *)malloc(sizeof(int *) * finder->size);
        finder->a[i] = "\0";
        for (int j = 0; j < finder->size; j++) {
            if (j != i) {
                finder->graph[i][j] = INT_MAX;
            }
            else {
                finder->graph[i][j] = 0;
            }
        }
    }
    char *str = mx_file_to_str(s);
    char *dereferencing;
    char **island2;
    char **island;
    int dst;
    int i = 0;
    int j = 0;
    int alt = 0;
    bool add = true;
    int line = 1;
    int count = 0;

    while (str[i] != '\n') {
        i++;
    }
    while (str[i] != '\0') {
        if (str[i - 1] == '\n' || str[i] == '-' || str[i] == ',' || mx_isalpha(str[i])) {
            if (mx_isalpha(str[i]) && str[i + 1] == '\n') {
                error_output(s, 4, line);
            }
            if (str[i - 1] == '\n') {
                line++;
                if (!mx_isalpha(str[i])) {
                    error_output(s, 4, line);
                }
                island = mx_strsplit(&str[i], '-');
                island2 = island;
            }
            if (str[i] == '-') {
                island = mx_strsplit(&str[i + 1], ',');
            }
            dereferencing = *island;
            for (int len = 0; len < mx_strlen(*island); len++) {
                if (!mx_isalpha(dereferencing[len])) {
                    error_output(s, 4, line);
                }
            }
            for (int m = 0; m < finder->size; m++) {
                if (mx_strcmp(*island, finder->a[m]) == 0) {
                    add = false;
                }
            }
            if (add == true) {
                if (j < finder->size) {
                    finder->a[j++] = *island;
                }
                count++;
            }
            add = true;
            if (str[i] == ',') {
                dst = mx_atoi(*mx_strsplit(&str[i + 1], '\n'));
                if (mx_strcmp(*island, *island2) == 0) {
                    error_output(s, 4, line);
                }
                for (int x = 0; x < finder->size; x++) {
                    for (int y = 0; y < finder->size; y++) {
                        if (mx_strcmp(*island, finder->a[x]) == 0 && mx_strcmp(*island2, finder->a[y]) == 0) {
                            if (dst != -1) {
                                if (finder->graph[x][y] != INT_MAX) {
                                    error_output(s, 6, line);
                                }
                                finder->graph[x][y] = dst;
                                finder->graph[y][x] = dst;
                                alt += dst;
                            }
                            else {
                                error_output(s, 4, line);
                            }
                        }
                    }
                }
            }
        }
        i++;
    }
    if  (count != finder->size) {
        error_output(s, 5, line);
    }
    if (alt < 0) {
        error_output(s, 7, line);
    }
    mx_strdel(&dereferencing);
    mx_strdel(&str);
}

