#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE *fp = NULL;

    int lines = 0, words = 0, chars = 0;
    int c;
    int in_word = 0;

    // 1) Decide where input comes from
    if (argc == 2) {
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            perror("wc");
            return 1;
        }
    } else if (argc == 1) {
        fp = stdin; // standard input
    } else {
        fprintf(stderr, "Usage: wc [FILE]\n");
        return 1;
    }

    // 2) Read one character at a time, count
    while ((c = fgetc(fp)) != EOF) {
        chars++;

        if (c == '\n') lines++;

        if (isspace(c)) {
            in_word = 0;
        } else {
            if (!in_word) {
                words++;
                in_word = 1;
            }
        }
    }

    // 3) Output counts (format doesn’t need to match exactly)
    printf("%d %d %d\n", lines, words, chars);

    if (fp != stdin) fclose(fp);
    return 0;
}
