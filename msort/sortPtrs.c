#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINE 5000

typedef int (* Compare) (const void *, const void *);

int readLines (char *lines[], int max);
void writeLines (char *lines[], int n);
void qSort (void *lines[], int left, int right, Compare cmp);

int lineAscend(const char *s1, const char *s2);
int lineDescend(const char *s1, const char *s2);
int punctAscend(const char *s1, const char *s2);
int punctDescend(const char *s1, const char *s2);

int main (int argc, char *argv[]) {
    char *lines[MAXLINE];
    int c, n, i;
    int opDescend, opPunct;

    opDescend = opPunct = 0;

    while(--argc > 0 && (*++argv)[0] == '-') {
        while((c = *++argv[0]) != 0) {
            switch(c) {
            case 'd':
                opDescend = 1; break;
            case 'p':
                opPunct = 1; break;
            default:
                printf("error: illegal option %c\n", c);
            }
        }
    }

    Compare cmp;

    cmp = (Compare)(opDescend ? 
                        (opPunct ? punctDescend : lineDescend) :
                        (opPunct ? punctAscend : lineAscend));

    if ((n = readLines(lines, MAXLINE)) >= 0) {
        qSort((void **) lines, 0, n - 1, cmp);
        writeLines(lines, n);
    } else {
        printf("error : input too big to sort\n");
        return 1;
    }
}

int lineAscend(const char *s1, const char *s2) {
    int n, m;

    n = strlen(s1);
    m = strlen(s2);

    return n - m;
}

int lineDescend(const char *s1, const char *s2) {
    int n, m;

    n = strlen(s1);
    m = strlen(s2);

    return m - n;
}

int punctAscend(const char *s1, const char *s2) {
    int n, m, i;

    for(i = n = 0; s1[i] != '\0'; i++)
        if(!ispunct(s1[i])) n++;

    for(i = m = 0; s2[i] != '\0'; i++)
        if(!ispunct(s2[i])) m++;

    return m - n;
}

int punctDescend(const char *s1, const char *s2) {
    int n, m, i;

    for(i = n = 0; s1[i] != '\0'; i++)
        if(!ispunct(s1[i])) n++;

    for(i = m = 0; s2[i] != '\0'; i++)
        if(!ispunct(s2[i])) m++;

    return n - m;  
}