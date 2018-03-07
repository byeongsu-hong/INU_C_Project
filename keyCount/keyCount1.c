#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXCHAR 100

struct key {
    char *word;
    int count;
} keytab[] = {
    { "auto",  0 }, 
    { "break",  0 }, 
    { "case",  0 }, 
    { "char",  0 }, 
    { "const",  0 }, 
    { "continue",  0 }, 
    { "default",  0 }, 
    { "do",  0 }, 
    { "double",  0 }, 
    { "else",  0 }, 
    { "enum",  0 }, 
    { "extern",  0 }, 
    { "float",  0 }, 
    { "for",  0 }, 
    { "goto",  0 }, 
    { "if",  0 }, 
    { "int",  0 }, 
    { "long",  0 }, 
    { "register",  0 }, 
    { "return",  0 }, 
    { "short",  0 }, 
    { "signed",  0 }, 
    { "sizeof",  0 }, 
    { "static",  0 }, 
    { "struct",  0 }, 
    { "switch",  0 }, 
    { "typedef",  0 }, 
    { "union",  0 }, 
    { "unsigned",  0 }, 
    { "void",  0 }, 
    { "volatile",  0 }, 
    { "while",  0 }
};

#define NKEYS (sizeof keytab / sizeof(struct key))

int getWord(char *word, int lim);
static int search(char *word, struct key tab[], int n);
static int binSearch(char *word, struct key tab[], int n);

int
main(void) {
    char word[MAXCHAR];
    int n;
 
    while(getWord(word, MAXCHAR) != EOF)
        if(isalpha(word[0]))
            if((n = binSearch(word, keytab, NKEYS)) >= 0) keytab[n].count++;

    for(n = 0; n < NKEYS; n++)
        if(keytab[n].count > 0)
            printf("%4d %s\n", keytab[n].count, keytab[n].word);

    return 0;
}

static int
search(char *word, struct key tab[], int n) {
    int i;
    
    for(i = 0; i < n; i++)
        if(strcmp(tab[i].word, word) == 0) return i;

    return -1;
}

static int
binSearch(char *word, struct key tab[], int n) {
    int low, high, mid;
    int cond;

    low = 0;
    high = n - 1;
    while(low <= high) {
        mid = (low + high) / 2;
        if((cond = strcmp(word, tab[mid].word)) < 0) 
            high = mid - 1;
        else if(cond > 0) low = mid + 1;
        else return mid;
    }

    return -1;
}