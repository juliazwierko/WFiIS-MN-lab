#include <stdio.h>
#include "/home/NR/numerical_recipes.c/nrutil.h"
#include "/home/NR/numerical_recipes.c/nrutil.c"
#include "/home/NR/numerical_recipes.c/gaussj.c"
#include "math.h"
#define x_min -5.0
#define x_max 5.0

float fun1(float x) {return 1/(1+x*x);}
float fun2(float x) {return cos(2*x);}
float sklejka(int i, float x, float h);

int main(){
	int n1[4] = {5,6,10,20};
	int n2[3] = {6,7,14};
    float eps = 0.02;
    float h, tmp, suma;
	int n;
	FILE *pierwsza_funkcja;
	FILE *pierwsza_punkty;
    FILE *druga_funkcja;
	FILE *druga_punkty;
	pierwsza_funkcja = fopen("pierwsza_funkcja.txt","w");
	pierwsza_punkty = fopen("pierwsza_punkty.txt","w");
	druga_funkcja = fopen("druga_funkcja.txt","w");
	druga_punkty = fopen("druga_punkty.txt","w");

    //FUN1
	for(int licznik1 = 0; licznik1<4; ++licznik1)
	{
		n = n1[licznik1];
		h = (x_max-x_min)/(n-1);
		for(int i = 0; i<n; ++i){
			tmp = x_min+i*h;
			fprintf(pierwsza_punkty, "%f\t%f\n",tmp,fun1(tmp));
		}
		fprintf(pierwsza_punkty, "\n\n");
        
		float **vec = matrix(1, n, 1, 1);
		float **vec2 = matrix(1, n+2, 1, 1);
		float **A = matrix(1, n, 1, n);

		for (int i = 1; i < n+1; ++i){
			for (int j = 1; j < n+1; ++j){
				A[i][j] = 0;
			}
			vec[i][1] = 0;
		}
		for(int i = 1; i<n+1; ++i){
			A[i][i] = 4;
		}
		A[1][2] = A[n][n-1] = 2;
		for(int i = 2; i<n; ++i)
		{
			A[i][i-1] = A[i][i+1] = 1;
		}   
		float alfa = (fun1(x_min+eps) - fun1(x_min-eps))/(2*eps);
		float beta = (fun1(x_max+eps) - fun1(x_max-eps))/(2*eps);

		vec[1][1] = fun1(x_min) + h/3*alfa;
		for(int i = 1; i<n-1; ++i)
		{
			vec[i+1][1] = fun1(x_min+i*h);
		}
		vec[n][1] = fun1(x_max) - h/3*beta;
		gaussj(A, n, vec, 1);

		for(int i = 1; i<n+1; ++i)
		{
			vec2[i+1][1]=vec[i][1];
		}
		vec2[1][1] = vec2[3][1] - h/3*alfa;
		vec2[n+2][1] = vec2[n][1] + h/3*beta;
	
        //Interpolacja
		for(float x = x_min; x<=x_max; x+=eps)
		{
			suma = 0; 
			for(int i = 0; i<=n+1; ++i)
			{
				suma += vec2[i+1][1] * sklejka(i,x,h);
			}
			fprintf(pierwsza_funkcja, "%f\t%f\n", x, suma);
		}
		fprintf(pierwsza_funkcja, "\n\n");
		free_matrix(vec2, 1, n, 1, 1);
		free_matrix(vec, 1, n, 1, 1);
		free_matrix(A, 1, n, 1, n);
	}
	fclose(pierwsza_funkcja);
	fclose(pierwsza_punkty);	

    
    //FUN2 to samo jak dla F1
	for(int licznik1 = 0; licznik1<3; ++licznik1)
	{
		n = n2[licznik1];
		h = (x_max-x_min)/(n-1);

		for(int i = 0; i<n; ++i)
		{
			tmp = x_min+i*h;
			fprintf(druga_punkty, "%f\t%f\n",tmp,fun2(tmp));
		}		
		fprintf(druga_punkty, "\n\n");
		float **vec = matrix(1, n, 1, 1);
		float **vec2 = matrix(1, n+2, 1, 1);
		float **A = matrix(1, n, 1, n);

		for (int i = 1; i < n+1; ++i){
			for (int j = 1; j < n+1; ++j){
				A[i][j] = 0;
			}
			vec[i][1] = 0;
		}

		for(int i = 1; i<n+1; ++i){
			A[i][i] = 4;
		}
		A[1][2] = A[n][n-1] = 2;
		for(int i = 2; i<n; ++i){
			A[i][i-1] = A[i][i+1] = 1;
		}

		float alfa = (fun2(x_min+eps) - fun2(x_min-eps))/(2*eps);
		float beta = (fun2(x_max+eps) - fun2(x_max-eps))/(2*eps);

		vec[1][1] = fun2(x_min) + h/3*alfa;
		for(int i = 1; i<n-1; ++i){
			vec[i+1][1] = fun2(x_min+i*h);
		}
		vec[n][1] = fun2(x_max) - h/3*beta;
		gaussj(A, n, vec, 1);
		for(int i = 1; i<n+1; ++i)
		{
			vec2[i+1][1]=vec[i][1];
		}
		vec2[1][1] = vec2[3][1] - h/3*alfa;
		vec2[n+2][1] = vec2[n][1] + h/3*beta;

		for(float x = x_min; x<=x_max; x+=eps){
			suma = 0;   
			for(int i = 0; i<=n+1; ++i){
				suma += vec2[i+1][1] * sklejka(i,x,h);
			}
			fprintf(druga_funkcja, "%f\t%f\n", x, suma);
		}
		fprintf(druga_funkcja, "\n\n");
		free_matrix(vec2, 1, n, 1, 1);
		free_matrix(vec, 1, n, 1, 1);
		free_matrix(A, 1, n, 1, n);
	}
	fclose(druga_funkcja);
	fclose(druga_punkty);
    return 0;
}

float sklejka(int i, float x, float h){
	float x_i = x_min + (i-1)*h;
	if(x >= x_i-2*h && x < x_i-h) 
        return 1/(h*h*h)*(x-(x_i-2*h))*(x-(x_i-2*h))*(x-(x_i-2*h));
	if(x >= x_i-h && x<x_i) 
        return 1/(h*h*h)*(h*h*h + 3*h*h*(x-(x_i-h)) + 3*h*(x-(x_i-h))*(x-(x_i-h)) - 3*(x-(x_i-h))*(x-(x_i-h))*(x-(x_i-h)));
	if(x >= x_i && x<x_i+h) 
        return 1/(h*h*h)*(h*h*h + 3*h*h*(x_i+h-x) + 3*h*(x_i+h-x)*(x_i+h-x) - 3*(x_i+h-x)*(x_i+h-x)*(x_i+h-x));
	if(x >= x_i+h && x<x_i+2*h) 
        return 1/(h*h*h)*(x_i+2*h-x)*(x_i+2*h-x)*(x_i+2*h-x);
	if(x < x_min-3*h && x > x_max+3*h) 
        return 0;
    else
        return 0;
}