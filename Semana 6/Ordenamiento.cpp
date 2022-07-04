#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void impresionDatos(vector <T> vec){
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
}

template <typename T>
void intercambio(T *a, T *b){
    char tmp = *a;
    *a = *b;
    *b = tmp;
}
// Desordenamieto fisher yattes
template <typename T>
void fisherYattes(vector <T> vec){
    for (int i = 0; i < 5; i++){
        srand(time(nullptr));
        int j = rand() % (i + 1);
        intercambio(&vec[j], &vec[i]);
    }
    impresionDatos(vec);
}

// ordenamiento por intecambio
template <typename T>
void ordenamientoIntercambio(vector <T> vec, int n){
    for (int i = n - 1; i > 0; i--){
        for (int j = i - 1; j >= 0; j--){
           if (vec[i]<vec[j]){
                intercambio(&vec[i], &vec[j]);
           }
        }
    }
    impresionDatos(vec);
}

// ordenamiento burbuja
template <typename T>
void ordenamientoBurbuja(vector <T> vec, int n){
    int c = 0;
    bool ordenado;
    for (int i = 0; i < n-1; i++){
        ordenado = true;
        for (int j = 0; j < n-i-1; j++){
           if (vec[j]<vec[j+1]){
                intercambio(&vec[j], &vec[j+1]);
                c++;
                ordenado = false;
           }
        }
        if (ordenado == true) break;
    }
    impresionDatos(vec);
    cout << "cantidad de intercambios: " << c << endl;
}

// ordenamiento por seleccion
template <typename T>
void selectionSort(vector <T> vec, int n){
    int c = 0;
    int k, menor;
    for (int i = 0; i < n - 1; i++){
        k = i;
        menor = vec[i];
        for (int j = i + 1; j < n; j++){
            if (vec[j] < menor){
                menor = vec[j];
                k = j;
            }
        }
        vec[k] = vec[i];
        vec[i] = menor;
        c++;
    }
    impresionDatos(vec);
    cout << "cantidad de intercambios: " << c << endl;
}

// ordenamiento por insecion
template <typename T>
void insertionSort(vector <T> vec, int n){
    int c = 0;
    int k, aux;
    for (int i = 1; i < n; i++){
        aux = vec[i];
        k = i - 1;
        while(k>=0 && aux < vec[k]){
            vec[k + 1] = vec[k];
            k--;
        }
        vec[k + 1] = aux;
        c++;
    }
    impresionDatos(vec);
    cout << "cantidad de intercambios: " << c << endl;
}

template <typename T>
void shellSort(vector <T> vec, int n){
    int c = 0;
    int i, j, k, aux;
    int intervalo = n/2;
    while (intervalo>0){
        for (i = intervalo; i < n; i++){
            j = i - intervalo;
            while (j >= 0){
                k = j + intervalo;
                if(vec[j] <= vec[k]){
                    j = -1;
                }else{
                    aux = vec[j];
                    vec[j] = vec[k];
                    vec[k] = aux;
                    j = j - intervalo;
                    c++;
                }
            }
        }
        intervalo = intervalo / 2;
    }
    impresionDatos(vec);
    cout << "cantidad de intercambios: " << c << endl;
}

int main(){
    vector <int> barajas = {16,23,98,56,19,34,63,69,33,14,34,89,58,67,39,61,47,96,77,79};
    int t = 20;
    cout << "\n- DesOrdenamiento Fisher Yattes -" << endl;
    fisherYattes(barajas);
    cout << "\n- Ordenamiento por intercambio -" << endl;
    ordenamientoIntercambio(barajas , t);
    cout << "\n- Ordamiento burbuja -" << endl;
    ordenamientoBurbuja(barajas, t);
    cout << "\n- Ordamiento por seleccion -" << endl;   
    selectionSort(barajas, t);
    cout << "\n- Ordamiento por insercion -" << endl;  
    insertionSort(barajas, t);
    cout << "\n- Ordenamiento Shell -" << endl;
    shellSort(barajas, t);
    return 0;
}
