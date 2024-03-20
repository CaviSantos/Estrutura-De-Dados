#include <iostream>
using namespace std;

struct Conjunto{
    int vet[5];
    int n;
};
void inicializar(Conjunto &C){
    C.n = 0;
} // ok.
bool vazio(Conjunto &C){
    if(C.n == 0){
        return true;
    }
    else{
        return false;
    }
} // ok.
bool cheio(Conjunto &C){
    if(C.n == 5){
        return true;
    }
    else{
        return false;
    }
} // ok.
void inserir(Conjunto &C, char elemento){
    if(vazio(C) || cheio(C)){
        if(cheio(C)){
            cout << "conjunto cheio, elemento não inserido\n";
        }
        else{
            C.vet[C.n++] = elemento;
            cout << "elemento inserido\n";
        }
    }
    else{
        for(int i = 0; i<C.n;i++){
            if(C.vet[i]==elemento){
                cout << "elemento já inserido no conjunto.\n";
            }
        }
        if(C.n > 5){
            C.vet[C.n++] = elemento;
        }
        else{
            cout << "conjunto cheio.\n";
        }
    }
} // ok
bool pertence(Conjunto &C, char elemento){
    for(int k = 0 ; k < C.n ;k++){
        if(C.vet[k]==elemento){
            cout << "o elemento está no conjunto.\n";
            return true;
        }
    }
    cout << "o elemento não está no Conjunto.\n";
    return false;
} // ok
void remover(Conjunto &C, char elemento){
    bool verifica = false;
    if(vazio(C)){
        cout << "conjunto vazio, não dá para remover.\n";
    }
    else{
        verifica = false;
        for(int j = 0; j < C.n;j++){
            if(C.vet[j]==elemento){
                C.vet[j]=C.vet[C.n - 1];
                C.n--;
                verifica = true;
                cout << "elemento removido.\n";
                break;
            }
        }
    }
    if(verifica == false){
        cout<< "elemento não encontrado, logo, não pode ser removido\n";
    }
} // ok
int main()
{
    char elemento;
    Conjunto C;
    inicializar(C);
    
    int op;
    do{
        cout << "insira a operação.\n";
        cout << "1-inserir\n2-ver cheio\n3-ver vazio\n4-pertence\n5-remover\n6-sair\n";
        cin >> op;
        switch(op){
            case 1:
                cout << "Insira o elemento a ser inserido: ";
                cin >> elemento;
                inserir(C, elemento);
                break;
            case 2:
                if(cheio(C)){
                    cout << "O conjunto está cheio.\n";
                } else {
                    cout << "O conjunto não está cheio.\n";
                }
                break;
            case 3:
                if(vazio(C)){
                    cout << "O conjunto está vazio.\n";
                } else {
                    cout << "O conjunto não está vazio.\n";
                }
                break;
            case 4:
                cout << "Insira o elemento a ser verificado: ";
                cin >> elemento;
                pertence(C, elemento);
                break;
             case 5:
                cout << "Insira o elemento a ser removido: ";
                cin >> elemento;
                remover(C, elemento);
                break;
            default:
                cout << "obrigado por utilizar o programa!\n";
        }
    }while(op != 6);

    return 0;
}
