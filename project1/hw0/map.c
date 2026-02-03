#include <stdio.h>
#include <stdlib.h>

static int static_data_var = 123;

void recur(int level) {
    int recur_stack_var = 0;
    printf("recur call %d: stack@ %p\n", level, (void*)&recur_stack_var);

    if (level > 0) {
        recur(level - 1);
    }
}

int main(int argc, char *argv[]) {
    int main_stack_var = 0;

    printf("main @ %p\n", (void*)&main);
    printf("recur @ %p\n", (void*)&recur);
    printf("main stack: %p\n", (void*)&main_stack_var);
    printf("static data: %p\n", (void*)&static_data_var);

    void *h1 = malloc(1);
    void *h2 = malloc(1);

    printf("Heap: malloc 1: %p\n", h1);
    printf("Heap: malloc 2: %p\n", h2);

    recur(3);

    free(h1);
    free(h2);

    return 0;
}
