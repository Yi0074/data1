#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"
#include "polynomial.c"

static void myPrint(char *pn, Polynomial *pp, int testZero, int showDegree) {
    printf("%s(x)=", pn);
    Polynomial_Print(pp);
    if (testZero) {
        printf(", is %sa zero polynomial", (Polynomial_isZero(pp) ? "" : "not "));
    }
    if (showDegree) {
        printf(", degree = %d", Polynomial_Degree(pp));
    }
    printf("\n");
}

int main(int argc, char *argv[]) {    
    int coef, degree;
    int MA = 0, MB = 0;
    Polynomial PA, PB, PC;

    // Input for Polynomial A
    Polynomial_Zero(&PA);
    int i;
    scanf("%d", &MA); // Number of terms in Polynomial A
    for (i = 1; i <= MA; i++) {
        scanf("%d %d", &coef, &degree); // Coefficient and Degree
        Polynomial_Attach(&PA, coef, degree); // Attach terms
    }
    myPrint("A", &PA, NO, YES);

    // Input for Polynomial B
    Polynomial_Zero(&PB);
    scanf("%d", &MB); // Number of terms in Polynomial B
    for (i = 0; i < MB; i++) {
        scanf("%d %d", &coef, &degree); // Coefficient and Degree
        Polynomial_Attach(&PB, coef, degree); // Attach terms
    }
    myPrint("B", &PB, NO, YES);

    // Perform Polynomial Addition
    Polynomial_Add(&PA, &PB, &PC);
    myPrint("add", &PC, NO, YES);

    // Perform Polynomial Multiplication (optional)
    Polynomial_Mul(&PA, &PB, &PC);
    myPrint("mul", &PC, NO, YES);

    return 0;
}
