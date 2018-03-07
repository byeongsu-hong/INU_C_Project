#include <stdio.h>

#define MAXCHAR 1000

static int getLine(char line[], int max);
static int strIndex(char source[], char searchFor[]);

static char pattern[] = "ould";

int main(void) {
    char line[MAXCHAR];
    char pattern[MAXCHAR];
    int found = 0;

    while(getLine(line, MAXCHAR) > 0)
        if(strIndex(line, pattern) >= 0){
            printf("%s", line);
            found++;
        }

    return(found);
}

static int getLine(char s[], int lim) {
    int i, c;

    for(i = 0; (i < lim - 1) && ((c = getchar()) != EOF) && (c != '\n'); i++)
        s[i] = c;
    if(c == '\n') s[i++] = c;
    s[i] = '\0';

    return i;
}

static int strIndex(char s[], char t[]) {
    int i, j, k;

    for(i = 0; s[i] != '\0'; i++) {
        for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++);
        if(k > 0 && t[k] == '\0') return i;
    }

    return -1;
}
