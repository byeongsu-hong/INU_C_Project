#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int c);

int
getWord(char *word, int lim) {
    // word 배열의 첫번째 위치를 w에다 넣음
    char *w = word;
    int c;

    // 공백 제거
    while(isspace(c = getch()));
    if(c != EOF) *w++ = c;
    if(!isalpha(c)) {
        *w = '\0';
        return c;
    }
    
    for( ; --lim > 0; w++)
        if(!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    
    *w = '\0';

    return word[0];
}