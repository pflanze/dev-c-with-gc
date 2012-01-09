#include "c-with-gc.h"

#include <stdio.h>

struct f_env {
    int a;
} f_env;

struct f_arg {
    int b;
    int c;
} f_arg;

void f (struct f_env* env, struct f_arg* arg) {
    printf("vars %i %i %i\n", env->a, arg->b, arg->c);
}

// a procedure that takes an env, and, hm, hm.
//typedef  generic_proc;

struct {
    void(proc)(struct f_env* env, struct f_arg* arg);
    struct f_env env;
} f_closure;


int main () {
    f(10,11);
    return 0;
}
