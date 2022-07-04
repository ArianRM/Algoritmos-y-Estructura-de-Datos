#include <iostream>

using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

bool colaVacia(Nodo *f){
    if (f == nullptr) return true;
    else return false;
}

void agregaNodo(Nodo *&frente, Nodo *&fin, int dato){
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = nullptr;
    if (colaVacia(frente))
        frente = nuevoNodo;
    else 
        fin->siguiente = nuevoNodo;
    fin = nuevoNodo;
    cout << "Insercion correcta" << endl;
}

void imprimeCola(Nodo *frente){
    Nodo *actual = frente;
    while(actual!=nullptr){
        cout << actual->dato << " ";
        actual = actual->siguiente;
    }       
}

void eliminarNodo(Nodo *&frente, Nodo *&fin, int &d){
    d = frente->dato;
    Nodo *actual = frente;
    if (frente == fin){
        frente = nullptr;
        fin = nullptr;
    }else{
        frente = frente->siguiente;
    }
    delete actual;
}

void quitaTodo(Nodo *&frente, Nodo *&fin, int d){
    Nodo *actual = frente;
    while (actual != nullptr){
        cout << actual->dato << " ";
        eliminarNodo(actual, fin, d);
    }
    
}

int main(){
    Nodo *frente = nullptr;
    Nodo *fin = nullptr;
    int numero;
    cout << "Numero: "; cin >> numero;
    agregaNodo(frente, fin, numero);
    cout << "Numero: "; cin >> numero;
    agregaNodo(frente, fin, numero);
    cout << "Numero: "; cin >> numero;
    agregaNodo(frente, fin, numero);
    cout << "Numero: "; cin >> numero;
    agregaNodo(frente, fin, numero);
    imprimeCola(frente);
    cout << "Dato a eliminar";
    cin >> numero;
    eliminarNodo(frente, fin, numero);
    imprimeCola(frente);
    quitaTodo(frente, fin, numero);
    imprimeCola(frente);
    return 0;
}
