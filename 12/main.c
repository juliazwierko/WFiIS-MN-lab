#include <stdio.h>
#include "math.h"

#define dolna_granica 0.0
#define gorna_granica M_PI


double fact(int n); //silnia
double I_j(int j, int k, int m);
double fun(int index, int m, int k, double h); //funckja podcalkowa [ f(x) = x^m * sin(kx) ]

int main(int argc, char** argv){
	FILE *zadanie1;
    FILE *zadanie2;
	zadanie1 = fopen("zadanie1.txt","w");
	zadanie2 = fopen("zadanie2.txt","w");

    ////////////////// Zadanie 1 ////////////////////////

	double I;
	int m_tab[]={0,1,5};
    int k_tab[]={1,1,5};
    int m;
    int k; 

    int size = sizeof(m_tab)/sizeof(m_tab[0]);
    int length = 30;

	for(int iteracja = 0; iteracja<size; ++iteracja)
	{
		m = m_tab[iteracja];
		k = k_tab[iteracja];
        // fprintf(zadanie1,"Parametry: m = %d, k = %d\n",m, k);

		// Rozwijecie w szereg Taylora
		for(size_t l=0; l<=length; l++){
			I = 0;
			for(size_t j=0; j<=l; ++j)
			{
				I += I_j(j,k,m);
			}
			fprintf(zadanie1,"%d\t%lf\n",l,I);
		}
    

        ////////////////// Zadanie 2 ////////////////////////


		int n_tab[] = {11,21,51,101,201};
        int size2 = sizeof(n_tab)/sizeof(n_tab[0]);
		int n; 
		double C; // calka obliczona numerycznie
        for(size_t iteracja2 = 0; iteracja2 < size2; iteracja2++){
            n = n_tab[iteracja2];
            int p = (n-1)/2;
			double h = (gorna_granica-dolna_granica)/(n-1);
			C=0;
			

            // Metoda S.
			for(size_t j=1; j<=p; j++){
				C += fun(2*j-2,m,k,h) + 4*fun(2*j-1,m,k,h) + fun(2*j,m,k,h);
			}
			C *= h/3;

            // Modul
            if(C-I>=0.0){
                fprintf(zadanie2, "%d\t%.10lf\n",n, C-I);
            }
            else{
                fprintf(zadanie2, "%d\t%.10lf\n",n, -(C-I));
            }
			
		}	
		fprintf(zadanie1, "\n");
		fprintf(zadanie2, "\n");
	}

	fclose(zadanie1);
	fclose(zadanie2);
	return 0;
}

double fact(int n){
	double result = 1;
	for(double i = 2; i<=n; i++) {
        result*=i;
    }
	return result;
}

double I_j(int j, int k, int m){
    double suma = 0;
    double licznik_1 = pow(-1,j) * (pow(k*gorna_granica, 2*j+m+2));
    double mianownik_1 = (pow(k,m+1) * fact(2*j+1) * (2*j+m+2));

    double licznik_2 = pow(-1,j) * (pow(k*dolna_granica, 2*j+m+2));
    double mianownik_2 = (pow(k,m+1) * fact(2*j+1) * (2*j+m+2));

    suma += licznik_1/mianownik_1;
    suma -= licznik_2/mianownik_2;
	return suma;
}

double fun(int index, int m, int k, double h){
	double x = dolna_granica + h*index;
	return (pow(x,m) * sin(k*x));
}