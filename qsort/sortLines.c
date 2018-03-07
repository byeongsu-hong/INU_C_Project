#include <stdio.h>

#define MAXLINE 5000

int readLines(char *lines[], int max);
void qSort(char *lines[], int left, int right);
void writeLines(char *lines[], int n);

int main(void) {
    char *lines[MAXLINE];
    int n;

    if((n = readLines(lines, MAXLINE)) > 0){
        qSort(lines, 0, n - 1);
        writeLines(lines, n);
    } else {
        printf("error : input too big to sort\n");
        return 1;
    }
}
