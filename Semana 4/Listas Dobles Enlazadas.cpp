#include <iostream>

using namespace std;

struct Nodo{
    int dato;
    Nodo* siguiente;
    Nodo* anterior;
};

Nodo *primero, *ultimo;

void insertaNodo(){
    Nodo *nuevo = new Nodo();
    cout << "Ingrese el valor: ";
    cin >> nuevo->dato;
    if(primero == nullptr){
        primero = nuevo;
        primero->siguiente = nullptr;
        primero->anterior = nullptr;
        ultimo = primero;
    }else{
        ultimo->siguiente = nuevo;
        nuevo->siguiente = nullptr;
        nuevo->anterior = ultimo;
        ultimo = nuevo;
    }

    cout << "-Nodo ingresado correctamente-" << endl;
}

void imprimirListaAdelante(){
    Nodo *actual = new Nodo();
    actual = primero;
    if (primero != nullptr){
        while (actual != nullptr){
            cout << actual->dato << " ";
            actual = actual->siguiente;
        }
    }
    else
        cout << "Lista vacía" << endl; 
}

void imprimirListaAtras(){
    Nodo *actual = new Nodo();
    actual = ultimo;
    if (ultimo != nullptr){
        while (actual != nullptr){
            cout << actual->dato << " ";
            actual = actual->anterior;
        }
    }
    else
        cout << "Lista vacía" << endl; 
}

void buscarNodo(){
    Nodo *actual = new Nodo();
    actual = primero;
    bool encontrado = false;
    int buscado = 0;
    cout << "Ingrese dato a buscar";
    cin >> buscado;
    if (primero != nullptr){
        while (actual != nullptr && encontrado != true){
            if(actual->dato == buscado){
                cout << "El dato " << buscado << " fue encontrado" << endl;
                encontrado = true;
            }
            else
                cout << "dato no encontrado" << endl;
            actual = actual->siguiente;
        }
    }
    else
        cout << "Lista vacía" << endl;
}

void modificaNodo(){
    Nodo *actual = new Nodo();
    actual = primero;
    bool encontrado = false;
    int buscado = 0;
    cout << "Ingrese dato a modificar";
    cin >> buscado;
    if (primero != nullptr){
        while (actual != nullptr && encontrado != true){
            if(actual->dato == buscado){
                cout << "El dato " << buscado << " fue encontrado" << endl;
                cout << "Ingrese el nuevo dato";
                cin >> actual->dato;
                cout << "Dato modificado"<< endl;
                encontrado = true;
            }
            else
                cout << "dato no encontrado" << endl;
            actual = actual->siguiente;
        }
    }
    else
        cout << "Lista vacía" << endl;
}

void eliminarNodo(){
    Nodo *actual = new Nodo();
    actual = primero;
    Nodo *previo = new Nodo();
    previo = nullptr;
    bool encontrado = false;
    int buscado = 0;
    cout << "Ingrese dato a eliminar";
    cin >> buscado;
    if (primero != nullptr){
        while (actual != nullptr && encontrado != true){
            if(actual->dato == buscado){
                cout << "El dato " << buscado << " fue encontrado" << endl;
                if(actual == primero){
                    primero = primero->siguiente;
                    primero->anterior = nullptr;
                }
                else if(actual == ultimo){
                    previo->siguiente= nullptr;
                    ultimo = previo;
                }else{
                    previo->siguiente = actual->siguiente;
                    actual->siguiente->anterior = previo;
                }
                cout << "Nodo eliminado";
                delete actual;
                encontrado = true;
            }
            previo = actual;
            actual = actual->siguiente;
        }
        if(!encontrado) cout << "El dato " << buscado << "NO fue encontrado" << endl;
    }
}

int main(){
    insertaNodo();
    insertaNodo();
    insertaNodo();
    insertaNodo();
    imprimirListaAdelante();
    imprimirListaAtras();
    buscarNodo();
    buscarNodo();
    modificaNodo();
    imprimirListaAdelante();
    eliminarNodo();
    imprimirListaAdelante();
    return 0;
}
