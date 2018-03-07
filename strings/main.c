#include <stdio.h>

#define MAXLINE 1000

#define TRUE 1
#define FALSE 0

void process(char in[], char rm[]);
char toLower(char a);
int getLine(char s[], int lim);
void wordCopy(char to[], char from[]);

int main() {

    char inStr[MAXLINE] = { 0 };
    char rmStr[MAXLINE] = { 0 };

    printf("Input String : ");

    if(getLine(inStr, MAXLINE) > 0) {
        printf("Characters to be removed : ");

        if(getLine(rmStr, MAXLINE) > 0) {
            process(inStr, rmStr);
        }
    }

    printf(inStr);

    return 0;
}

void process(char in[], char rm[]) {
    int change;
    int i, j, k;

    for(i = k = 0; in[i] != '\0'; i++) {
        change = FALSE;

        for(j = 0; rm[j] != '\0'; j++) {
            if(toLower(in[i]) == toLower(rm[j])) {
                change = TRUE;
            }
        }

        if(change == FALSE) {
            in[k++] = in[i];
        }
    }

    in[k] = '\0';
}

char toLower(char a) {
    if(a >= 'A' && a <= 'Z')
        return (char) (a + 'a' - 'A');
    else
        return a;
}

int getLine(char line[], int limit) {
    int c, i;

    for(i = 0; (i < limit - 1) && (c = getchar()) != EOF && c != '\n'; i++) {
        line[i] = (char)c;
    }

    if(c == '\n') {
        line[i++] = '\0';
    }

    return i;
}