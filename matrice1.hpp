#ifndef __MATRICE1_H__
#define __MATRICE1_H__

#include<iostream>
#include<fstream>
#define maxnome 100
using namespace std;
bool tableau(double **&matrice, double **&a, double *&b,double *&c, int &dim);
void trovaa(double **&matrice, double **&a, int &dim);
void trovac(double **&matrice, double *&c, int &dim);
void trovab(double **&matrice, double *&b, int &dim);
//------------------------------------------------------leggo file da tableau e creo la matrice e la stampo
bool leggifile(double **&matrice, int &dim, string nome, ifstream &file, double **&a, double *&b, double *&c) {
    //cout << "Inserisci nome percorso:\n";
    //cin >> nome;
    
    nome="tableau.txt";
    file.open(nome);
    
    if (!file) {
        return true; //mi da cout errore dopo nel main 
    }
    double count=0;
    while (!file.eof()) {     //finchè non finisce il file
        file >> count;
        dim++;  
    }
    cout << "count: " << count << endl;
    dim=sqrt(dim);
    cout << "La dimensione della matrice e': " << dim <<endl;

    file.seekg(0, file.beg); //Sets the position of the next character to be extracted from the input stream

    matrice=new double*[dim]; //alloca lo spazio per dim puntatori
    for (int i=0; i<dim; i++) { //per ogni riga assegna ai puntatori delle righe della matrice l'indirizzo di dim
        matrice[i]=new double [dim];
    }
    for (int i=0; i<dim; i++) {
        for (int j=0; j<dim; j++) {
            file >> matrice[i][j];
            cout << matrice[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;

    trovaa(matrice, a, dim);
    trovac(matrice, c, dim);
    trovab(matrice, b, dim);

    return false;
    file.close();
}

//--------------------------------------------------funzione che mi dealloca la memoria
void dealloc(double **&matrice, int dim) {
    for (int i=0; i<dim; i++) {
        delete [] matrice[i];
    }
    delete [] matrice;
}
//------------------------------------------------funzioni che mi dividono la matrice in a, b, c, e le stampano
void trovaa(double **&matrice, double **&a, int &dim){
    a=new double*[dim-1]; 
    for (int i=0; i<dim-1; i++) {
        a[i]=new double [dim-1];
    }
    for (int i=0; i<dim-1; i++) {
        for (int j=0; j<dim-1; j++) {
            a[i][j]=matrice[i][j+1]; //prima righe poi colonne
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;
}
void trovac(double **&matrice, double *&c, int &dim){
    c=new double[dim-1];
    for(int i=0; i<dim-1; i++){
        c[i]=matrice[i][0]; 
        cout<< c[i]<<" ";
    }
    cout<< endl<< endl;;

}
void trovab(double **&matrice, double *&b, int &dim){
    b=new double[dim-1];
    for(int i=0; i<dim-1; i++){
        b[i]=matrice[dim-1][i+1];
        cout<< b[i]<<" ";
    }
    cout<< endl;
}
//-----------------------------------------------mi dice se la matrice è un tableau
bool tableau(double **&matrice,double **&a, double *&b,double *&c, int &dim){
    if(matrice[dim-1][0]!=0) return true; // se elemento sotto c è diverso da zero allora sicuro non è un tableau
    for(int i=0; i<dim-1; i++){ //controlla che la somma delle righe di a sia c
        int somma=0;
        for(int j=0; j<dim-1; j++){
            somma=somma+a[i][j];
        }
        if(somma!=c[i]) return true;
    }
    int somma=0;
    for(int i=0; i<dim-1; i++){ //controlla che la somma di b sia 1
        somma=somma+b[i];  
    }
    if(somma!=1) return true;
    return false;
}
#endif