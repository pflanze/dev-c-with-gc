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


typedef void* Object;

/* lists */

struct pair {
    Object car;
    Object cdr;
};
// flat kinds of pairs?...  then multitude of map implementations
// needed yeah, or dyn dispatch

/* General types (*Interface*!), if C had struct equiv typing, right?,
   or, just *do* use these in definitions? -- AH, env is (ehr, has to
   be) actually unchecked. */

struct mapfn_arg {
    Object v;
};

//struct map_env not needed, except for uniformity, but, alas,

struct Empty_env {
};

struct Some_env {
    /* anything */
};

struct map_arg {
    void(*mapfn)(struct Some_env* env, struct mapfn_arg* arg);
    struct pair* lis;
};

void map (struct Empty_env* env, struct map_arg* arg) {
    if (!(arg->lis)) {
	RETURN(NULL);
    } else {
	ç
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
