#include "../inc/pathfinder.h"

int mx_atoi(const char *str) {
    int i = 0;
    int res = 0;

    while (str[i]) {
        if (!mx_isdigit(str[i])) {
            return -1;
        }
        res = res * 10;
        res = res + (str[i] - 48);
        i++;
    }
    return res;
}

