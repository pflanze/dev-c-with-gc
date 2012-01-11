#define ENV(...) { __VA_ARGS__ }

#define __PICK2nd(a,...) __VA_ARGS__

#define DEFINE(Rtype, Name, Env, ...)					\
	struct Name##_env Env;						\
    struct Name##_closure {						\
	Rtype (*proc) (struct Name##_env* env,				\
		       __VA_ARGS__);					\
	struct Name##_env env;						\
    };									\
    struct Name##_closure Name = { Name##_proc,	{} };			\
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
