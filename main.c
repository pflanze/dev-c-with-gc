#include <stdlib.h>

#include "c-with-gc.h"

#include <stdio.h>

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


struct printlis_env {
    char* prefix;
};

void
printlis (struct printlis_env* env,
	  pair_t* lis,
	  int i) {
    if (! lis) {
	return;
    } else {
	printf("%s element %i is value: %i\n", env->prefix, i, CAST(int,lis->car));
	// again shortcut self call, no need for closure ?
	printlis(env, lis->cdr, i+1);
    }
}

struct printlis_closure {
    void (*proc) (struct printlis_env* env,
		  pair_t* lis,
		  int i);
    struct printlis_env env;
};

struct printlis_closure*
make_printlis (struct Empty_env* _env,
	       char* prefix) {
    LET_NEW(res, struct printlis_closure);
    res->proc= &printlis;
    res->env.prefix= prefix;
    return res;
}


int main () {
    pair_t lis;
    lis.car = CAST(Object,101);
    lis.cdr = NULL;
    struct printlis_closure* myprintlis= make_printlis(NULL,"lis");
    CALL(myprintlis, &lis, 0);
    return 0;
}
