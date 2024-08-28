#include <exception>
#include <iostream>
using namespace std;


class matriz{
    int num_linhas;
    int num_colunas;
    double **M;
    
    public:
    
    //construtor
    Matriz(int linhas, int colunas){
        num_colunas = colunas;
        num_linhas = linhas;
        
        M = new double* [linhas];
        
        for(int l = 0; l < linhas ; ++l){
            M[l] = new double [colunas];
        }
        
    }
    
    //destrutor
    ~Matriz(){
        for(int l = 0 ; l<linhas; ++l){
            delete[] M[l];
        }
        delete[] M;
    }
}


int main(){
    try{
        
    }
    catch{
        
    }




    return 0;
}
