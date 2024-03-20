//Escreva uma implementação alternativa de Fila Limitada, 
//com capacidade para até 10 elementos armazenados simultaneamente,
//que utilize 2 vetores de 5 elementos. 
#include <iostream>
using namespace std;
struct Fila{
    int p;
    int u;
    int tam;
    int v1[5];
    int v2[5];
};
void inicializar(Fila &F){
    F.p = -1;
    F.u = -1;
}
bool vazio(Fila &F){
    return (F.u == F.p == -1);
}
bool cheio(Fila &F){
    return !((F.p + F.u + 1) % 10);
}
bool inserir(Fila &F, int elemento){
    if(cheio(F)){
        return false;
    }
    else if (vazio(F)){
        F.p = F.u =  0;
        F.v1[F.p]=elemento;
        F.p++;
        F.u++;
        return true;
    }
    else if(!cheio(F) && !vazio(F)){
        int index = (F.u - F.p)%10;
        if(index < 4){
            F.v1[F.p]=elemento;
            F.p++;
            F.u++;
            return true;
        }
        else{
            F.v2[F.p-5]=elemento;
            F.p++;
            F.u++;
            return true;
        }
    }
}
bool remover(Fila &F){
    if(vazio(F)){
        return false;
    }
    else if(F.p == F.u){
        inicializar(F);
        return true;
    }
    else{
        F.p = (F.p+1)%10;
      return true;
    }
    return true;
}
int primeiro(Fila &F){
    if(F.p < 4){
        return F.v1[F.p];
    }
    else if(F.p > 4){
        return F.v2[F.p-5];
    }
} 

int main()
{
    int op, elemento;
    Fila F;
    inicializar(F);
    
    do{
        cout << "selecione a opção: \n";
        cout << "[1]-inserir\n[2]-remover\n[3]-ver se vazio\n[4]-ver se cheio\n[5]-ver primeiro\n[6]-sair\n";
        cin >> op;
        switch(op){
            case 1:{
                cout << "digite o elemento: ";
                cin >> elemento;
                cout << "\n";
                inserir(F,elemento);
                break;
            }
            case 2:{
                remover(F);
                cout << "elemento removido\n";
                break;
            }
            case 3:{
                if(vazio(F)){
                    cout << "fila vazia\n";
                }
                else{
                    cout << "fila não vazia\n";
                }
                break;
            }
            case 4:{
                if(cheio(F)){
                    cout << "fila cheia\n";
                }
                else{
                    cout << "fila não cheia\n";
                }
                break;
            }
            case 5:{
                cout << "o primeiro elemento é: \n"<<primeiro(F);
                break;
            }
            default:
                cout << "opção inválida.\n";
        }
    }while(op != 6);
    
    return 0;
}
