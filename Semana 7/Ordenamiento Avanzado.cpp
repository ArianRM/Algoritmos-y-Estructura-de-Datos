#include <iostream>

using namespace std;

void imprimirDatos(int *v, int n){
    for (int i = 0; i < n; i++){
       cout << v[i] << " ";
    }
    
}

void merge(int *v1, int *v2, int *v, int n){
    int i=0, j=0, k=0;
    int mitad = n / 2;
    while(i < mitad && j<= n-mitad){
        if(v1[i] < v2[j]){
            v[k] = v1[i];
            i++; k++;
        }else{
            v[k] = v2[j];
            j++; k++;
        }
    }
    while(i < mitad){
        v[k] = v1[i];
        i++;
        k++;
    }
     while(j < n-mitad){
        v[k] = v2[j];
        j++;
        k++;
    }
}

void mergeSort(int *v, int n){
    if(n>1){
        int mitad = n / 2;
        int *v1 = new int[mitad];
        int *v2 = new int[n - mitad];
        for (int i = 0; i < mitad; i++){
            v1[i] = v[i];
        }
        for (int i = mitad; i < n; i++){
            v2[i-mitad] = v[i];
        }
        mergeSort(v1, mitad);
        mergeSort(v2, n - mitad);
        merge(v1, v2, v, n);
    }
}


int main(){
    int v[] = {16,23,98,56,19,34};
    int n = 6;
    mergeSort(v, n);
    imprimirDatos(v, n);
    return 0;
}
