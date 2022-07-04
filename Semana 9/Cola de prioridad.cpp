#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

class CColaPrioridad{
private:
    int vector[1000];
    int t;
public:
    CColaPrioridad(int *a, int n){
        for (int i = 0; i < n; i++){
            vector[i] = a[i];
        }
        t = n;
        buildMaxHeap(vector, t);
    }
    ~CColaPrioridad(){}
    // 1. comportamientos para el heap
    int padre(int i){return (i-1)/2;}
    int izquierda(int i){return 2*i+1;}
    int derecha(int i){return 2*i+2;}
    // amontonamiento
    void maxHeapify(int a[], int n, int i){
        int l = izquierda(i);
        int r = derecha(i);
        int largest(0);
        if (l <= (n - 1) && a[l] > a[i]) largest = 1;
        else largest = i;
        if (r <= (n-1) && a[r] > a[largest]) largest = r;
        if (largest != i){
            swap(a[i], a[largest]);
            maxHeapify(a, n, largest);
        }
    }
    // amontonamiento de todos los datos por el maximo
    void buildMaxHeap(int a[], int n){
        for (int i = n/2-1; i >= 0; --i){
            maxHeapify(a, n, i);
        }
    }
    // comportamientos para la cola de prioridad
    // imprime datos de la fuente
    void imprimeDatos(int a[], int n){
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
    }
    void heapSort(int a[], int n){
        buildMaxHeap(a, n);
        for (int i = n - 1; i > 0; --i){
            swap(a[0], a[i]);
            maxHeapify(a, --n, 0);
        }
        
    }

    // meter un elemento
    void insertaElemento(int elemento){
        t++;
        vector[t-1] = elemento;
        int i = t - 1;
        while(i > 0 && vector[padre(i)] < vector[i]){
            swap(vector[i], vector[padre(i)]);
            i = padre(i);
        }
    }

    // obtener el elemento maximo
    int maximaPrioridad(){
        if (t <= 0){
            cout << "no hay datos";
            return -1;
        }
        return vector[0];
    }

    // eliminar el elemento con maxima prioridad
    int eliminaMaximo(){
        if(t <= 0){
            cout << "no hay datos";
            return -1;
        }
        int max = vector[0];
        vector[0] = vector[t - 1];
        t--;
        maxHeapify(vector, t, 0);
        return max;
    }
    // reemplaza el i-esimo elemento por un nuevo elemento
    void increase_key(int i, int nelemento){
        vector[i] = max(vector[i], nelemento);
        while(i>0 && vector[padre(i)] < vector[i]){
            swap(vector[padre(i)], vector[i]);
            i = padre(i);
        }
    }
    // imprimir datos del monticulo
    void imprimeMonticulo(){
        for (int i = 0; i < t; i++){
            cout << vector[i] << " ";
        }
        cout << endl;
    }
};




int main(){
    int a[] = {2, 10, 8, 7, 3, 19, 4, 1};
    int n = 8;
    int temp;
    CColaPrioridad qp(a, n);
    qp.imprimeDatos(a, n);
    cout << endl;
    qp.imprimeMonticulo();
    cout << "\nmaximo: " << qp.maximaPrioridad() << endl;
    temp = 105;
    qp.insertaElemento(temp);
    cout << "\n despues de meter: " << temp << endl;
    cout << "\nmaximo: " << qp.maximaPrioridad() << endl;
    return 0;
}