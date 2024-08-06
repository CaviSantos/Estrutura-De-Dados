#include <string>
#include <iostream>
using namespace std;

struct dicionario {

	struct noh {

		string elemento;
		int chave;
		noh *proximo;

	};

	noh *fim;

	dicionario() {
		noh *sentinela = new noh;

		fim = sentinela;
		sentinela->proximo = nullptr;
	}

	bool inserir(string s, int c) {
		noh *novo = new noh;

		if(sentinela->proximo==nullptr) {
			sentinela->proximo = novo;
			novo->proximo = sentinela;
			fim = novo;
			fim->elemento = s;
			fim->chave = c;
		}
		else {
			novo->elemento = s;
			novo->chav = c;


			novo->proximo = sentinela;
			fim->proximo = novo;
			fim = novo;

		}
	}

	void remover(int c) {
	    if(sentinela->proximo->chave == c) {
				if(sentinela->proximo == fim) {
				    noh *aux = new noh;
				    
                    aux = fim;
                    fim = sentinela;
                    sentinela->proximo = nullptr;
                    delete aux;
                    
                    return;
				}
				else{
				    noh *aux = new noh;

				    aux = sentinela->proximo;
				    sentinela->proximo = aux->proximo;
				    delete aux;
				}
				
			}
			
		while(aux->proximo  != fim) {
		    
		    noh *aux = new noh;
			    
			aux = sentinela->proximo;
			    if(aux->proximo->elemento == c){
			        noh *deletador = new noh;
			        
			        deletador = aux->proximo;
			        aux->proximo = aux->proximo->proximo;
			        delete deletador;
			        
			        return;
			    }
			    
			    aux =  aux->proximo;

			}

		}
	}

	~dicionario() {
        while(fim != sentinela){
            if(sentinela->proximo != fim){
                noh *deleter = new noh;
                
                sentinela->proximo = deleter;
                sentinela->proximo = deleter->proximo;
                delete deleter;
            }
            else{
                noh *deleter = new noh;
                
                deleter = fim;
                sentinela->proximo = nullptr;
                fim = sentinela;
                delete deleter;
            }
        }
	}

};

int main()
{

	return 0;
}
