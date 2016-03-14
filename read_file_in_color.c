#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main (int argc, char **argv) {

    if (argc > 2) {
        fprintf (stderr, "\e[1;31m%s\e[0m%s\n", "Error: ", "Too much arguments");
        fprintf (stderr, "%s\n", "Use ./color --help for more information.");
        return 2;
    }

    if (argc == 1) {
        fprintf (stderr, "\e[1;31m%s\e[0m%s\n", "Error: ", "Too few arguments. No file selected.");
        fprintf (stderr, "%s\n", "Use ./color --help for more information.");
        return 2;
    }

    if (strcmp (argv[1], "-h") == 0 \
        || strcmp (argv[1], "--help") == 0) {
        printf ("%s\n", "Usage: ./color [FILE]");
        printf ("%s\n", "   or: `./color -h` or `./color --help` to show this message");
        return 1;
    }
    char *filename = argv[1];
    FILE *file = fopen (filename, "r");
    int r, g, b;
    bool reach_end = false;

    if (file == NULL) {
        fprintf (stderr, "\e[1;31m%s\e[0m%s\n", "Error: ", "No such file.");
        return 2;
    }
    while (!reach_end) {
        r = fgetc (file);
        g = fgetc (file);
        b = fgetc (file);
        if (r == EOF) {
            r = 0;
            reach_end = true;
        }
        if (g == EOF) {
            g = 0;
            reach_end = true;
        }
        if (b == EOF) {
            b = 0;
            reach_end = true;
        }
        printf ("\e[48;2;%d;%d;%dm \e[0m", r, g, b);
    }

    printf ("\e[0m\n");
    fclose (file);

    return 0;
}
