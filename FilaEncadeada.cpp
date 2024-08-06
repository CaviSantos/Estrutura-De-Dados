// fila via lista encadeada
#include <iostream>
using namespace std;

struct Fila{
    
    struct noh{
        int elemento;
        noh *proximo;
    };
    
    noh *inicio;
    noh *fim;
    
    Fila(){
        inicio = fim = nullptr;
    }
    
    void inserir(int e){
        noh *novo = new noh {e,nullptr};

        
        if(inicio == nullptr){
            inicio = fim = novo;
        }
        
        else{
            fim->proximo = novo;
            fim = novo;
        }
    }
    
    void remover(){
        
        if(inicio==nullptr){
            cout << "vazio, remover_loss"<<;
            return 0;
        }
        
        noh *aux = new noh;
        inicio = inicio->proximo;
        
        if(inicio==nullptr){
           fim = nullptr;
            
        }
        delete aux;
    }
    
    int consultarPrimeiro(){
        return inicio->elemento; 
    }
        
    ~Fila(){
        while(inicio != nullptr){
            remover();
        }
    }
};

int main()
{
    

    return 0;
}
