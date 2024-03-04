#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "nrutil.h"
#include "nrutil.c"
#include "ludcmp.c" 
#include "lubksb.c"

// #include "/home/NR/numerical_recipes.c/nrutil.h"
// #include "/home/NR/numerical_recipes.c/nrutil.c"
// #include "/home/NR/numerical_recipes.c/gaussj.c"

// * tworzenie archiwum: tar -czvf nazwa.tar.gz zad/
//   np. tar -czvf lab01.tar.gz lab01/


#define N 4 

void print_matrix(float **M, int size)
{
    for(int i=1; i<=size; ++i)
    {
        for(int j=1; j<=size; ++j)
        {
            printf("%10g ", M[i][j]);
        }
        printf("\n");
    }  
    printf("\n");
}

void print_matrix_to_file(float **M, int size, FILE *pt)
{
  for(int i=1; i<=size; ++i)
  {
        for(int j=1; j<=size; ++j)
        {
            fprintf(pt, "%15g ", M[i][j]);
        }
        fprintf(pt, "\n");
    }  
    fprintf(pt, "\n");
}

void copy_matrix(float **M, float **copy, int size)
{
    for(int i=1; i<=size; ++i)
    {
        for(int j=1; j<=size; ++j)
        {
            copy[i][j] = M[i][j];
        }
    }  
}

void product(float **X, float **Y, float **Z, int size)
{
    for (int i=1; i<=size; ++i)
    {
        for (int j=1; j<=size; ++j)
        {
            Z[i][j]= 0.;
            for (int k=1; k<=size; ++k)
                Z[i][j]+= X[i][k] * Y[k][j]; 
        }
    }
}  

//norma macierzy
float norm(float **M, int size)
{
    float max_m = M[1][1] >= 0 ? M[1][1] : -M[1][1];
    for(int i=1; i<=N; ++i)
    {
        for(int j=1; j<=N; ++j)
        {
            float temp_m = M[i][j]  >= 0 ? M[i][j] : -M[i][j];
            max_m = temp_m > max_m ? temp_m : max_m;
        }
    }
    return max_m;
}

void transpose(float **M)
{
    for (int i=1; i<=N-1; ++i)
    {
        for(int j=i+1; j<=N; ++j)
        {
            float temp = M[i][j];
            M[i][j] = M[j][i];
            M[j][i] = temp; 
        }
    }
}

int main(void)
{
	float **A, **A_copy, **product_A;
    
	A = matrix(1, N, 1, N);
    A_copy = matrix(1, N, 1, N);
    product_A = matrix(1, N, 1, N);

    int *indx;
    float d;
    float f = 1.;

    //wypelnienie macierzy 
    //wzor a[i][j]=1/i+j+0, 0 przyjelam. bo korzystam z NR
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=N; ++j){
            float suma = i+j;
            A[i][j] = f/(suma);
        }
    }

    FILE *fp = fopen("out.txt", "w");
    copy_matrix(A, A_copy, N);

    printf("A:\n");
    print_matrix(A, N);

    indx = ivector(1,N);

    //Rozklad LU
    ludcmp(A_copy, N, indx, &d);

    printf("Rozkład LU macierzy A:\n");
    print_matrix(A_copy, N);

    float **a = matrix(1, N, 1, N); 

    for(int i=1; i<=N; ++i)
    {
        for(int j=1; j<=N; ++j)
        {
            a[i][j] = i==j ? 1. : 0.;
        }
    }
    
    for(int i=1; i<=N; i++){
        lubksb(A_copy, N, indx, a[i]);  
    }

    /*  Lubksb zwraca kolumny odwróconej macierzy a nie wiersze.
        Aby otrzymać macierz a, która jest odwrotna do macierzy odpowiednio A,
        należy transponować otrzymana macierz a
    */ 
    transpose(a);

    printf("A^(-1):\n");
    print_matrix(a, N);

    float max_A = norm(A, N);
    float max_a = norm(a, N);

    fprintf(fp, "Norma macierzy A: %g \n", max_A);
    fprintf(fp, "Norma macierzy A^(-1): %g \n", max_a);
    fprintf(fp, "Wskaźnik uwarunkowania macierzy A (norma A * norma A^(-1)): %g\n\n", max_A * max_a);

    fprintf(fp, "Iloczyn macierzy A*A^(-1):\n");
    product(A, a, product_A, N);
    print_matrix_to_file(product_A, N, fp);

    //	Zwolnienie pamieci
	free_matrix(A, 1, N, 1, N);
    free_matrix(a, 1, N, 1, N);

    free_ivector(indx, 1, N);
    free_matrix(A_copy, 1, N, 1, N);
    free_matrix(product_A, 1, N, 1, N);
    fclose(fp);
	return 0;
}
