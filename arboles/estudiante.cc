/*Definir la estructura del árbol.
Registrar los datos del nodo.
Ubicar el nodo dentro del árbol por código.
Ubicar el nodo dentro del árbol por fecha.
Plantear al menos un recorrido en uno de los arboles por cualquier método.  
Hacer el primer commit */


#include <iostream>
#include <malloc.h>
using namespace std;

struct Restudiantes
{
    char nombre[50];
    char apellido[50];

    int codigo=0;
    int dia=0;
    int mes=0;
    int año=0;

    Restudiantes *izq;
    Restudiantes *der;

};

Restudiantes *raiz, *aux, *aux2;


int Registro(){
    aux = (Restudiantes *) malloc (sizeof(Restudiantes));

    cout<<"Ingrese Codigo: "<<endl;
    cin>>aux->codigo;
    cout<<"Ingrese Nombre: "<<endl;
    cin>>aux->nombre;
    cout<<"Ingrese Apellido: "<<endl;
    cin>>aux->apellido;
    cout<<"Ingrese Dia: "<<endl;
    cin>>aux->dia;
    cout<<"Ingrese Mes: "<<endl;
    cin>>aux->mes;
    cout<<"Ingrese Año: "<<endl;
    cin>>aux->año;

    aux->izq = aux->der = NULL;
    return 0;
}


int Buscar(){

    int code;

    aux = raiz;


    cout<<"Ingrese Codigo del Estudiante que Desea Buscar: "<<endl;
    cin>>code;

    if(raiz==NULL){
        cout<<"No hay ningun registro actualmente"<<endl;
    }

    if(raiz!=NULL){
        if(aux->codigo == code){
        cout<<"Codigo: "<<aux->codigo<<endl;
        cout<<"Nombre: "<<aux->nombre<<endl;
        cout<<"Apellido: "<<aux->apellido<<endl;
        cout<<"Dia: "<<aux->dia<<endl;
        cout<<"Mes: "<<aux->mes<<endl;
        cout<<"Año: "<<aux->año<<endl;
        }
    
        if(aux->codigo != code){
        cout<<"No se encontro el codigo"<<endl;
        }
    }
    return 0;
}





int main(){
    int opc = 0;
    

    cout<<"\t Bienvenido al Sistema de Registro"<<endl<<" "<<endl;


    do
    {
        cout<<"Menu"<<endl;
        cout<<"1. Registrar Alumno"<<endl;
        cout<<"2. Buscar Alumno"<<endl;
        cout<<"3. Listar Alumnos"<<endl;
        cout<<"4. Eliminar Alumno"<<endl;
        cout<<"5. Salir"<<endl;
        cin>>opc;


        switch (opc){

            case 1:
                Registro();
                break;
            case 2:
                Buscar();
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                cout<<"Opcion Invalida"<<endl;

        }
    } while (opc!=5);
    
}