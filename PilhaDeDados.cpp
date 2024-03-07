#include <iostream>
using namespace std;

struct Pilha{
    char *array;
    int contador;
};
void inicializar(Pilha &P,int size){
    P.array = (char*) malloc(size * sizeof(char));
    P.contador = 0;
}
bool vazia(Pilha &P){
    return P.contador == 0;
}

bool cheia(Pilha &P,int size){
    return P.contador == size;
}

bool inserir(Pilha &P, char letra, int size){
    if(cheia(P,size)){
        cout << "Pilha cheia, elemento não inserido\n\n";
        return false;
    }
    else{
        P.array[P.contador] = letra;
        P.contador++;
        cout << "letra inserida\n\n";
        return true;
    }
}

bool remover(Pilha &P, char letra){
    if(vazia(P)){
        cout << "pilha vazia, não é possível remover.";
        return false;
    }
    else{
        P.contador--;
        cout << "letra removida";
        return true;
    }
}
void ultimo(Pilha &P){
    if(!vazia(P)){
        cout << P.array[P.contador -1];
    }
    else {
        cout << "pilha vazia\n\n";
    }
}
int main(){
    int size;
    Pilha P;
    int ops;
    cout << "insira o tamanho da fila: ";
    cin >> size;
    cout << "\n";
    inicializar(P, size);
    cout << "selecione a opcao requerida";
    while(ops != 6){
        cout << "\n1 - ver se a fila está cheia \n2 - ver se ela está vazia \n3 - inserir elemento \n4 - remover o ultimo elemento\n5 - ver qual o ultimo elemento\n\n";
        cin >> ops;
        switch(ops){
        case 1:
            if(cheia(P,size)){
                cout << "pilha cheia\n";
                cout << "\n";
                break;
            }
            cout << "pilha com espaço\n\n";
            break;
        case 2:
            if(vazia(P)){
                cout << "pilha vazia";
                cout << "\n";
                break;
            }
            else {
                cout << "pilha com elementos\n\n";
            }
            break;
        case 3:
            char letra;
            cout << "insira a letra desejada: ";
            cin >> letra;
            inserir(P,letra,size);
            break;
        case 4:
            remover(P,letra);

            break;
        case 5:
            ultimo(P);

            break;
        }
    }
    return 0;
}
