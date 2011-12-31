
#define BEGIN_PROC(name, ...) void name (__VA_ARGS__) {

#define END_PROC() }


#define CALL(name,...) name(__VA_ARGS__);
//^ to be made tail . hm only  tail calls ?

// hm inline lambdas ndgehgl  hm   eh hm   wl . ? .

// ach weil gar nd nested defs geht at all  muss ich, lambdas ausseneben,
// wl manual  hoisting   hll  ,
// udn dnn alloc von closr js t ussn  f  chmn,innen.


