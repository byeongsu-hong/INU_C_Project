#include <stdio.h>

// #define _TEST

#ifdef _TEST
int getch();
void ungetch(int c);

int main() {
    int c;
    c = getch();
    printf("%c\n", c);
    ungetch(c);
    c = getch();
    printf("%c\n", c);
}
#endif

#define BUFSIZE 100

int bufp = 0;
char buf[BUFSIZE];

// 평소에는 그냥 getchar함수에서 리턴된 값을 반환하다가.
// buffer에 값이 들어왔을 경우에는 들어온 순서대로 buffer에 있는 값을 반환한다.
int getch(void) {
    return((bufp > 0) ? buf[--bufp] : getchar());
}

void ungetch(int c) {
    if(bufp < BUFSIZE)
        buf[bufp++] = c;
    else
        printf("ungetch: too many characters\n");
}
