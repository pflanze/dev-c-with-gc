#include "c-with-gc.h"

#include <stdio.h>

struct f_env {
    int a;
};

struct f_arg {
    int b;
    int c;
};

void f (struct f_env* env, struct f_arg* arg) {
    printf("vars %i %i %i\n", env->a, arg->b, arg->c);
}

struct {
    void(*proc)(struct f_env* env, struct f_arg* arg);
    struct f_env env;
} f_closure;


int main () {
    struct f_env env= {
	10
    };
    struct f_arg arg= {
	11,
	12
    };
    f(&env,&arg);
    return 0;
}
