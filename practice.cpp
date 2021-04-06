#include <stdio.h>

int foo(int a, int* p){
    p = &a;
    printf("p: %p, a:%d\n", p, a);
    return a+1;
}

int main(void){
    int x = 1;
    int* p;
    foo(x, p);
    printf("P: %p\n", p);
    return 0;
}