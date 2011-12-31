#include "c-with-gc.h"

#include <stdio.h>

struct {
    int a;
} f_env;

BEGIN_PROC(f, f_env* env, int b, int c)
printf("vars %i %i %i\n", env->a, b, c);
END_PROC()

typedef  generic_proc;

struct {
    generic_proc proc;
    f_env env;
} f_closure;


int main () {
    f(10,11);
    return 0;
}
