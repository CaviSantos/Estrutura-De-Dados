#include <iostream>
#define size 5
using namespace std;

struct Fila{
    int vet[size];
    int p;
    int u;
};
void inicializar(Fila &F){
    F.p=-1;
    F.u=-1;
}

bool vazia(Fila &F){
    if(F.p == -1){
        return true;
    }
    return false;
}
    
bool remover(Fila &F){
   if(vazia(F)){
       cout << "\nnão há como remover, fila vazia.\n";
       return false;
   }
   else if(F.p == F.u){
       F.p = F.u = -1;
       return true;
   }
   else {
       F.p = (F.p + 1)%size;
       return true;
   }
}

bool cheia(Fila &F){
    if((F.u + 1)%size==F.p){
        return true;
    }
    return false;
}

bool inserir(Fila &F, int num){
    if(cheia(F)){
        cout << "fila cheia\n";
        return false;
    }
    else if(vazia(F)){
        F.p = F.u = 0;
        F.vet[F.u] = num;
        return true;
    }
    else{
        F.u = (F.u + 1)%size;
        F.vet[F.u] = num;
        return true;
    }
    
}
int main(){
   
    int op;
    int num;
    Fila F;
    inicializar(F);
    do{
    cout << "\nselecione a opção: \n\n";
    cout << "1-ver se a fila está ou não vazia\n2-inserir um elemento\n3-remover o primeiro elemento\n4-consultar o primeiro elemento\n5-sair";
    cout <<"\n";
    cin >> op;
       switch(op){
        case 1:
            if(vazia(F)){
                cout << "\nfila vazia\n\n";
            }
            else if(cheia(F)){
                cout << "\nfila cheia\n\n";
            }
            else{
                cout << "\nfila com elementos, mas não cheia\n\n";
            }
            break;
        case 2:
            cout << "\ndigite o elemento que deseja inserir: ";
            cin >> num;
            if(inserir(F,num)){
                cout << "\nelemento inserido com sucesso\n";
            }
            else{
                cout << "\nelemento não inserido\n\n";
            }
            break;
        case 3:
            {
                int x = F.vet[F.p];
                if(remover(F)){
                    cout << "elemento "<< x <<" removido com sucesso\n\n";
                }
            }
            break;
        case 4:
            if(vazia(F)){
                cout << "fila vazia, não há primeiro elemento\n";
            }
            else{
                cout << "o primeiro elemento da fila é "<<F.vet[F.p];
            }
            break;
        }
    }while(op!=5);
       

    return 0;
}
