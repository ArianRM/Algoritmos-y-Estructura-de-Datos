#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

void escribirTXT(string nombreArchivo, string nombres, string apellidos, string Madre, string Padre, string Hora, string Fecha, string Lugar){
    ofstream archivo;
    // abriendo el archivo y seteandolo para que escriba un output/ para añadir datos cambiar el out por el app
    archivo.open(nombreArchivo.c_str(), ios::app); 
    if (archivo.fail()){// si falla
        cout << "no se pudo abrir el archivo" << endl;
        exit(1);
    }
    archivo << "---- REGISTRO DE NACIMIENTO ----" << endl;
    archivo << "[Nombre del bebé:" << nombres  << "]" << endl;
    archivo << "[Apellidos del bebé:" << apellidos  << "]" << endl;
    archivo << "[Madre del bebé:" << Madre  << "]" << endl;
    archivo << "[Padre del bebé:" << Padre  << "]" << endl;
    archivo << "[Hora de nacimiento:" << Hora  << "]" << endl;
    archivo << "[Fecha de nacimiento:" << Fecha  << "]" << endl;
    archivo << "[Lugar de nacimiento:" << Lugar  << "]" << endl;
    cout << "REGISTRO CREADO CORRECTAMENTE" << endl;
    archivo.close(); // cerramos el archivo
}

void lecturaTXT(string nombreArchivo){
    ifstream archivo;
    string text;
    archivo.open(nombreArchivo.c_str(), ios::in);
    if (archivo.fail()){// si falla
        cout << "no se pudo abrir el archivo" << endl;
        exit(1);
    }
    while (!archivo.eof()){ //mientras no sea el final del archivo
        getline(archivo, text);
        cout << text << endl;
    }
    archivo.close(); // cerramos el archivo
    
}

int main(){
    string nombreArchivo, nombres, apellidos, Madre, Padre, Hora, Fecha, Lugar;
    int nBebes, i = 1;
    char op;
    cout << "Ingrese el nombre del registro: ";
    getline(cin, nombreArchivo);
    do
    {
        cout << " --- BEBE " << i << " --- " << endl;
        cout << "Nombres del bebé: "; getline(cin, nombres);
        cout << "Apellidos del bebé: "; getline(cin, apellidos);
        cout << "Madre del bebé: "; getline(cin, Madre);
        cout << "Padre del bebé: "; getline(cin, Padre);
        cout << "Hora de nacimiento: "; getline(cin, Hora);
        cout << "Fecha de nacimiento: "; getline(cin, Fecha);
        cout << "Lugar de nacimiento: "; getline(cin, Lugar);  
        escribirTXT(nombreArchivo, nombres, apellidos, Madre, Padre, Hora, Fecha, Lugar);
        i++;
        cout << "Desea agregar otro bebe?(y/n);"; cin >> op;
    } while (op != 'n');
    lecturaTXT(nombreArchivo);
    return 0;
}
