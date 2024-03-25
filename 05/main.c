#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define n 7
#define IT_MAX 12

void roznica_Macierzy(double result[n][n], double macierz1[n][n], double macierz2[n][n]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            result[i][j] = macierz1[i][j] - macierz2[i][j];
        }
    }   
}

void kopia_Macierzy(double macierz1[n][n], double macierz2[n][n]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            macierz1[i][j] = macierz2[i][j];
        }
    }
}

void transponuj(double macierz1[n][n], double macierz2[n][n]) 
{
    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < n; j++)
        {
            macierz1[j][i] = macierz2[i][j];
        }
    }
}

void iloczyn_Macierz_Wektor(double macierz[n][n], double wektor[n], double res[n]){
    for(unsigned int i=0; i<n; i++){
        res[i]=0.;
        for(unsigned int j=0;j<n;j++){
            res[i]+=macierz[i][j]*wektor[j]; 
        }
    }
}

double iloczyn_Skalarny(double wektor1[n], double wektor2[n]) {
    double res=0.0;
    for(int i=0;i<n;i++){
        res+=wektor1[i]*wektor2[i];
    }
    return res;
}

void iloczyn_Macierz_Macierz(double res[n][n], double macierz1[n][n], double macierz2[n][n]){
    for (unsigned int i=0; i<n; i++){
        for (unsigned int j=0; j<n; j++){
            res[i][j] = 0.; 
            for (unsigned int k = 0; k < n; k++)
                res[i][j]+=macierz1[i][k] * macierz2[k][j];
        }
    }
}

void iloczyn_Tensorowy(double res[n][n], double vector[n], double lambda){
    for(unsigned int i = 0; i < n; i++) {
        for(unsigned int j = 0; j < n; j++){
            res[i][j] = lambda * vector[i] * vector[j];
        }
    }
}

int main()
{
    // Zadanie 1
	double A[n][n];
    double W[n][n];
    double Wn[n][n];
     for (int i = 0; i < n; i++)
{
        for (int j = 0; j < n; j++){
            A[i][j] = (1.)/sqrt(2.+fabs(i-j));
            W[i][j] = A[i][j];
            Wn[i][j]=A[i][j];
        }
    }

    // Zadanie 2
    double X[n][n];
    double X_T[n][n];
    double D[n][n];
    double x_old[n];
    double x_new[n];
    double lambda;
    double temp[n][n];
    FILE *w_wlasne;
    FILE *macierz_D;
    w_wlasne = fopen("wynik.txt", "w");
    macierz_D = fopen("macierz_D.txt", "w");

    for (unsigned int k = 0; k < n; k++){
    	for (int i=0;i<n;i++){
    		x_old[i]=1.;
        }
    	for(unsigned i = 1; i <= IT_MAX; i++){
    		iloczyn_Macierz_Wektor(W, x_old, x_new);
    		lambda=iloczyn_Skalarny(x_new,x_old)/iloczyn_Skalarny(x_old,x_old);
    		for (unsigned int j=0;j<n;j++){
                x_old[j] = x_new[j]/sqrt(iloczyn_Skalarny(x_new, x_new));
            }
    		fprintf(w_wlasne, "%d  %f \n", i, lambda);
    	}
    	fprintf(w_wlasne, "\n");


    	iloczyn_Tensorowy(temp, x_old, lambda);
        roznica_Macierzy(Wn, W, temp);
        kopia_Macierzy(W, Wn);
        for (unsigned int i = 0; i < n; i++){
            X[i][k] = x_old[i];
        }
    }

    // Zadanie 3
    iloczyn_Macierz_Macierz(temp,A,X);
    transponuj(X_T,X);
    iloczyn_Macierz_Macierz(D,X_T,temp);

    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < n; j ++) 
        {
            fprintf(macierz_D, "%e ", D[i][j]);
        }
        fprintf(macierz_D, "\n");
    }
    fclose(w_wlasne);
    fclose(macierz_D);

	return 0;
}
