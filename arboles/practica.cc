/**/

#include <iostream>
#include <malloc.h>
using namespace std;


struct arbol{

    int val = 0;
    arbol *izq;
    arbol *der;
};

arbol *raiz, *aux, *aux2;


int posicionar (){
    if(aux->val < aux2->val){
        if(aux2->izq != NULL){
            aux2 = aux2->izq;
            posicionar();

        }else 
        aux2->izq = aux;

    }else if(aux->val > aux2->val){
            if(aux2->der != NULL){
                aux2 = aux2->der;
                posicionar();
            }else
            aux2->der = aux;
        }
}


int registrar(){

    aux = (struct arbol *) malloc (sizeof(struct arbol));
    cout<<"Ingrese Valor: "<<endl;
    cin>>aux->val;

    aux->izq = aux->der = NULL;

    if(raiz == NULL){
        raiz = aux;
        aux = NULL;
        free(aux);
    }else {
        aux2 = raiz;
        posicionar();
    }
    
};




int preorden(arbol *recursivo){
    cout<<"Valor "<<recursivo->val<<endl;
    
    if(recursivo->izq != NULL)
        preorden(recursivo->izq);

    if(recursivo->der != NULL)
        preorden(recursivo->der);
        return 0;
    }


int recorrerArbol(){
    aux = raiz;
    if(aux!=NULL){
        preorden(aux);

    }
}

int main(){

    int opc = 0;

    do
    {
        cout<<"1. Registrar Nodo"<<endl;
        cout<<"2. Recorrer Arbol preorden"<<endl;
        cout<<"3. Salir"<<endl;
        cin>>opc;

        switch (opc)
        {
        case 1:
            registrar();
            break;

        case 2:
            recorrerArbol();
            break;
        
        default:
            break;
        }
    } while (opc!=3);
    
    return 0;
}