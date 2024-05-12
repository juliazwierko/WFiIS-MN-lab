#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//funkcja 1 oraz funkcja 2
double fun1(double x){return log(pow(x,5) + (3*pow(x,2)) + x + 9);}
double fun2(double x){return pow(x,6);}
// iloraz roznicowy pierwszego rzedu
double F1(double (*fun)(double), double x1, double x2){
    return (fun(x2)-fun(x1))/(x2-x1);}
// iloraz roznicowy drugiego rzedu
double F2(double (*fun)(double), double x1, double x2, double x3){
	return (F1(fun,x2,x3) - F1(fun,x1,x2))/(x3-x1);
}

int main(int argc, char** argv){
    //punkty startowe
	double x_min = -1.5;
    double x_max = 1;
    double h = 0.01;
	double eps = 1e-7; 
    double minimum;

	FILE *log;
	log = fopen("log.txt","w");
    // wykres funckji log f1(x) = ln(x^5 + 3x^2 + x + 9)
	for(double x = x_min; x<=x_max; x+=h){
        fprintf(log, "%f\t%f\n", x, fun1(x));
    }
	fclose(log);

//-----------------  FUNCKJA 1, ZADANIE dla x1 = -0.5  ----------------- 
	printf("funkcja 1, dla punktu startowego x1=-0.5\n");
	double x1 = -0.5; 
    double x2, x3;
    if(fun1(x1+h)<fun1(x1)) {x2 = x1+h;}
    else{x2 = x1-h;}

    if(fun1(x2+h)<fun1(x2)) {x3 = x2+h;}
    else{x3 = x2-h;}
	FILE *fun1_zad1;
	fun1_zad1 = fopen("fun1_zad1.txt","w");
	double x_m;
	int n = 10; // ilosc przyblizen;
    
    // fprintf(fun1_zad1,"%s\t %s\t\t %s\t\t %s\t %s\t %s\t %s\n", 
    //             "it.", "x1", "x2", "x3", "x_m", "F1(fun1,x1,x2)","F2(fun1,x1,x2,x3)");

	for(int i = 0; i<n; ++i)
	{   
        
		x_m = ((x1+x2)/2.) - (F1(fun1,x1,x2)/(2*F2(fun1,x1,x2,x3)));
		fprintf(fun1_zad1,"%i\t%f\t%f\t%f\t%f\t%f\t%f\n", 
                i+1, x1, x2, x3, x_m, F1(fun1,x1,x2),F2(fun1,x1,x2,x3));
	
		if(fabs(x_m-x1) < eps || fabs(x_m-x2) < eps || fabs(x_m-x3) < eps){
			minimum = x_m;
			break;
		}
		if(fabs(x_m-x1) < fabs(x_m-x2)){
			if(fabs(x_m-x2) < fabs(x_m-x3)) x3 = x_m;
			else x2 = x_m;
		}
		else{
			if(fabs(x_m-x1) < fabs(x_m-x3)) {
                x3 = x_m;
            }
			else x1 = x_m;
		}
	}
    fclose(fun1_zad1);

//----------------- FUNCKJA 1, ZADANIE dla x1 = -0.9  ----------------- 
    printf("funkcja 1, dla punktu startowego x1=-0.9\n");
    x1 = -0.9; 
    x2 = x3 = 0.;
    if(fun1(x1+h)<fun1(x1)) {x2 = x1+h;}
    else{x2 = x1-h;}

    if(fun1(x2+h)<fun1(x2)) {x3 = x2+h;}
    else{x3 = x2-h;}
	FILE *fun1_zad2;
	fun1_zad2 = fopen("fun1_zad2.txt","w");
    x_m = 0 ;
	n = 10; // ilosc przyblizen;

    // fprintf(fun1_zad2,"%s\t %s\t\t %s\t\t %s\t %s\t %s\t %s\n", 
    //             "it.", "x1", "x2", "x3", "x_m", "F1(fun1,x1,x2)","F2(fun1,x1,x2,x3)");

	for(int i = 0; i<n; ++i)
	{   
        
		x_m = ((x1+x2)/2.) - (F1(fun1,x1,x2)/(2*F2(fun1,x1,x2,x3)));
		fprintf(fun1_zad2,"%i\t%f\t%f\t%f\t%f\t%f\t%f\n", 
                i+1, x1, x2, x3, x_m, F1(fun1,x1,x2),F2(fun1,x1,x2,x3));
	
		if(fabs(x_m-x1) < eps || fabs(x_m-x2) < eps || fabs(x_m-x3) < eps){
			minimum = x_m;
			break;
		}
		if(fabs(x_m-x1) < fabs(x_m-x2)){
			if(fabs(x_m-x2) < fabs(x_m-x3)) x3 = x_m;
			else x2 = x_m;
		}
		else{
			if(fabs(x_m-x1) < fabs(x_m-x3)) {
                x3 = x_m;
            }
			else x1 = x_m;
		}
	}
    fclose(fun1_zad2);

//----------------- FUNCKJA 2, ZADANIE dla x1 = 1.5  ----------------- 
    printf("funkcja 2, dla punktu startowego x1= 1.5\n");
    x1 = 1.5; 
    x2 = x3 = 0.;
    if(fun1(x1+h)<fun1(x1)) {x2 = x1+h;}
    else{x2 = x1-h;}

    if(fun1(x2+h)<fun1(x2)) {x3 = x2+h;}
    else{x3 = x2-h;}
	FILE *fun2_zad1;
	fun2_zad1 = fopen("fun2_zad1.txt","w");
    x_m = 0 ;
	n = 100; // ilosc przyblizen;

    // fprintf(fun2_zad1,"%s\t %s\t\t %s\t\t %s\t %s\t %s\t %s\n", 
    //             "it.", "x1", "x2", "x3", "x_m", "F1(fun1,x1,x2)","F2(fun1,x1,x2,x3)");

	for(int i = 0; i<n; ++i)
	{
		x_m = ((x1+x2)/2.0) - (F1(fun2,x1,x2)/(2*F2(fun2,x1,x2,x3)));
		fprintf(fun2_zad1,"%i\t%f\t%f\t%f\t%f\t%f\t%f\n", i+1, x1,x2,x3,x_m,F1(fun2,x1,x2),F2(fun2,x1,x2,x3));
		if(fabs(x_m-x1) < eps || fabs(x_m-x2) < eps || fabs(x_m-x3) < eps)
		{
			minimum = x_m;
			break;
		}
		if(fabs(x_m-x1) < fabs(x_m-x2))
		{
			if(fabs(x_m-x2) < fabs(x_m-x3)) x3 = x_m;
			else x2 = x_m;
		}
		else
		{
			if(fabs(x_m-x1) < fabs(x_m-x3)) x3 = x_m;
			else x1 = x_m;
		}
	}
u
	fclose(fun2_zad1);
    return 0;
}
