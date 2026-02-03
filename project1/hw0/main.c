#include <stdio.h>
#include <sys/resource.h>

static void print_limit(const char *label, int resource) {
    struct rlimit rl;

    if (getrlimit(resource, &rl) != 0) {
        perror("getrlimit");
        return;
    }

    // rl.rlim_cur is the SOFT limit (what the assignment wants)
    if (rl.rlim_cur == RLIM_INFINITY) {
        printf("%s: unlimited\n", label);
    } else {
        printf("%s: %llu\n", label, (unsigned long long)rl.rlim_cur);
    }
}

int main(void) {
    print_limit("stack size", RLIMIT_STACK);
    print_limit("process limit", RLIMIT_NPROC);
    print_limit("max file descriptors", RLIMIT_NOFILE);
    return 0;
}
