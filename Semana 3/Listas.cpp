#include <iostream>

using namespace std;


struct Nodo{
    int dato;
    Nodo *siguiente;
};

Nodo *lista;
void insertarNodo(int dato){
    Nodo *nodoNuevo = new Nodo();
    nodoNuevo->dato = dato;
    Nodo *aux1 = lista;
    Nodo *aux2;

    while (aux1 != nullptr && aux1->dato<=dato){
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }
    
    if (aux1 == lista)
        lista = nodoNuevo;
    else 
        aux2->siguiente = nodoNuevo;
    nodoNuevo->siguiente = aux1;
}

void imprimeLista(){
    Nodo *actual = new Nodo();
    actual = lista;
    while(actual!=nullptr){
        cout << actual->dato << " ";
        actual = actual->siguiente;
    }
}

void buscarElemento(int datoBuscado){
    bool resultado = false;
    Nodo *actual = new Nodo();
    actual = lista;
    while (actual != nullptr && actual->dato <= datoBuscado){
        if (actual->dato == datoBuscado)
            resultado = true;
        actual = actual->siguiente;
    }
    
    if(resultado == false)
        cout << "El dato no existe" << endl;
    else
        cout << "El dato existe" << endl;
}

void eliminarNodo(int datoEliminado){
    if(lista != nullptr){
        Nodo *ptrBorrar;
        Nodo *anterior = nullptr;
        ptrBorrar = lista;
        while (ptrBorrar != nullptr && ptrBorrar->dato != datoEliminado){
            anterior = ptrBorrar;
            ptrBorrar = ptrBorrar->siguiente;
        }
        
        if(ptrBorrar == nullptr)
            cout << "elemento no encontrado" << endl;
        else if(anterior == nullptr){
            lista = lista->siguiente;
            delete ptrBorrar;
        }
        else{
            anterior->siguiente = ptrBorrar->siguiente;
            delete ptrBorrar;
        }
    }
    cout << "Dato eliminado" <<endl;
}

int main(){
    insertarNodo(1);
    insertarNodo(2);
    insertarNodo(3);
    insertarNodo(4);
    imprimeLista();
    buscarElemento(4);
    buscarElemento(15);
    eliminarNodo(4);
    imprimeLista();
    return 0;
}
