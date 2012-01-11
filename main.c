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

DEFN(pair_t*, map,
     struct mapfn_closure* mapfn,
     pair_t* lis) {
    if (!lis) {
	return NULL;
    } else {
	LET_NEW(new, pair_t);
	new->car= CALL(mapfn, lis->car);
	new->cdr= SELFCALL(map, mapfn, lis->cdr);
	return new;
    }
}


DEFN(long, cj_atol,
     char* v) {
    return atol(v);
}


DEFCLOSURE(void, printlis,
	   {char* prefix;},
	   pair_t* lis,
	   int i,
	   pair_t* origlis) {
    if (! lis) {
	SELFCALL(printlis, origlis, i, origlis);
    } else {
	printf("%s element %i is value: '%s'\n",
	       env->prefix, i, CAST(char*,lis->car));
	SELFCALL(printlis, lis->cdr, i+1, origlis);
    }
}

DEFN(struct printlis_closure*, make_printlis,
     char* prefix) {
    LET_NEW(res, struct printlis_closure);
    res->proc= &printlis_proc;
    res->env.prefix= prefix;
    return res;
}


// mutual recursion example
typedef int BOOL;
#define FALSE 0
#define TRUE 1

DEFN(BOOL, zerop,
     long n) {
    return (n == 0);
}

DEFN(BOOL, evenp,
     long n);

DEFN(BOOL, oddp,
     long n) {
    if (CALL(zerop, n)) {
	return FALSE;
    } else {
	return CALL(evenp, n-1);
    }
}

BOOL
evenp_proc (const struct evenp_env* _env,
	    long n) {
    if (CALL(zerop, n)) {
	return TRUE;
    } else {
	return CALL(oddp, n-1);
    }
}


int main (int argc, char** argv) {
    if (argc==2) {
	long v= atol(argv[1]);
	printf("is number %ld even?: %s\n",
	       v,
	       (CALL(evenp,v) ? "yes" : "no"));
    } else {
	pair_t* lis=NULL;
	int i;
	for (i=argc-1; i>=0; i--) {
	    LET_NEW(p, pair_t);
	    p->car = argv[i];
	    p->cdr= lis;
	    lis= p;
	}
	struct printlis_closure* myprintlis= CALL(make_printlis,"argv");
	CALL(myprintlis, lis, 0, lis);
    }
    return 0;
}
