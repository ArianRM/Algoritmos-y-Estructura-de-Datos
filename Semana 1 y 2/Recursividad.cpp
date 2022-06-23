#include <iostream>

using namespace std;

int factorialRecursivo(int n){
    if(n == 0)
        n = 1;
    else
        n *= factorialRecursivo(n-1);
    
    return n;
}

int sumaRecursiva(int n){
    if (n == 1)
        n = 1;
    else
        n += sumaRecursiva(n-1);
    return n;
}

int potenciaRecursiva(int n, int x){
    if (x == 0)
        n = 1;
    else if(x == 1)
        n*=1;
    else
        n *= potenciaRecursiva(n, x-1);
    
    return n;
}

int main(){
    cout << "factorial: " << factorialRecursivo(10) << endl;
    cout << "suma n primeros numeros: " << sumaRecursiva(10) << endl;
    cout << "potencia: " << potenciaRecursiva(10,1) << endl;
    return 0;
}
