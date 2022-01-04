#ifndef __MATRICE2_H__
#define __MATRICE2_H__

#include "matrice1.hpp"
#include<iostream>
#include<fstream>
using namespace std;

bool esplicita(double **&a, int &dim){
    for(int i=0; i<dim-1; i++){
        for(int j=0; j<dim-1; j++){
            if(a[i][j]!=0 && j>=i) return true; //implicito
        }
    }
    return false; //esplicito
}

double funz(double x){
    double y=x;
    return y;
}

double restituisce(double *&y,double h, double *&k, double **&a, double *&b, double *&c, int &dim, int stop){
    k=new double[dim-1];
    y=new double[dim-1];
    for(int n=0; n<stop-1; n++){
        for(int i=0; i<dim-1; i++){
            for(int j=0; j<dim-1; j++){
                k[i]=y[n]+h*a[i][j]*funz(k[j]);
            }
        }
        for(int i=0; i<dim-1; i++){
            y[n+1]=y[n]+h*b[i]*funz(k[i]);
        }
    }
    return y[stop-1];
}


#endif
