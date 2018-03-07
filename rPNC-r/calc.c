#include <stdio.h>
#include <string.h>
#include <math.h>

#define NUMBER '0'
#define IDENTIFIER 'a'

#define NUM_IDENTIFIER 4
#define MAXOP 100


double atof(char s[]);
int getop(char s[]);
void push(double f);
double pop();

int main(void) {
    char s[MAXOP] = { 0 };
    int type;
    double tmp;

    while((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
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
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                tmp = pop();
                push(pop() - tmp);
                break;
            case '/':
                tmp = pop();
                if(tmp != 0.0)
                    push(pop() / tmp);
                else
                    printf("error: zero divisor\n");
                break;
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
