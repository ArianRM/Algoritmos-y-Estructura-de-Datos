#include <iostream>

using namespace std;

template <typename T>
int suma(T a, T b){ return a + b; }

template <typename T>
int resta(T a, T b){ return a - b; }

template <typename T>
int multiplicacion(T a, T b){ return a * b; }

template <typename T>
int division(T a, T b){ return a/b;}

template <typename T>
void calcular(T (*operacion)(T,T), T x, T y){
    cout << operacion(x, y) << endl;
}

int main(){
    int (*operacion[4]) (int, int);
    int x, y, opcion;
    operacion[0] = suma;
    operacion[1] = resta;
    operacion[2] = multiplicacion;
    operacion[3] = division;


    cout << "Elija la operacion: " << endl;
    cout << "[1] Suma" << endl;
    cout << "[2] Resta" << endl;
    cout << "[3] Multiplicacion" << endl;
    cout << "[4] Division" << endl;
    cin >> opcion;

    cout << "Ingrese los numeros :";
    cin >> x >> y;
    switch (opcion){
    case 1:
        calcular(operacion[0], x, y);
        break;
    case 2:
        calcular(operacion[1], x, y);
        break;
    case 3:
        calcular(operacion[2], x, y);
        break;
    case 4:
        calcular(operacion[3], x, y);
        break;
    }
    
    return 0;
}
