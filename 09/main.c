#include <stdio.h>
#include "stdlib.h"

#include "nrutil.h"
#include "nrutil.c"
#include "gaussj.c"

#include "math.h"
#include "time.h"

// gcc main.c -lm -lgsl -lgslcblas - kompilacja 

////////////////////////////////////////////////////////////////////// 
float g(float x, float x_0, float sigma, float a0, float a1, float a2){return exp(a0 + a1*x+a2*pow(x,2));}
float g2(float x, float x_0, float sigma, float a0, float a1, float a2){
	float X = rand()/(RAND_MAX+1.0);
	float alfa = 0.1;
	float delta = alfa *(X - 0.5);
	return g(x,x_0,sigma,a0,a1,a2)*(1+delta);
}
float G_x(float x, float rozm, float ** b){
	float suma = 0;
	for(size_t i = 1; i<=rozm; ++i){
		suma+= b[i][1]*pow(x,i-1);
	}
	return exp(suma);
}
float G2_x(float x, float rozm, float ** b){	float suma = 0;
	for(size_t i = 1; i<=rozm; ++i){suma+= b[i][1]*pow(x,i-1);}
	return exp(suma);
}
float f(float x, float x_0, float sigma, float a0, float a1, float a2){return log(g(x,x_0,sigma,a0,a1,a2));}
float f2(float x, float x_0, float sigma, float a0, float a1, float a2){return log(g2(x,x_0,sigma,a0,a1,a2));}
////////////////////////////////////////////////////////////////////// 
void WypiszMacierz(float ** A, int rozm){
	printf("-> MAcierz:\n");
	for(size_t i = 1; i<=rozm; ++i){
		for(size_t j = 1; j<=rozm; ++j){printf("%f\t", A[i][j]);}
		printf("\n");
	}
    printf("\n");
}
void WypiszWektor(float **vec, int rozm){
	printf("WEKTOR:\n");
	for(size_t i = 1; i<=rozm; ++i){
		printf("%f\n", vec[i][1]);
	}
	printf("\n");
}
//wspolczynnik b_i
void Wypisz_b(float ** vec, int rozm){
	for(size_t i = 1; i<=rozm; ++i){
		printf("b_%d = %.14f\t", i, vec[i][1]);
	}
	printf("\n");
}




////////////////////////////////////////////////////////////////////// 
int main()
{
	srand(time(NULL));
	float x_0 = 2;
    float sigma = 4;
    float L = x_0 - 3*sigma;
    float R = x_0 + 3* sigma;
	float a0 = -pow(x_0,2)/(2*pow(sigma,2));
    float a1 = x_0/pow(sigma,2);
    float a2 = -1/(2*pow(sigma,2));
	int n_do_rozwazania[] = {11,21,51,101};
	int n, m = 4;

	FILE *file_1;
	FILE *file_2;
	file_1 = fopen("funckja_g.txt","w");
	file_2 = fopen("aproksymacja_funckji_G.txt","w");

	printf("-> Funkcja g\n");
	printf("a_0 = %f\t\ta_1 = %f\t\ta_2 = %f\n", 
            a0,a1,a2);	

	for(int l1 = 0; l1<sizeof(n_do_rozwazania)/sizeof(n_do_rozwazania[0]); ++l1)	{
		n = n_do_rozwazania[l1];
		if(n!=51) printf("n = %d\n", n);

		float h = (R-L)/(n-1);
		// printf("h = %f\n", h);
		for(int i = 1; i<=n; ++i){
			float tmp = L+h*(i-1);
			printf("x_%d = %f,\tf(x_%d) = %f\n", i, tmp, i, f(tmp,x_0,sigma,a0,a1,a2));
		}
		
        // macierz i wektor, zerowanie macierzy i wektora, wypelnianie macierzy
		float **r = matrix(1, m, 1, 1);
		float **G = matrix(1, m, 1, m);
		for (int i = 1; i<=m; ++i){
			for (int j = 1; j<=m; ++j){G[i][j] = 0;}
			r[i][1] = 0;
		}
		float suma;
		for(int i = 1; i<=m; ++i){
			for(int k = 1; k<=m; ++k){
				suma = 0;
				for(float x = L; x<=R; x+=h){suma += pow(x,i+k-2);}
				G[i][k] = suma;
		    }
		}
        // wypelnianie wektora
		for(int k = 1; k<=m; ++k){
			suma = 0;
			for(float x = L; x<=R; x+=h)
			{
				suma += f(x,x_0,sigma,a0,a1,a2) * pow(x,k-1);
			}
			r[k][1] = suma;
		}

		//WypiszMacierz(G,m);
		//WypiszWektor(r,m);		
		gaussj(G, m, r, 1);
		if(n!=51) Wypisz_b(r,m); //wspolczynnik b
        // g a G
		if(n==11 || n==101)
		{
			for(float x = L; x<=R; x+=0.01)
			{
				fprintf(file_1, "%f\t%f\n", x, g(x,x_0,sigma,a0,a1,a2));
			}
			fprintf(file_1, "\n\n");
			
			for(float x = L; x<=R; x+=0.01)
			{
				fprintf(file_2, "%f\t%f\n", x, G_x(x,m,r));
			}
			fprintf(file_2, "\n\n");	
		}
		free_matrix(r, 1, m, 1, 1);
		free_matrix(G, 1, m, 1, m);
	}
	fclose(file_1);
	fclose(file_2);

///////////////////////////////////////////////////////////////////////////////////////////////////////	

	file_1 = fopen("funckja_g2.txt","w");
	file_2 = fopen("aproksymacja_funckji_G2.txt","w");	
	printf("\n\n-> funckja g2\n");
	printf("a_0 = %f\t\ta_1 = %f\t\ta_2 = %f\n", a0,a1,a2);
	for(int l1 = 0; l1<sizeof(n_do_rozwazania)/sizeof(n_do_rozwazania[0]); ++l1)
	{
		n = n_do_rozwazania[l1];
		printf("n = %d\n", n);

		float h = (R-L)/(n-1);
		for(int i = 1; i<=n; ++i)
		{
			float tmp = L+h*(i-1);

		}
		
		float **r = matrix(1, m, 1, 1);
		float **G = matrix(1, m, 1, m);
		for (int i = 1; i<=m; ++i)
		{
			for (int j = 1; j<=m; ++j)
			{
				G[i][j] = 0;
			}
			r[i][1] = 0;
		}
		float suma;
		for(int i = 1; i<=m; ++i)
		{
			for(int k = 1; k<=m; ++k)
			{
				suma = 0;
				for(float x = L; x<=R; x+=h)
				{
					suma += pow(x,i+k-2);
				}
				G[i][k] = suma;
			}
		}
		for(int k = 1; k<=m; ++k)
		{
			suma = 0;
			for(float x = L; x<=R; x+=h)
			{
				suma += f2(x,x_0,sigma,a0,a1,a2) * pow(x,k-1);
			}
			r[k][1] = suma;
		}
		gaussj(G, m, r, 1);
		Wypisz_b(r,m);
		if(n==11 || n==101)
		{
			for(float x = L; x<=R; x+=h)
			{
				fprintf(file_1, "%f\t%f\n", x, g2(x,x_0,sigma,a0,a1,a2));
			}
			fprintf(file_1, "\n\n");
		
			for(float x = L; x<=R; x+=0.01)
			{
				fprintf(file_2, "%f\t%f\n", x, G2_x(x,m,r));
			}
			fprintf(file_2, "\n\n");
        }
		free_matrix(r, 1, m, 1, 1);
		free_matrix(G, 1, m, 1, m);
	}
	fclose(file_1);
	fclose(file_2);

	return 0;
}
