#include <stdio.h>

typedef int (*Compare) (const void *, const void *);

void swap (void *v[], int i, int j);

void qSort (void *v[], int left, int right, Compare cmp) {
    int last, i;

    if(left >= right) return;

    swap(v, left, (left + right) / 2);
    last = left;

    for(i = left + 1; i <= right; i++)
        if(cmp(v[i], v[left]) > 0)
            swap(v, ++last, i);

    swap(v, left, last);
    qSort(v, left, last, cmp);
    qSort(v, last + 1, right, cmp);
}

void swap (void *v[], int i, int j) {
    void *t;

    t = v[i];
    v[i] = v[j];
    v[j] = t;
}
