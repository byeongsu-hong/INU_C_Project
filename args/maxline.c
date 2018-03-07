#include    <stdio.h>

#define     MAXLINE     1000

int     getLine(char line[], int maxline);
void    copy(char to [], char from []);

int
main()
{
    int     len;
    int     max1, max2;
    char    line[MAXLINE];
    char    longest1[MAXLINE], longest2[MAXLINE];
    max1 = max2 = 0;
    while((len = getLine(line, MAXLINE)) > 0)
        if(len > max1) {
            max1 = len;
            max2 = max1;
            copy(longest2, longest1);
            copy(longest1, line);
        } else if(len > max2) {
            max2 = len;
            copy(longest2, line);
        }
    if(max1 > 0) printf("%s", longest1);
    if(max2 > 0) printf("%s", longest2);
    return 0;
}

int     
getLine(char s[], int lim)
{
    int     c, i;
    for (i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if(c == '\n'){
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

void    
copy(char to[], char from[])
{
    int     i;
    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}
