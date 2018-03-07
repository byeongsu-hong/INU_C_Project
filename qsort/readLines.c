#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000

int getLine (char s[], int lim);

int readLines (char *lines[], int max) {
    char line[MAXLEN], *p;
    int len, n;

    n = 0;
    while((len = getLine(line, MAXLEN)) > 0) {
        if((n >= max) || ((p = malloc(len)) == NULL))
            return -1;
        line[len - 1] = '\0';
        strcpy(p, line);
        lines[n++] = p;
    }

    return n;
}

int getLine (char s[], int lim) {
    int i, c;

    for(i = 0; (i < lim - 1) && ((c = getchar()) != EOF) && (c != '\n'); i++)
        s[i] = c;

    if(c == '\n') s[i++] = c;
    s[i] = '\0';

    return i;
}