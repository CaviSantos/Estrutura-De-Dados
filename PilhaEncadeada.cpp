
#include <iostream>
using namespace std;

struct Pilha{
    
    struct Noh{
        int elemento;
        Noh *prox;
    };
    
    Noh *topo;
    
    Pilha(){
        topo = nullptr;
    }
    
    void empilhar(int e){
        topo = new Noh{e,topo};
    }
    
    int consultar_topo(){
        return topo->elemento;
    }
    int desempilhar(){
        Noh *primeiro = topo;
        topo = topo->prox;
        delete primeiro;
    }
    ~Pilha(){
        while(topo!=nullptr){
            desempilhar();
        }
    }
}


int main(){

    // O foco do código está nas funções.

    return 0;
}
