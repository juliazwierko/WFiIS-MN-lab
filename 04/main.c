#include</usr/include/gsl/gsl_eigen.h>

#include <stdio.h>
#include <math.h>

//gcc main.c -lm -lgsl

double delta(int i, int j);

int main(int argc, char** argv){
    double L=10.0;
    double N=1.0;
    double n=200.0;
    
    double del_x=L/(n+1);
    int _alfa;

    gsl_matrix *A = gsl_matrix_calloc(n, n);
    gsl_matrix *B = gsl_matrix_calloc(n, n);
    gsl_vector *x = gsl_vector_calloc(n);
    gsl_vector *Ro = gsl_vector_calloc(n);
    gsl_eigen_gensymmv_workspace *w = gsl_eigen_gensymmv_alloc(n);
    gsl_vector *eval = gsl_vector_calloc(n);
    gsl_matrix *evec = gsl_matrix_calloc(n, n);
    FILE *file1;
    file1 = fopen("1.txt", "w");
    FILE *file2;
    file2 = fopen("2.txt", "w");
    FILE *file3;
    file3 = fopen("3.txt", "w");

    for(unsigned int i = 0; i < n; i++){
        gsl_vector_set(x, i,((-L/2)+del_x*(i+1)));
    }

    for(_alfa = 0; _alfa <= 100; _alfa++){
        fprintf(file1, "%d ", _alfa);

        for(unsigned int i = 0; i < n; i++)
        {
            gsl_vector_set(Ro, i, (1 + 4*_alfa*pow(gsl_vector_get(x, i), 2)));
        }
        for(unsigned int i = 0; i < n; i++)
        {
            for(int j=0; j<n; j++){
                gsl_matrix_set(A, i, j, (double)((-delta(i, j + 1) + 2 * delta(i, j) - delta(i, j-1)) / pow(del_x, 2)));
                gsl_matrix_set(B,i,j, (gsl_vector_get(Ro,i)*delta(i, j))/N);
            }
        } 
        gsl_eigen_gensymmv(A, B, eval, evec, w);
        gsl_eigen_gensymmv_sort(eval, evec, GSL_EIGEN_SORT_ABS_ASC);

        
        for (unsigned int i = 0; i < 6; i++){
            fprintf(file1, "%f ", sqrt(gsl_vector_get(eval, i)) );
        }
        fprintf(file1, "\n");

        if (_alfa == 100){
            for (unsigned int i = 0; i < n; i++){
                fprintf(file3, "%f ", gsl_vector_get(x,i));
                 for (int j = 0; j < 6; j++){
                    fprintf(file3, "%f ", gsl_matrix_get(evec, i, j));
                }
                fprintf(file3, "\n");
            }
        }
        if (_alfa == 0){
            for (unsigned int i = 0; i < n; i++){
                fprintf(file2, "%f ", gsl_vector_get(x,i));
                for (unsigned int j = 0; j < 6; j++){
                    fprintf(file2, "%f ", gsl_matrix_get(evec, i, j));
                }
                fprintf(file2, "\n");
            }
        }      
    }
    gsl_vector_free(eval);
    gsl_matrix_free(evec);

    fclose(file1);
    fclose(file2);
    fclose(file3);
    return 0;
}

double delta(int i, int j){
    double delta = 0.;
    if(i==j){
        delta=1;
    }
    else{ 
        delta=0;
    } 
    return delta;
}