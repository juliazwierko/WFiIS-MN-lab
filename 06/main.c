#include <stdio.h>
#include <stdlib.h>
#include "math.h"

#define N 5
#define IT_MAX 30

double licz_r(double *a, double *b, int n, double xj);

int main() {
	double x_0, x_1, x_2;
    double R_0, R_1, R_2;

	double* a = malloc((N+1)*sizeof(double));
	double* b = malloc((N+1)*sizeof(double));

	FILE* f = fopen("wyniki.txt", "w");
	fprintf(f, "%s  %s  %s  %s  \n", "|numer zera|", 
                                     "numer iteracji|", 
                                     "x2|", 
                                     "R2|");
	
    
    a[0]=240.,a[1]=-196.,a[2]=-92.,a[3]=33.,a[4]=14.,a[5]=1.;
	for(size_t L = 1; L <= N; L++) {
		size_t n = N-L+1;
		x_0 = 0.0;
		x_1 = 0.1;
		R_0 = licz_r(a, b, n, x_0);
		R_1 = licz_r(a, b, n, x_1);

		for(size_t IT = 1;  IT <= IT_MAX; IT++) {
			x_2 = x_1-R_1*(x_1-x_0)/(R_1-R_0);
			R_2 = licz_r(a, b, n, x_2);
			R_0 = R_1;
			R_1 = R_2;
			x_0 = x_1;
			x_1 = x_2;
        	fprintf(f, "| %d | %d | %g | %g |\n", L, 
                                               IT, 
                                               x_2, 
                                               R_2);
			if(fabs(x_1-x_0) < 10e-7) 
                break;
		}
		for(size_t i = 0; i <= n; i++)
			a[i] = b[i];
	}
	free(a);
	free(b);
    fclose(f);	
	return 0;
}

double licz_r(double *a, double *b, int n, double xj) {
	*(b+n) = 0;
	for(int i = n-1; i >= 0; i--){
		*(b+i) = a[i+1] + (xj*b[i+1]);
    }
	return a[0] + xj*b[0];
}