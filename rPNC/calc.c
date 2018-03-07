#include <stdio.h>
#include <string.h>
#include <math.h>

#define NUMBER '0'
#define IDENTIFIER 'a'

#define NUM_IDENTIFIER 4
#define MAXOP 100

// 함수 :
// 1. 선언
// 2. 정의
// 3. 호출

// 함수 프로토타입 선언
double atof(char s[]);
int getop(char s[]);
void push(double f);
double pop();

int main(void) {
    char s[MAXOP];
    int type;
    double tmp;

    // getop로 받아온 값이 EOF가 될때까지 내부에 있는 코드 반복
    while((type = getop(s)) != EOF) {
        switch (type) {
            // 타입이 숫자인 경우 -> double 타입으로 변환 후 stack에 저장
            case NUMBER:
                push(atof(s));
                break;
            // 타입이 IDENTIFIER인 경우 -> strcmp로 비교를 한뒤 맞는 연산을 시행
            // double sin(double), cos(double), exp(double), log(double), pow(double, double)
            // pow는 뺄셈과 같은 논리로 구현한다.
            case IDENTIFIER:
                if(!strcmp(s, "sin")) {
                    push(sin(pop()));
                } else if(!strcmp(s, "cos")) {
                    push(cos(pop()));
                } else if(!strcmp(s, "exp")) {
                    push(exp(pop()));
                } else if(!strcmp(s, "log")) {
                    push(log(pop()));
                } else if(!strcmp(s, "pow")) {
                    tmp = pop();
                    push(pow(pop(), tmp));
                } else {
                    printf("error : wrong identifier\n");
                }

                break;
            // + 연산자 -> stack에서 두개를 pop한다음 더해서 stack에 저장
            case '+':
                push(pop() + pop());
                break;
            // + 연산자 -> stack에서 두개를 pop한다음 곱해서 stack에 저장
            case '*':
                push(pop() * pop());
                break;
            // - 연산자 -> x - y -> 앞의 값을 뒤에 값으로 뺀다.
            // stack에서 먼저 pop한 값을 임시변수에 저장하고. (y)
            // 다음으로 pop한 값(x)과의 차를 구한 뒤 stack에 저장.
            case '-':
                tmp = pop();
                push(pop() - tmp);
                break;
            // / 연산자 -> x / y -> -와 같은 원리로 진행.
            // 0으로 나누었을때를 대비해서 체크를 한뒤 0.0일경우 에러 출력
            case '/':
                tmp = pop();
                if(tmp != 0.0)
                    push(pop() / tmp);
                else
                    printf("error: zero divisor\n");
                break;
             // 모두 연산한 최종 값 출력 (소수점 8째 자리까지)
             case '\n':
                printf("%.8g\n", pop());
                break;
             default:
                printf("error : unknown command\n");
                break;
         }
     }

     return 0;
 }
