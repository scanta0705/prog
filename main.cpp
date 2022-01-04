
#include <iostream>
#include <fstream>
#include "matrice1.hpp"
#include "matrice2.hpp"
using namespace std;
int dim=0;
bool tab;

int main () {
    ifstream file;
    double **matrice;
    string nome;

    double **a;
    double *c;
    double *b;

    double *k;
    double *x;
    double x0;
    x[0]=x0;
    double *y;
    y[0]=funz(x[0]);

    bool errore;
    do{
        errore=leggifile(matrice, dim, nome, file,a,b,c);
        if (errore) {
            cout << "Errore durante la ricerca del file...";
        }
    }while (errore);
    cout<<endl;
    tab=tableau(matrice,a,b,c,dim);
    if(tab) cout<<"Errore, la matrice nel file non e' un tableau";

    bool esplicito;
    esplicito=esplicita(a, dim);

    dealloc(matrice, dim);
    return 0;
}
