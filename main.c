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
	  int i,
	  pair_t* origlis) {
    if (! lis) {
	printlis(env, origlis, i, origlis);
    } else {
	printf("%s element %i is value: %i\n", env->prefix, i, CAST(int,lis->car));
	// again shortcut self call, no need for closure ?
	printlis(env, lis->cdr, i+1, origlis);
    }
}

struct printlis_closure {
    void (*proc) (struct printlis_env* env,
		  pair_t* lis,
		  int i,
		  pair_t* origlis);
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


int main (int argc, char** argv) {
    pair_t* lis=NULL;
    for (int i=argc-1, i>=0, i--) {
	LET_NEW(p, pair_t);
	p->car = argv[i];
	p->cdr= lis;
	lis= p;
    }
    struct printlis_closure* myprintlis= make_printlis(NULL,"argv");
    CALL(myprintlis, lis, 0, lis);
    return 0;
}
