/* created by Frostornge
   2017.04.05 */

#include <stdio.h>

#define TABSIZE 8

int entab();
int detab();

int main(void) {

    /* flag that informs this is turn of entabLine function */
    int isEntabTurn = 0;

    int isEOF = 0;

    while(isEOF != 1) {
        if(isEntabTurn == 0) {
            isEOF = entab();
            isEntabTurn = 1;
        } else {
            isEOF = detab();
            isEntabTurn = 0;
        }
    }

    return 0;
}

int entab() {
    int c, readButnotPrintedBlanks, currentPrintPosition, positionAfterPrintAllBlanks;

    currentPrintPosition = readButnotPrintedBlanks = 0;

    while((c = getchar()) != EOF && c != '\n') {
        if (c == ' ') {
            readButnotPrintedBlanks++;

        } else if (readButnotPrintedBlanks == 0) {
            putchar(c);1
            currentPrintPosition++;
        
        } else if (readButnotPrintedBlanks == 1) {
            putchar(' ');
            putchar(c);
            currentPrintPosition += 2;
            readButnotPrintedBlanks = 0;
        
        } else {
            positionAfterPrintAllBlanks = x + readButnotPrintedBlanks;
        
            while (currentPrintPosition / TABSIZE != positionAfterPrintAllBlanks / TABSIZE) {
                putchar('\t');
                currentPrintPosition += (TABSIZE - (currentPrintPosition % TABSIZE));
            }

            readButnotPrintedBlanks = positionAfterPrintAllBlanks - currentPrintPosition;
        
            while (readButnotPrintedBlanks > 0) {
                putchar(' ');
                readButnotPrintedBlanks--;
            }
        
            putchar(c);
        
            currentPrintPosition = positionAfterPrintAllBlanks + 1;
        }
    }

    if(c == EOF) {
        return 1;
    } else {
        putchar('\n');
        return 0;
    }
}

int detab() {
    int c, currentPrintPosition, positionNextTabStop, indexVariable;

    x = 0;

    while((c = getchar()) != EOF && c != '\n') {
        if(c == '\t') {
            positionNextTabStop = TABSIZE - (currentPrintPosition % TABSIZE);

            for(indexVariable = 0; indexVariable < positionNextTabStop; indexVariable++) {
                putchar(' ');
            }

            currentPrintPosition += positionNextTabStop;
        } else {
            putchar(c);
            currentPrintPosition++;
        }
    }

    if(c == EOF) {
        return 1;
    } else {
        putchar('\n');
        return 0;
    }
}