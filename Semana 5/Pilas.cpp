#include <iostream>
#include <conio.h>

using namespace std;
/*
    Concepto de PILA
    - Estructura de datos de entradas ordenadas, tales que solo se pueden introducir y eliminar por un extremo, llamado cima.
    LIFO: Last In First Out
    - operaciones usuales: insertar y quitar
    - insertar(push) añade elemento a la cima de la pila
    - quitar(pop) elimina o saca un elemento de la cima de la pila
*/

struct Nodo{
    int dato;
    Nodo *siguiente;
};

void push(Nodo *&pila, int n){ // agregar elementos a la pila
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;
    cout << "elemento agregado correctamente"<<endl;
}

void pop(Nodo *&pila, int &n){
    Nodo *aux = pila;
    n = aux->dato;
    pila = aux->siguiente;
    delete aux;
}

void imprimePila(Nodo *&pila) {
	Nodo* aux = pila;
	while (aux != nullptr) {
		if (aux != nullptr)
            cout << aux->dato << "|";
        else
            cout << aux->dato << ".";
		aux = aux->siguiente;
	}
}

void quitaTodos(Nodo*& pila, int &n) {
	Nodo* aux = pila;
	while (aux != nullptr)
		pop(aux, n);
}

int main(){
    Nodo *pila = nullptr;
    char op;
    int dato;

    cout << "Ingrese un dato: ";
    cin >> dato;
    push(pila, dato);
    
    cout << "Ingrese un dato: ";
    cin >> dato;
    push(pila, dato);
    
    cout << "Ingrese un dato: ";
    cin >> dato;
    push(pila, dato);

    cout << "-- DATOS DE LA PILA --" << endl;
    imprimePila(pila);
    quitaTodos(pila, dato);
    imprimePila(pila);
    
    getch();
    return 0;
}
