#include <iostream>
#define size 5
using namespace std;
struct Fila{
    char v[size];
    int p;
    int n;
};
void inicializar(Fila &F){
    F.p = -1;
    F.n = 0;
}
bool cheio(Fila &F){
    if(F.n == size){
        return true;
    }else{
        
        return false;
    }
    
}
bool vazio(Fila &F){
    if(F.n == 0){
        return true;
    }
    else{
        return false;
    }
}
bool remover(Fila &F){
    if(F.n == 0){
        cout << "fila vazia, não é possível remover\n";
        return false;
    }
    else if(F.n == 1){
        inicializar(F);
        cout << "elemento removido.\n";
        return true;
    }
    else{
        F.p = (F.p + 1)%size;
        F.n--;
        cout << "elemento removido.\n";
        return true;
    }
}
bool inserir(Fila &F, char c){
    if(cheio(F)){
        cout << "elemento não inserido, fila cheia!\n";
        return false;
    }
    else if(vazio(F)){
        F.p = 0;
        F.n++;
        F.v[F.p]=c;
        cout << "elemento inserido.\n\n";
        return true;
    }
    else{
        int indice  = (F.p + F.n)%size;
        F.v[indice]=c;
        F.n++;
        cout << "elemento inserido.\n\n";
        return true;
    }

}
void primeiro(Fila &F){
    if(vazio(F)){
        cout << "fila vazia, não tem primeiro.\n";
    }
    else{
        cout << "o primeiro da fila é: " << F.v[F.p]<<"\n";
    }
}
int main(){
    Fila F;
    char c;
    inicializar(F);
    int op;
    do{
        cout << "1-inserir\n2-remover\n3-ver vazio/cheio\n4-ver primeiro\n5-sair\n";
        cout << "insira a opção desejada: ";
        cin >> op;
        switch(op){
            case 1:
                cout << "digite o elemento: ";
                cin >> c;
                inserir(F,c);
                break;
            case 2:
                remover(F);
                break;
            case 3:
                if (vazio(F)){
                    cout << "fila vazia\n\n";
                }
                else if(cheio(F)){
                    cout << "fila cheia\n\n";
                }
                else{
                    cout << "fila com elementos\n\n";
                }
               
                break;
            case 4:
                primeiro(F);
                break;
        }
    }while(op<5);

    return 0;
}
