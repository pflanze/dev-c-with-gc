#include "c-with-gc.h"

#include <stdio.h>

struct {
    int a;
} f_env;

struct {
    int b;
    int c;
} f_arg;

void f (f_env* env, f_arg* arg) {
    printf("vars %i %i %i\n", env->a, arg->b, arg->c);
}

// a procedure that takes an env, and, hm, hm.
typedef  generic_proc;

struct {
    generic_proc proc;
    f_env env;
} f_closure;


int main () {
    f(10,11);
    return 0;
}
