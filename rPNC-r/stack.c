#include <stdio.h>

// #define _TEST

#ifdef _TEST
void push(double f);
double pop();

int main() {
    push(1.0);
    push(2.0);
    push(3.0);
    push(4.0);

    printf("%f\n", pop());
    printf("%f\n", pop());
    printf("%f\n", pop());
    printf("%f\n", pop());
}
#endif

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f) {
    if(sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop() {
    if(sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
