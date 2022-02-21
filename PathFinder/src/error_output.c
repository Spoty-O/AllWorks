#include <../inc/pathfinder.h>

void error_output(char *s, int num, int line) {
    switch (num) {
    case 0:
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(0);
        break;

    case 1:
        mx_printerr("error: file ");
        mx_printerr(s);
        mx_printerr(" does not exist\n");
        exit(0);
        break;

    case 2:
        mx_printerr("error: file ");
        mx_printerr(s);
        mx_printerr(" is empty\n");
        exit(0);
        break;

    case 3:
        mx_printerr("error: line 1 is not valid\n");
        exit(0);
        break;

    case 4:
        mx_printerr("error: line ");
        mx_printerr(mx_itoa(line));
        mx_printerr(" is not valid\n");
        exit(0);
        break;

    case 5:
        mx_printerr("error: invalid number of islands\n");
        exit(0);
        break;

    case 6:
        mx_printerr("error: duplicate bridges\n");
        exit(0);
        break;

    case 7:
        mx_printerr("error: sum of bridges lengths is too big\n");
        exit(0);
        break;
    
    default:
        exit(0);
        break;
    }
}

