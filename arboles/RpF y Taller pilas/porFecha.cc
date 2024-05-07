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

nodo *raiz, *aux, *aux2, *aux3; 

// Función Recursiva para posicionar un nuevo nodo en el árbol general
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
    
    cout<<""<<endl;
    cout<<"Ingrese el nombre del estudiante: "<<endl;
    cout<<"--> ";cin>>aux->nombre;cout<<""<<endl;
    cout<<"Ingrese el apellido del estudiante: "<<endl;
    cout<<"--> ";cin>>aux->apellido;cout<<""<<endl;
    cout<<"Ingrese codigo del estudiante: "<<endl;
    cout<<"--> ";cin>>aux->codigo;cout<<""<<endl;
    cout<<"Ingrese el año de nacimiento del estudiante: "<<endl;
    cout<<"--> ";cin>>aux->ano_nacimiento;cout<<""<<endl;
    cout<<"Ingrese el día de nacimiento del estudiante: "<<endl;
    cout<<"--> ";cin>>aux->dia_nacimiento;cout<<""<<endl;
    cout<<"Ingrese el mes de nacimiento del estudiante: "<<endl;
    cout<<"--> ";cin>>aux->mes_nacimiento;

    cout<<"-------------------------------------------"<<endl;
    cout<<"     ¡Estudiante registrado con exito!     "<<endl;
    cout<<"-------------------------------------------"<<endl;


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

bool busqueda(nodo *raiz, int codigo){
	if(raiz == NULL){
		return false;
	}else if(codigo == raiz->codigo){
		return true;
	}else if( codigo < raiz->codigo){
		return busqueda(raiz->izq,codigo);
	}else{
		return busqueda(raiz->der,codigo);
	}
}

/*    Arbol de ejemplo

             45               inorden: 1, 2, 7, 45, 65
         2           65       preorden: 45, 2, 1, 7, 65                                                                   
     1      7                 postorden: 1, 7, 2, 65, 45
                                                           */

//mostrar en preorden - primero imprime la raiz, que en este caso lleva por parametro el nodo apuntador recursivo
// despues busca a profundidad por el subarbol izquierdo y por ultimo al lado derecho 

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

//recorrer en preorden - si la raiz es diferente de NULL llama a la funcion principal que muestra en preorden, sino el arbol estará vacío
int recorrerArbolF(){
    aux = raiz;
    if(aux!=NULL){
        mostrarPre(aux);
        }
    
    if (aux==NULL){
        cout<<"El arbol esta vacio..."<<endl;
        cout<<"-------------------------------------------"<<endl;
        }
    }

//mostrar en inorden (ATS) - busca a profundidad el subarbol izquierdo, imprime la raiz y por ultimo pasa al lado derecho

void inorden(nodo *raiz){

    if(raiz!=NULL){

        inorden(raiz->izq);
        
        cout<<"Nombre: "<<raiz->nombre<<endl<<"Apellido: "<<raiz->apellido<<endl<<"Codigo: "<<raiz->codigo<<endl;
        cout<<"Año de nacimiento: "<<raiz->ano_nacimiento<<endl;
        cout<<"-------------------------------------------"<<endl;
        
        inorden(raiz->der);
        
        }
    }

//mostrar en postorden (ATS) busca a profundidad el subarbol izquierdo, pasa al derecho y por ultimo imprime la raiz

void postorden(nodo *raiz){
    if(raiz != NULL){

        postorden(raiz->izq);
        
        postorden(raiz->der);
                
        cout<<"Nombre: "<<raiz->nombre<<endl<<"Apellido: "<<raiz->apellido<<endl<<"Codigo: "<<raiz->codigo<<endl;
        cout<<"Año de nacimiento: "<<raiz->ano_nacimiento<<endl;
        cout<<"-------------------------------------------"<<endl;
    }

}


// Función principal
int main(){

    //cout<<"-------------------------------------------"<<endl;

    int dato,opc=0;
    cout<<"\n";
    cout<<"-------------------------------------------"<<endl;
    cout<<"|        BIENVENIDO AL PROGRAMA DE        |"<<endl;
    cout<<"|         REGISTRO DE ESTUDIANTES         |"<<endl;
    cout<<"-------------------------------------------"<<endl;



    do {
        cout<<"\n\n";
        cout<<"-------------------------------------------"<<endl;
        cout<<"¿Que desea realizar?"<<endl;
        cout<<"-------------------------------------------"<<endl;
        cout<<"\t 1. Registrar"<<endl;
        cout<<"\t 2. Recorrer Arbol (pre)"<<endl;
        cout<<"\t 3. Recorrer Arbol (in)"<<endl;
        cout<<"\t 4. Recorrer Arbol (post)"<<endl;
        cout<<"\t 5. Buscar"<<endl;
        cout<<"\t 9. Salir"<<endl;
        cout<<"-------------------------------------------"<<endl;
        cout<<"--> ";cin>>opc;cout<<"";
        cout<<"-------------------------------------------"<<endl;
        
        
        switch (opc)
        {
            case 1: registrar();
            break;

            case 2: 
            cout<<"\n";
            cout<<"-------------------------------------------"<<endl;
            cout<<"    Cargando datos de los estudiantes...   "<<endl;
            cout<<"-------------------------------------------"<<endl;
            recorrerArbolF();
            break;

            case 3:
            cout<<"\n";
            cout<<"-------------------------------------------"<<endl;
            cout<<"    Cargando datos de los estudiantes...   "<<endl;
            cout<<"-------------------------------------------"<<endl;
            inorden(raiz);
            break;

        
            case 4:
            cout<<"\n";
            cout<<"-------------------------------------------"<<endl;
            cout<<"    Cargando datos de los estudiantes...   "<<endl;
            cout<<"-------------------------------------------"<<endl;
            postorden(raiz);
            break;

        
            case 5:
            cout<<"\n";
            cout<<"-------------------------------------------"<<endl;
            cout<<"Ingrese el codigo del estudiante que desea buscar: "<<endl;
            cout<<"-->";cin>>dato;
            cout<<"-------------------------------------------"<<endl;

            if(busqueda(raiz,dato)){
                cout<<"\t El codigo '"<<dato<<"' SI fue encontrado."<<endl;

                nodo *estudiante = raiz;
                while (estudiante != NULL) {
                if (estudiante->codigo == dato) {
                    cout << "Nombre: " << estudiante->nombre << endl;
                    cout << "Apellido: " << estudiante->apellido << endl;
                    cout << "Codigo: " << estudiante->codigo << endl;
                    cout << "Fecha de nacimiento: " << estudiante->dia_nacimiento << "/" << estudiante->mes_nacimiento << "/" << estudiante->ano_nacimiento << endl;
                break;
            } else if (dato < estudiante->codigo) {
                estudiante = estudiante->izq;
            } else {
                estudiante = estudiante->der;
            }
        }

            }else{
			    cout<<"El codigo: '"<<dato<<"' NO fue encontrado."<<endl;
			    }
            break;
        
        }

    } while(opc != 9);

    return 0;
}