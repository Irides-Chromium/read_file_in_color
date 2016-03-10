#include <ncurses.h>
#include <stdio.h>

int main (int argc, char **argv) {

    if (argc > 2) {
        fprintf (stderr, "\e[1;31m%s\e[0m%s\n", "Error: ", "Too much arguments");
        return 2;
    }

    if (argc == 1) {
        fprintf (stderr, "\e[1;31m%s\e[0m%s\n", "Error: ", "Too few arguments");
        return 3;
    }
    char *filename = argv[1];
    FILE *file = fopen (filename, "r");
    int r, g, b;

    while (1) {
        r = fgetc (file);
        g = fgetc (file);
        b = fgetc (file);
        if (b == EOF) {
            break;
        }
        printf ("\e[48;2;%d;%d;%dm \e[0m", r, g, b);
    }
    fclose (file);

    printf ("\n");

    return 0;
}
