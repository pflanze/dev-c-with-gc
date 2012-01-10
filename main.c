#include <stdlib.h>

#include "c-with-gc.h"

#include <stdio.h>

struct f_env {
    int a;
};

void f (struct f_env* env, int b, int c) {
    printf("vars %i %i %i\n", env->a, b, c);
}

struct f_closure {
    void(*proc)(struct f_env* env, int b, int c);
    struct f_env env;
};


/* lists */

struct pair {
    Object car;
    Object cdr;
};
// flat kinds of pairs?...  then multitude of map implementations
// needed yeah, or dyn dispatch

typedef struct pair pair_t;

/* interface, with undefined env */
struct mapfn_closure {
    Object(*proc)(struct Some_env* env, Object v);
    struct Some_env env;
};

pair_t*
map (struct Empty_env* _env,
	   struct mapfn_closure* mapfn,
	   pair_t* lis) {
    if (!lis) {
	return NULL;
    } else {
	LET_NEW(new, pair_t);
	new->car= CALL(mapfn, lis->car);
	new->cdr= map(NULL, mapfn, lis->cdr);
	return new;
    }
}

int main () {
    struct f_env env= {
	10
    };
    f(&env,11,12);
    return 0;
}
