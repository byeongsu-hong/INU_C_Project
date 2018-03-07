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

// stack에 값을 넣는다.
// 만약 stack이 꽉 찼으면 에러를 출력한다.
void push(double f) {
    if(sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

// stack에 있는 맨 위 값을 리턴한다
// 만약 stack에 아무런 값이 없으면 에러를 출력한다.
double pop() {
    if(sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
