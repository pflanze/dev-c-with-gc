#define ENV(...) { __VA_ARGS__ }

#define __PICK2nd(a,...) __VA_ARGS__

#define STATIC static

#define DEFN(Rtype, Name, ...)						\
    struct Name##_env {};						\
    struct Name##_closure {						\
	Rtype (*const proc) (const struct Name##_env* env,		\
			     __VA_ARGS__);				\
	const struct Name##_env env;					\
    };									\
    STATIC Rtype Name##_proc (const struct Name##_env* env, __VA_ARGS__); \
    STATIC const struct Name##_closure Name##_flat = { Name##_proc, {} }; \
    STATIC const struct Name##_closure* const Name = &(Name##_flat);	\
    STATIC Rtype Name##_proc (const struct Name##_env* env, __VA_ARGS__) 

#define IMPLN(Rtype, Name, ...)						\
    STATIC Rtype Name##_proc (const struct Name##_env* env, __VA_ARGS__)

#define DEFCLOSURE(Rtype, Name, Env, ...)				\
    struct Name##_env Env;						\
    struct Name##_closure {						\
	Rtype (*proc) (struct Name##_env* env,				\
		       __VA_ARGS__);					\
	struct Name##_env env;						\
    };									\
    STATIC Rtype Name##_proc (struct Name##_env* env, __VA_ARGS__) 

// #define IMPLCLOSURE  needed?


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
