#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int (*suma1)(int) = [](int num){
        return num + 1;
    };

    int a;
    auto lambda = [a](int num){return num * a;}; // captura la variable insertada

    int x, y;
    auto lambda2 = [&](int num){ //captura todas la variables en el scope y permite su modificacion
        x++;
        y--;
        return num * x * y;
    };

    int m, n;
    auto lambda3 = [=](int num){ //captura las variables pero no permite modificarlas
        return m * num * n;
    };

    vector <int> numeros {1,4,3,2,5,6,9,7};
    sort(numeros.begin(), numeros.end(), [](int a, int b){
        return a < b;
    });

    for_each(numeros.begin(), numeros.end(), [](int i){
        cout << i << " ";
    });
    return 0;
}
