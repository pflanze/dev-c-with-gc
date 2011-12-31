#include "c-with-gc.h"

#include <stdio.h>

BEGIN_PROC(f, int a, int b)
printf("some %i\n", a+b);
END_PROC()

int main () {
    f(10,11);
    return 0;
}
