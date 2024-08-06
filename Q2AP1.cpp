#include <string>
#include <iostream>
using namespace std;

questão 2 da AP2 de Estrutura de dados.

struct lista{
    
    noh *primeiro; // nulo de vazia
    noh *ultimo; // nulo se vazia
    
};
struct noh{
    noh *ant; // nulo no primeiro
    double elem; // 
    noh *prox; // nulo no ultimo
};

void mover_ordenado(Lista &L, noh *n){
    if(n->ant <= n or L.primeiro == n){
        return 0;
    }
    
    n->ant = n->prox;
    n->prox = n->ant;
    
    if(n->elemento <= L.primeiro->elemento){
        n->ant =  L.primeiro->ant;
        n->prox =  L.primeiro;
        L.primeiro->ant = n;
        return 0;
    }
    
    noh *aux = n->ant;
    while(aux->elemento < aux->ant->elemento){
        aux = aux-ant;    
    }
    
    n->ant = aux->ant;
    aux->ant->prox = n;
    n->prox = aux;
    aux->ant = n;
    
    if(n->prox == nullptr){
        L.ultimo = n->ant;
    }
    
}
int main()
{

	return 0;
}
