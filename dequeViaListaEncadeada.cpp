#include <iostream>
#include <string>
using namespace std;

struct Deque {
    
    struct noh {
        int elemento;
        noh *esquerda;
        noh *direita;
    };
    
    noh *inicio;
    noh *fim;
    
    Deque() {
        inicio = fim = nullptr;
    }
    
    void inserir(int e, const string& lado) {
        noh *novo = new noh{e, nullptr, nullptr};
        if (inicio == nullptr) {
            inicio = fim = novo;
        } else {
            if (lado == "esquerda") {
                novo->direita = inicio;
                inicio->esquerda = novo;
                inicio = novo;
            } else if (lado == "direita") {
                novo->esquerda = fim;
                fim->direita = novo;
                fim = novo;
            } else {
                cout << "Lado inválido. Use 'esquerda' ou 'direita'." << endl;
                delete novo;
            }
        }
    }
    
    void remover(const string& lado) {
        if (inicio == nullptr) {
            cout << "Deque vazio, não há elementos para remover." << endl;
            return;
        }
        noh *aux;
        if (lado == "esquerda") {
            aux = inicio;
            inicio = inicio->direita;
            if (inicio != nullptr) {
                inicio->esquerda = nullptr;
            } else {
                fim = nullptr;
            }
            delete aux;
        } else if (lado == "direita") {
            aux = fim;
            fim = fim->esquerda;
            if (fim != nullptr) {
                fim->direita = nullptr;
            } else {
                inicio = nullptr;
            }
            delete aux;
        } else {
            cout << "Lado inválido. Use 'esquerda' ou 'direita'." << endl;
        }
    }
    
    int consultarInicio() {
        if (inicio != nullptr) {
            return inicio->elemento;
        } else {
            cout << "Deque vazio." << endl;
            return -1; // Valor de erro
        }
    }
    
    int consultarFim() {
        if (fim != nullptr) {
            return fim->elemento;
        } else {
            cout << "Deque vazio." << endl;
            return -1; // Valor de erro
        }
    }
    
    ~Deque() {
        while (inicio != nullptr) {
            noh *aux = inicio;
            inicio = inicio->direita;
            delete aux;
        }
    }
};

int main() {
    Deque d;

    d.inserir(10, "esquerda");
    d.inserir(20, "direita");
    d.inserir(30, "esquerda");

    cout << "Inicio do deque: " << d.consultarInicio() << endl;
    cout << "Fim do deque: " << d.consultarFim() << endl;

    d.remover("esquerda");
    cout << "Inicio do deque após remover da esquerda: " << d.consultarInicio() << endl;

    d.remover("direita");
    cout << "Fim do deque após remover da direita: " << d.consultarFim() << endl;

    d.remover("esquerda");
    d.remover("esquerda"); // Testar remoção quando o deque está vazio

    return 0;
}
