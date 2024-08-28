#include <exception>
#include <iostream>
using namespace std;


class Matriz{
    int num_linhas;
    int num_colunas;
    double **M;
    
    public:
    
    //construtor
    Matriz(int linhas, int colunas){
        num_colunas = colunas;
        num_linhas = linhas;
        
        M = new double* [linhas];
        
        for(int l = 0; l < linha; l++){
            M[l] = new double [colunas];
        }
    }
    
    ~Matriz(){
        for(int l =0; l<num_linhas; l++){
            delete[] M[l];
        }
        delete[] M;
    }
    
    double& operator() (int i, int j) {
        return M[i][j];
    }
    
    int getColuna(){
        return num_colunas;
    }
    int getLinha(){
        return num_linhas        
    }
    
    
};



int main(){
   
   
    

    return 0;
}
