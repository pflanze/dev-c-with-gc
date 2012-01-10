#include "c-with-gc.h"

#include <stdio.h>

struct f_env {
    int a;
};

void f (struct f_env* env, int b, int c) {
    printf("vars %i %i %i\n", env->a, b, c);
}

struct {
    void(*proc)(struct f_env* env, struct f_arg* arg);
    struct f_env env;
} f_closure;


/* lists */

struct pair {
    Object car;
    Object cdr;
};
// flat kinds of pairs?...  then multitude of map implementations
// needed yeah, or dyn dispatch


/* interface, with undefined env */
struct {
    Object(*proc)(struct Some_env* env, Object v);
    struct Some_env env;
} mapfn_closure;

pair* map (struct Empty_env* _env,
	   struct mapfn_closure* mapfn,
	   struct pair* lis) {
    if (!(arg->lis)) {
	return NULL;
    } else {
	LET_NEW(new, pair);
	new->car= CALL(mapfn, lis->car);
	new->cdr= map(NULL, mapfn, lis->cdr);
	return new;
    }
}

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
