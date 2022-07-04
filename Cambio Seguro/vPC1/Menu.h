#include <iostream>

using namespace std;

class Menu{
private:
    int opcion;

public:
    Menu(/* args */){}
    ~Menu(){}

    int login(){
        int op;
        do{
            cout << "Bienvenido a Cambio Seguro" << endl << endl;
            cout << "1. Iniciar sesion" << endl;
            cout << "2. Registrarse" << endl;
            cout << "0. Salir" << endl; 
            cin >> op;
        } while (op < 0 || op > 2);
        
    }

    void opciones(){
        cout << "Bienvenido a Cambio Seguro" << endl << endl;
        cout << "1. Depositar dinero" << endl;
        cout << "2. Ver saldo" << endl;
        cout << "3. Cambio de divisas" << endl;
        cout << "4. Retirar saldo" << endl;
        cout << "0. Salir" << endl;
    }
};

