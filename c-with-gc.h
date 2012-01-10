#define ENV(...) { __VA_ARGS__ }

#define BEGIN_DEFN(rtype, name, arg, env)		\
    struct name##_env env				\
    struct name##_closure {				\
    						\
    }						\
						\
    rtype name (__VA_ARGS__) {

#define END_DEFN() }


#define CALL(varname,...) varname->proc(&(varname->env), __VA_ARGS__)


#define LET_NEW(varname, type) type* varname = NEW(type)


typedef void* Object;

struct Empty_env {
};

struct Some_env {
    /* anything */
};


#define NEW(type) malloc(sizeof(type)) // ç

#define CAST(type,val) (type)(val)
