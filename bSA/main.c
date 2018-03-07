#include <stdio.h>

#define MAXNUMBER 500

// random functions
int rand(void);
void srand(unsigned int seed);

void selectionSort(int v[], int n);
void insertionSort(int v[], int n);
void shellSort(int v[], int n);

int main(void) {
    int v[MAXNUMBER];
    int i;

    // 배열 초기화
    for(i = 0; i < MAXNUMBER; i++)
        v[i] = rand();

//    selectionSort(v, MAXNUMBER);
//    insertionSort(v, MAXNUMBER);
//    shellSort(v, MAXNUMBER);

    for(i = 0; i < MAXNUMBER; i++)
	    printf("%d\n", v[i]);

    return 0;
}

unsigned long int next = 1;

// 랜덤 함수
int rand(void) {
    next = next * 1103515245 + 12345;

    return (unsigned int) (next / 65536) % 32768;
}

void srand(unsigned int seed) {
    next = seed;
}

void swap(int v[], int to, int from) {
    int tmp;

    tmp = v[to];
    v[to] = v[from];
    v[from] = tmp;
}

/* 선택 정렬 */

void selectionSort(int v[], int n) {
    int i, j, max;

    for(i = 0, max = i; i < n; i++) {
        for(j = i + 1; j < n && v[j] > v[max]; j++)
            max = j;
        swap(v, i, max);
    }
}
void insertionSort(int v[], int n) {
    int i, j;

    for(i = 1; i < n; i++)
        for(j = i - 1; j >= 0 && v[j] < v[j + 1]; j--)
            swap(v, j, j + 1);
}

void shellSort(int v[], int n) {
    int i, j, gap;

    for(gap = n / 2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for (j = i - gap; j >= 0 && v[j] < v[j + gap]; j -= gap)
                swap(v, j, j + gap);
}
