#include <stdio.h>
#include <ctype.h>
#include <string.h>

// #define _TEST

#ifdef _TEST
int getop(char s[]);

int main(void) {
    int type;

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

    while(((s[0] = c = getch()) == ' ') || (c == '\t'));

    s[1] = '\0';

    i = 0;

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


    if(isdigit(c))
        while(isdigit(s[++i] = c = getch()));

    if(c == '.')
        while(isdigit(s[++i] = c = getch()));

    s[i] = '\0';

    if(c != EOF) ungetch(c);

    return NUMBER;
}
