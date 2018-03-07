#include <stdio.h>
#include <string.h>

void swap(char *v[], int i, int j);
int cmp(char *s1, char *s2);

void qSort (char *v[], int left, int right) {
    int last, i;

    if(left >= right) return;

    swap(v, left, (left + right) / 2);
    last = left;

    for(i = left + 1; i <= right; i++)
        if(strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);

    swap(v, left, last);
    qSort(v, left, last);
    qSort(v, last + 1, right);
}

void swap(char *v[], int i, int j) {
    char *t;

    t = v[i];
    v[i] = v[j];
    v[j] = t;
}

int cmp(char *s1, char *s2) {
    int i, n, m;

    for(i = n = 0; s1[i] != '\0'; i++)
        n += s1[i];

    for(i = m = 0; s2[i] != '\0'; i++)
        m += s2[i];

    return n - m;
}
