#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// #include "/home/NR/numerical_recipes.c/nr.h"
#include "/home/NR/numerical_recipes.c/nrutil.h"
#include "/home/NR/numerical_recipes.c/nrutil.c"
#include "/home/NR/numerical_recipes.c/gauher.c"
#include "/home/NR/numerical_recipes.c/gammln.c"
#include "/home/NR/numerical_recipes.c/gaulag.c"
#include "/home/NR/numerical_recipes.c/gauleg.c"

float fun1(float x) {return 1/(x*sqrt(pow(x,2) - 1));}
float fun2H(float x) {return log(fabsf(x))/2.f;}
float fun2L(float x) {return log(x)*exp(-x*x);}
float fun3(float x) {return sin(2*x)*exp(-2*x);}
float fun(float x){return x * sqrt(pow(x,2) - 1);}


int main(){
    float c_1a = M_PI/3.;
    float c_2a = -0.8700577;
    float c_3a = 2./13.;

    printf("Zadanie 1:\n");
    for(size_t n=2; n<=100; n++){
        float * x = vector(1, n);
        float * w = vector(1, n);
        float x1 = 1.;
        float x2 = 2.;
        // gauleg(float x1,float x2, float x[],float w[],int n);
        gauleg(x1, x2, x, w, n);

        float c_1 = 0.;
        for(int i = 1; i <= n; i++){
            c_1 += w[i]*fun1(x[i]);
        }
        float err = fabsf(c_1 - c_1a);

        // printf("%d: %f\n", n, err);
        printf("%f,", err);
        free_vector(x,1,n);
        free_vector(w,1, n);
    }
    printf("\n\nZadanie 2:\n");
   
    for(size_t n=2; n<=100; n+=2){
        float * x = vector(1, n);
        float * w = vector(1, n);

        // gauher(float x[],float w[],int n)
        gauher(x, w, n);

        float c_2 = 0.;
        for(int i = 1; i <= n; i++){
            c_2 += w[i]*fun2H(x[i]);
        }
        float err = fabsf(c_2 - c_2a);
        
        // printf("%d: %f\n", n, err);
        printf("%f,", err);
        free_vector(x,1,n);
        free_vector(w,1,n);
    }
   
    printf("\n\nPodpunkt b) zadania 2\n");
   
    for (int n = 2; n <= 100; ++n) {
		float* x = vector(1, n);
		float* w = vector(1, n);
		
		float x1 = 0.f;
		float x2 = 5.f;
        
        // gauher(float x[],float w[],int n)
		gauleg(x1, x2, x, w, n);


		float c_2 = 0.0;
		for (int i = 1; i <= n; i++) {
			c_2 += w[i]*fun2L(x[i]);
		}

		float err = fabsf(c_2 - c_2a);

		// printf("%d	%f\n", n, err);
        printf("%f,", err);
		free_vector(x, 1, n);
		free_vector(w, 1, n);
	}

    printf("\n\nZadanie 3:\n");
    for (int n = 2; n <= 10; n++){
        float* x = vector(1, n); 
        float* w = vector(1, n);


        gaulag(x, w, n, 0.0f);

        float c_3 = 0.0;
        for (int i = 1; i <= n; i++){
            c_3 += w[i]*fun3(x[i]);
        }

        float err = fabsf(c_3 - c_3a);
        // printf("%d	%f\n", n, err);
        printf("%f,", err);
		free_vector(x, 1, n);
		free_vector(w, 1, n);


    }
    return 0;
}