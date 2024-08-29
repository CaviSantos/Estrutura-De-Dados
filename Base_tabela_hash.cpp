#include <string>
#include <iostream>
using namespace std;

class Dic{
    struct noh{
        int chave;
        string elemento;
        noh *prox;
    };
    
    noh** tabela
    int tamanho;
    
    public:
    
    Dic(){
        tamanho = 5;
        tabela = new noh* [tamanho];
        for(int i = 0; i<tamanho; i++){
            tabela[i] = nullptr;
        }
    }
    
    struct resultado{
        bool achado;
        string valor;
    };
    
    int hash_calc(int chave){
        return chave%tamanho;
    }
    
    resultado consulta(int chave){
        noh* cursor = tabela[hash_calc(chave)];
        resultado R;
        while(cursor != nullptr){
            
            if(cursor->chave == chave){
                R.achado = true;
                R.valor = cursor->elemento;
                return R;
            }
            cursor = cursor->prox;
        }
        R.achado = false;
        R.valor = NULL;
        return R;
    }
    
    void inserir(int chave, string elemento){
        noh* inicio = tabela[hash_calc(chave)];
        noh* novo = new noh {chave,elemento,inicio}
        
        inicio = novo;
    }
    
    
    void inserir_se_novo(int chave, string elemento){
        if(consulta(chave).achado == false){
            inserir(chave,elemento);
        }
    }
    
    void remover(int chave){
        noh* cursor = tabela[hash_calc(chave)];
        if(cursor == nullptr){
            return;
        }
        if(cursor->chave == chave){ //caso q a chave é a primeira
            tabela[hash_calc(chave)] = cursor->prox;
            
            delete cursor;
        }
        while(cursor->prox != nullptr){
            
            if(cursor->prox->chave == chave){
                
                noh* aux = cursor->prox;
                
                cursor = aux->prox;
                
                delete aux;
            }
        }
        
    }
    
    
    
    ~Dic(){
        
    }
    
};

int main(){
    
    

    return 0;
}
