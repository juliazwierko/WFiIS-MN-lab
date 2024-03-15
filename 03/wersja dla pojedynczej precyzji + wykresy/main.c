#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define n 1000 

void suma(float w1[n], float w2[n])
{
	for (int i=0;i<n;i++)
	{
		w2[i]=w1[i]+w2[i];
	}
}
void iloczyn (float a[n][n], float x[n], float temp[n])
{
	for (int i=0;i<n;i++)
	{
		temp[i]=0.0;
		for (int j=fmax(0,i-10); j<=fmin(i+10,n-1);j++)
		{
			temp[i] += a[i][j] * x[j];
		}
	}
}
float iloczynskalarny(float w1[n], float w2[n])
{
	float wynik = 0.0;
	for (int i=0;i<n;i++)
	{
		wynik+=w1[i]*w2[i];
	}
	return wynik;
}

int main ()
{
    //1. Definiowanie macierzy A.
	int m=10;
	float A[n][n];
	for (int i=0; i<n; i++)
	{
		for (int j=0;j<n;j++)
		{
			if (abs(i-j)<m || abs(i-j)==m)
				A[i][j]=1./(1.+abs(i-j));
			else
				A[i][j]=0.;
		}
	}

    //Wypisanie macierzy dla n = 4:
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         printf("%.7f", A[i][j]);
    //         printf(", ");
    //     }
    //     printf("\n");
    // }
    // printf("\n");

    //2. Tworzenie wektora wyrazow wolnych b.
	float b[n];
	for (int i=0;i<n;i++)
	{
		b[i]=i;
	}

    //3. Metoda najwiekszego spadku dla rozwiazywania ukladu rownan.
	int k=0;
	float x[n];
    // dla 4.a) x jest zerowym
	for (int i=0; i<n ;i++)
	{
		x[i]=0.;
	}

	float temp[n];
    float r[n];
    float alfa;
	FILE *p1 = fopen("zadanie_a.txt", "w");
	do
	{
		k++;
		iloczyn(A, x, temp);
		for(int i=0;i<n;i++)
		{
			r[i]=b[i]-temp[i];
		}
		iloczyn(A, r, temp);
		alfa=iloczynskalarny(r,r)/iloczynskalarny(r,temp);
		for (int i=0;i<n;i++)
		{
			temp[i]=r[i]*alfa;
		}
		suma(temp, x);
		printf("%d %.5f %g %.5f \n", 
                k, sqrt(iloczynskalarny(r, r)), 
                alfa, sqrt(iloczynskalarny(x, x)));

		fprintf(p1, "%d \t %f \t %f \t %f\n", 
                k, sqrt(iloczynskalarny(r, r)), 
                alfa, sqrt(iloczynskalarny(x, x)));
	}
	while (sqrt((iloczynskalarny(r, r))) > pow(10, -6) && k < 500);

	k=0;
    
    // dla 4.b) b slada sie z jedynke
	for (int i=0;i<n;i++)
	{
		x[i]=1.0;
	}
	FILE *p2 = fopen("zadanie_b.txt", "w");
	do
	{
		k++;
		iloczyn(A, x, temp);
		for(int i=0;i<n;i++)
		{
			r[i]=b[i]-temp[i];
		}
		iloczyn(A, r, temp);
		alfa=iloczynskalarny(r,r)/iloczynskalarny(r,temp);
		for (int i=0;i<n;i++)
		{
			temp[i]=r[i]*alfa;
		}
		suma(temp, x);
		printf("%d %.5f %g %.5f \n", k, sqrt(iloczynskalarny(r, r)), alfa, sqrt(iloczynskalarny(x, x)));
		fprintf(p2, "%d \t %f \t %f \t %f\n", k, sqrt(iloczynskalarny(r, r)), alfa, sqrt(iloczynskalarny(x, x)));
	}
	while((sqrt(iloczynskalarny(r, r)) > pow(10, -6)) && (k < 500));

	fclose(p1);
	fclose(p2);
	return 0;
}
