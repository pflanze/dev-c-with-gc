#define ENV(...) { __VA_ARGS__ }

#define __PICK2nd(a,...) __VA_ARGS__

#define NOENV(it) 

#define DEFINE(Rtype, Name, Env, ...)					\
#define NOENV {}							\
    struct Name##_env Env;						\
#undef NOENV							\
    struct Name##_closure {						\
	Rtype (*proc) (struct Name##_env* env,				\
		       __VA_ARGS__);					\
	struct Name##_env env;						\
    };									\
#define NOENV _,struct Name##_closure Name = { Name##_proc,	{} };	\
    __PICK2nd(Env)							\
#undef NOENV							\
    Rtype Name##_proc (struct Name##_env* env, __VA_ARGS__) 


#define CALL(varname,...) varname->proc(&(varname->env), __VA_ARGS__)
#define TCALL(varname,...) varname->proc(&(varname->env), __VA_ARGS__)


#define LET_NEW(varname, type) type* varname = NEW(type)


typedef void* Object;

struct Empty_env {
};

struct Some_env {
    /* anything */
};


#define NEW(type) malloc(sizeof(type)) // ç

#define CAST(type,val) (type)(val)
