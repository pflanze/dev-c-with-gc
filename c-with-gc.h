#define ENV(...) { __VA_ARGS__ }

#define __PICK2nd(a,...) __VA_ARGS__

#define STATIC static

#define DEFINE(Rtype, Name, Env, ...)					\
    struct Name##_env Env;						\
    struct Name##_closure {						\
	Rtype (*proc) (struct Name##_env* env,				\
		       __VA_ARGS__);					\
	struct Name##_env env;						\
    };									\
    STATIC Rtype Name##_proc (struct Name##_env* env, __VA_ARGS__);	\
    struct Name##_closure Name##_flat = { Name##_proc,	{} };		\
    STATIC struct Name##_closure* Name = &(Name##_flat);		\
    STATIC Rtype Name##_proc (struct Name##_env* env, __VA_ARGS__) 


#define CALL(Name,...) Name->proc(&(Name->env), __VA_ARGS__)
#define TCALL(Name,...) Name->proc(&(Name->env), __VA_ARGS__)
#define SELFCALL(Name,...) Name##_proc(env, __VA_ARGS__)


#define LET_NEW(varname, type) type* varname = NEW(type)


typedef void* Object;

struct Empty_env {
};

struct Some_env {
    /* anything */
};


#define NEW(type) malloc(sizeof(type)) // ç

#define CAST(type,val) (type)(val)
