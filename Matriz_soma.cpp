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
        
        for(int l = 0; l < linhas; l++){
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
        return num_linhas;        
    }
    
    
};

Matriz soma(Matriz &cleiton, Matriz &rasta){
    
    Matriz cabecadegelo(cleiton.getLinha(),cleiton.getColuna());
    
    for(int a = 0; a < cleiton.getLinha(); a++){
        for(int b = 0; a < cleiton.getColuna(); b++){
            cabecadegelo(a,b) = cleiton(a,b) + rasta(a,b);
        }
    }
    return cabecadegelo;
}

int main(){
    /*
    int i,j;
    
    
   cout << "matriz 1";
   cout << "numero de linhas: "; cin >> i; 
   cout <<"\n";
   cout << "numero de colunas : "; cin >> j;
   cout <<"\n";
   
   Matriz cleiton(i,j);
   
   for(int k = 0; k < i;k++){
       for(int g = 0; g<j; g++){
           cin >> cleiton(k,g);
       }
   }
   
   cout << "matriz 2";
   Matriz rasta(i,j);
   
   for(int k = 0; k < i;k++){
       for(int g = 0; g<j; g++){
           cin >> rasta(k,g);
       }
   }
   */
   Matriz cleiton(2,2);
   cleiton(0,0) = 1; cleiton(0,1) = 2;
   cleiton(1,0) = 3; cleiton(1,1) = 4;
   Matriz rasta(2,2);
   rasta(0,0) = 4; rasta(0,1) = 3;
   rasta(1,0) = 2; rasta(1,1) = 1;
   
    
    Matriz pedra = soma(cleiton,rasta);
    
    for(int k = 0; k < 2;k++){
       for(int g = 0; g<2; g++){
           cout << pedra(k,g) <<" ";
       }
       cout << "\n";
   } 

    return 0;
}
