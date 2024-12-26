#include<stdio.h>
#include<assert.h>
#include"polynomial.h"

int
Polynomial_Print(Polynomial *poly)
{
	int cc = 0;
	int ii;
	if (poly == NULL) return -1;
	for (ii=Polynomial_MaxDegree; ii>=2; ii--) {
		if (poly->coef[ii] != 0) {
			if (cc == 0) {
				printf("%fx^%d", poly->coef[ii], ii);
			} else {
				printf("%+fx^%d", poly->coef[ii], ii);
			}
			cc++;
		}
	}
	if (poly->coef[1] != 0) {
		if (cc == 0) {
			printf("%fx", poly->coef[1]);
		} else {
			printf("%+fx", poly->coef[1]);
		}
		cc++;
	}
	if (poly->coef[0] != 0) {
		if (cc == 0) {
			printf("%f", poly->coef[0]);
		} else {
			printf("%+f", poly->coef[0]);
		}
		cc++;
	}
	if (cc == 0) {
		/* There is no non-zero term. This is a zero polynomial. */
		printf("0");
	}
	return cc;
}

void
Polynomial_Zero(Polynomial *poly)
{
	int ii;
	assert(poly != NULL);
	for (ii=Polynomial_MaxDegree; ii>=0; ii--) {
		poly->coef[ii] = 0;
	}
}

int
Polynomial_isZero(Polynomial *poly)
{
	int ii;
	assert(poly != NULL);
	for (ii=Polynomial_MaxDegree; ii>=0; ii--) {
		if (poly->coef[ii] != 0) {
			return NO;
		}
	}
	return YES;
}

int
Polynomial_Degree(Polynomial *poly)
{
	int ii;
	assert(poly != NULL);
	for (ii=Polynomial_MaxDegree; ii>=0; ii--) {
		if (poly->coef[ii] != 0) {
			return ii;
		}
	}
	return -1;
}

float
Polynomial_Coef(Polynomial *poly, int degree)
{
	assert(poly != NULL);
	assert((0<=degree) && (degree<=Polynomial_MaxDegree));
	return poly->coef[degree];
}

void
Polynomial_Attach(Polynomial *poly, float coef, int degree)
{
	assert(poly != NULL);
	assert((0<=degree) && (degree<=Polynomial_MaxDegree));
	if (coef == 0) return;
    // 如果已存在該 degree 的項目，則直接相加 coef
    poly->coef[degree] += coef;
}

void
Polynomial_Remove(Polynomial *poly, int degree)
{
	assert(poly != NULL);
	assert((0<=degree) && (degree<=Polynomial_MaxDegree));
	poly->coef[degree] = 0;
}

void
Polynomial_Add(Polynomial *pa, Polynomial *pb, Polynomial *pc)
{
	int ii;
	assert(pa != NULL);
	assert(pb != NULL);
	assert(pc != NULL);
	for (ii=0; ii<=Polynomial_MaxDegree; ii++) {
		pc->coef[ii] = pa->coef[ii] + pb->coef[ii];
	}
}

void
Polynomial_Mul(Polynomial *pa, Polynomial *pb, Polynomial *pc)
{
	int ii, jj;
	assert(pa != NULL);
	assert(pb != NULL);
	assert(pc != NULL);
	Polynomial_Zero(pc);
	for (ii=0; ii<=Polynomial_MaxDegree; ii++) {
		for (jj=0; jj<=Polynomial_MaxDegree; jj++) {
			float ef = pa->coef[ii] * pb->coef[jj];
			if (ef != 0) {
				assert((ii+jj)<=Polynomial_MaxDegree);
				pc->coef[ii+jj] += ef;
			}
		}
	}
}
