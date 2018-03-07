#include <stdio.h>
#include <ctype.h>

// #define _TEST

#ifdef _TEST
int getop(char s[]);

int main(void) {
    int type;
    char s[100] = { 0 }; // 쓰레기값 방지

    while((type = getop(s)) != EOF)
        printf("type = '%c', s = \"%s\"\n", type, s);

    return 0;
}
#endif

#define NUMBER '0'
#define IDENTIFIER 'a'

int getch(void);
void ungetch(int c);

int getop(char s[]) {
    int i, c;

    // getch()로 받아온 값이 blank나 tab이면 계속 넘기다가 다른값이 나오면
    while(((s[0] = c = getch()) == ' ') || (c == '\t'));
    // 배열에 null값을 넣고 넘어간다.
    s[1] = '\0';


    i = 0;

    // 숫자가 아니고, 소수점도 아닌경우는 연산자라고 판단하고 리턴한다.
    if(!isdigit(c) && c != '.') {
        if(isalpha(c)) {
            while(isalpha(s[++i] = c = getch()));

            s[i] = '\0';

            if(c != EOF) ungetch(c);

            return IDENTIFIER;
        } else {
            return c;
        }
    }

    // ex) input : 123.456

    // 소수점 위 숫자를 처리한다. (123)
    if(isdigit(c))
        while(isdigit(s[++i] = c = getch()));

    // 소수점 아래 값을 처리한다. (.456)
    if(c == '.')
        while(isdigit(s[++i] = c = getch()));

    // 배열에 null값을 넣고 마무리.
    s[i] = '\0';

    // EOF값이 아닌경우 (개행문자) 다시 standard input에다 넣어버린다.
    if(c != EOF) ungetch(c);

    return NUMBER;
}
