#include "sinft.c"
#include "four1.c"
#include "realft.c"
#include "nr.h"
#include "nrutil.c"
#include "nrutil.h"

#include <stdio.h>
#include "stdlib.h"
#include "time.h"
#include <stdlib.h>
// gcc main.c -lm 


// liczba pseudolosowa.
float X();
// zmienna losowa imitujaca szum.
float a();

int main(){
    srand(time(NULL));
    FILE *file1;
	FILE *file2;
	FILE *file3;
	FILE *file4;
    file1 = fopen("zadanie1.txt","w");
    file2 = fopen("zadanie2.txt","w");
    file3 = fopen("zadanie3.txt","w");
    file4 = fopen("zadanie4.txt","w");

    int tablica_k[3] = {10,8,6};
    int size = sizeof(tablica_k)/sizeof(tablica_k[0]);
    for(int iteracja = 0; iteracja<size; iteracja++){
        int k = tablica_k[iteracja];
        int n = pow(2,k);
        float w = 2*2*M_PI/n;

        // #1
        float y0[n];
        float y[n];
        for(int i = 0; i<n; ++i){
            y0[i] = sin(w*(i+1)) + sin(2*w*(i+1)) + sin(3*w*(i+1));
            y[i] = y0[i] + a();
            if(iteracja == 0) 
                fprintf(file1, "%d\t%f\t%f\n", (i+1), y[i], y0[i]);
        }

        // #2 
        sinft(y,n);
        for(int i = 0; i<n; ++i)
        {
            if(iteracja == 0) 
                fprintf(file2, "%d\t%f\n", (i+1), y[i]);
            if(i<=100 && iteracja==0) 
                fprintf(file3, "%d\t%f\n", (i+1), y[i]);
        }

        // #3 i #4
        float d = 0.25;
        float max = -1e5;
	    for(size_t i = 0; i<n; ++i){if(y[i]>max) max = y[i];}
        d*=max;
        for(size_t i = 0; i<n; ++i){if(y[i]<d) y[i]=0;} 
     
        sinft(y,n);
        for(size_t i = 0; i<n; ++i)
        {
            y[i]*=2./n;
            fprintf(file4, "%d\t%f\t%f\n", (i+1), y[i], y0[i]);
        }
        fprintf(file4, "\n\n");
    }
    fclose(file1);
    fclose(file2);
    fclose(file3);
    fclose(file4);
    return 0;
}

void srand( unsigned int seed );
float X(){return rand()/(RAND_MAX+1.0);}
float a(){
    float Y = X();
    int sign = 0;
    float value = 1/2;
    if((Y<value) || (Y==value)){
        sign = -1;
    }
    sign = +1;
    return 2*sign*X();
}