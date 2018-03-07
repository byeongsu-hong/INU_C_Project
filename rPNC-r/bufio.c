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

int getch(void) {
    return((bufp > 0) ? buf[--bufp] : getchar());
}

void ungetch(int c) {
    if(bufp < BUFSIZE)
        buf[bufp++] = c;
    else
        printf("ungetch: too many characters\n");
}
