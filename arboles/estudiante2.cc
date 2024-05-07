#include <iostream>
#include <string>
#include <malloc.h>
using namespace std;

struct nodo {
    int codigo;
    char nombre [50];
    char apellido [50];
    int ano_nacimiento;
    int dia_nacimiento;
    int mes_nacimiento;
    
    nodo *izq;
    nodo *der;
}; 

nodo *raiz, *raiz2, *aux, *aux2, *aux3; 

// Función Recursiva para posicionar un nuevo nodo en el árbol
void posicionar(){
    if(aux->ano_nacimiento < aux2->ano_nacimiento){
        if(aux2->izq == NULL){
            aux2->izq = aux;
        } else {
            aux2 = aux2->izq;
            posicionar();
        }
    } else {
        if(aux2->der == NULL){
            aux2->der = aux;
        } else {
            aux2 = aux2->der;
            posicionar();
        }
    }
}

// Función para registrar un nuevo estudiante en el árbol
void registrar(){

//cout<<"-------------------------------------------"<<endl;



    aux = (nodo *) malloc (sizeof(nodo));
    aux3 = (nodo *) malloc (sizeof(nodo));

    cout << "Ingrese el nombre del estudiante: ";
    cin >> aux->nombre;
    cout << "Ingrese el apellido del estudiante: ";
    cin >> aux->apellido;
    cout<<"Ingrese codigo del estudiante";
    cin>> aux->codigo;
    cout << "Ingrese el año de nacimiento del estudiante: ";
    cin >> aux->ano_nacimiento;
    cout << "Ingrese el día de nacimiento del estudiante: ";
    cin >> aux->dia_nacimiento;
    cout << "Ingrese el mes de nacimiento del estudiante: ";
    cin >> aux->mes_nacimiento;

    /*
    aux->nombre;
    aux->apellido;
    aux->codigo;
    aux->ano_nacimiento;
    aux->dia_nacimiento;
    aux->mes_nacimiento;
    
    
    cout<<"-------------------------------------------"<<endl
    cout<<"\t Cargando datos del estudiante..."
    cout<<"-------------------------------------------"<<endl
    cout<<"Nombre :"<<aux->nombre<<endl<<"Apellido: "<<aux->apellido<<endl<<"Codigo: "<<aux->codigo<<endl
    cout<<"Fecha de nacimiento DD/MM/AA"<<aux->dia_nacimiento<<"/"<<aux->mes_nacimiento<<"/"<<aux->ano_nacimiento;<<endl;
    cout<<"-------------------------------------------"<<endl
    
    */

    aux->izq = NULL;
    aux->der = NULL;

    aux3->izq = NULL;
    aux3->der = NULL;

    if(!raiz){
        raiz = aux;
    } else {
        aux2 = raiz;
        posicionar();
    }
}

int datosE (){

    cout<<"-------------------------------------------"<<endl;
    cout<<"\t Cargando datos del estudiante..."<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<<"Nombre: "<<aux->nombre<<endl<<"Apellido: "<<aux->apellido<<endl<<"Codigo: "<<aux->codigo<<endl;
    cout<<"Fecha de nacimiento DD/MM/AA: "<<aux->dia_nacimiento<<"/"<<aux->mes_nacimiento<<"/"<<aux->ano_nacimiento<<endl;
    cout<<"-------------------------------------------"<<endl;

}

bool busqueda(nodo *aux, int codigo){
	if(aux == NULL){
		return false;
	}else if(codigo == aux->codigo){
		return true;
	}else if( codigo < aux->codigo){
		busqueda(aux->izq,codigo);
	}else{
		busqueda(aux->der,codigo);
	}
}

//mostrar en preorden
int mostrarPre(nodo *recursivo){
    
    cout<<"Nombre: "<<recursivo->nombre<<endl<<"Apellido: "<<recursivo->apellido<<endl<<"Codigo: "<<recursivo->codigo<<endl;
    cout<<"Año de nacimiento: "<<recursivo->ano_nacimiento<<endl;
    cout<<"-------------------------------------------"<<endl;
    
    if(recursivo->izq != NULL)
        mostrarPre(recursivo->izq);

    if(recursivo->der != NULL)
        mostrarPre(recursivo->der);
        return 0; 
}


int recorrerArbol(){
    aux = raiz;
    if(aux!=NULL){
        mostrarPre(aux);

    }
    
    if (aux==NULL){
        cout<<"El arbol esta vacio..."<<endl;
        cout<<"-------------------------------------------"<<endl;
    }
}



// Función principal
int main(){
    int dato,opc=0;
    do {
        cout << "1. Registrar" << endl;
        cout << "2. Recorrer Arbol (pre)" << endl;
        cout<<"3. Buscar"<<endl;
        cin >> opc;
        switch (opc)
        {
        case 1: registrar();
            break;

        case 2: 
        cout<<"-------------------------------------------"<<endl;
        cout<<"\t Cargando datos de los estudiantes..."<<endl;
        cout<<"-------------------------------------------"<<endl;
        recorrerArbol();
        break;

        case 3:
        cout<<"Ingrese el codigo del estudiante que desea buscar: "<<endl;
        cin>>dato;
        if(busqueda(aux,dato) == true){
			cout<<"El '"<<dato<<"' SI fue encontrado."<<endl;
            cout<<raiz->nombre<<endl;
            cout<<raiz->codigo<<endl;

            datosE();

			}if(busqueda(aux,dato)==false){
			    cout<<"El codigo: '"<<dato<<"' NO fue encontrado."<<endl;
			    }
        }

        


    } while(opc != 5);

    return 0;
}