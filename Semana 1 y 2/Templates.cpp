#include <iostream>

using namespace std;

template <typename T>
T abs(T a){
    if (a < 0)
        a = a * -1;
    return a;
}

template <typename T>
T suma(T a, T b){
    return a + b;
}

template <typename T>
T resta(T a, T b){
    return a - b;
}

template <typename T>
T multiplicacion(T a, T b){
    return a * b;
}

template <typename T>
T division(T a, T b){
    return a/b;
}

int elegir(){
    int op;
    do{ 
        system("cls");
        cout << "Elija la operacion: " << endl;
        cout << "[1] Suma" << endl;
        cout << "[2] Resta" << endl;
        cout << "[3] Multiplicacion" << endl;
        cout << "[4] Division" << endl;
        cin >> op;
    } while (op < 0 || op > 4);
    return op;
}



int main(){
   int x = -12;
   float y = -123.1421;
   double z = -123.141241;
   cout << abs(x) << endl;
   cout << abs(y) << endl;
   cout << abs(z) << endl;
   int a, b, op;
   op = elegir();
   cout << "Ingrese el primer numero: " ; cin >> a;
   cout << "Ingrese el segundo numero: " ; cin >> b;
   switch (op){
        case 1:
            cout << "La suma de los numero es " << suma(a, b) << endl;
            break;
        case 2: 
            cout << "La resta de los numero es " << resta(a, b) << endl;
            break;
        case 3: 
            cout << "La multiplicacion de los numero es " << multiplicacion(a, b) << endl;
            break;
        case 4: 
            cout << "La division de los numero es " << division(a, b) << endl;
            break;
   }
    return 0;
}
