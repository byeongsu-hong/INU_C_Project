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
static struct key * search(char *word, struct key tab[], int n);
static struct key * binSearch(char *word, struct key tab[], int n);

int
main(void) {
    char word[MAXCHAR];
    struct key *p;
 
    while(getWord(word, MAXCHAR) != EOF)
        if(isalpha(word[0]))
            if((p = binSearch(word, keytab, NKEYS)) != NULL) p->count++;

    for(p = keytab; p < keytab + NKEYS; p++)
        if(p->count > 0)
            printf("%4d %s\n", p->count, p->word);

    return 0;
}

static struct key *
search(char *word, struct key tab[], int n) {
    struct key *p;
    
    // tab + n 제일 마지막 (n - 1)거 다음 거 포인터
    for(p = tab; p < tab + n; p++)
        if(strcmp(p->word, word) == 0) return p;
    
    // NULL포인터 리턴
    return NULL;
}

static struct key *
binSearch(char *word, struct key tab[], int n) {
    struct key *low = tab;
    struct key *high = &tab[n];
    struct key *mid;
    int cond;
    
    while(low < high) {
        mid = low + (high - low) / 2;
        if((cond = strcmp(word, mid->word)) < 0)
            high = mid;
        else if(cond > 0) low = mid + 1;
        else return mid;
    }

    return NULL;
}