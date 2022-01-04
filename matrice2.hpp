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

double avanzaesplicito(double *&x, double *&y,double h, double *&k, double **&a, double *&b, double *&c, int &dim){
    k=new double[dim-1];
    x=new double[dim-1];
    y=new double[dim-1];
    /*double y=y0;
    for(int f=0; f<dim-1; f++){
        for(int i=0; i<dim-1; i++){
            k[i]=h*funz(x[f]+c[i]*h, y);
            for(int j=0; j<i; j++){
                y=y+a[i][j]*k[i];
            }
        }
    }*/
    
    
    return 1;
}

#endif