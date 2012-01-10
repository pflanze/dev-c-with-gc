
#define BEGIN_PROC(name, ...) void name (__VA_ARGS__) {

#define END_PROC() }


#define CALL(varname,...) varname->proc(&(varname->env), __VA_ARGS__)


#define LET_NEW(varname, type) type* varname = NEW(type)


typedef void* Object;

struct Empty_env {
};

struct Some_env {
    /* anything */
};


#define NEW(type) malloc(sizeof(type)) // ç

