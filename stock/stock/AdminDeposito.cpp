#include "AdminDeposito.h"
#include "Funciones.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>

using namespace std;

void configurarDeposito(Deposito &deposito){

    ifstream fdeposito;
    string dato;

    fdeposito.open("/Users/walter/Documents/personal-repositories/stock/stock/stock/configuracion.conf");

    if (fdeposito.is_open()){

        while (fdeposito.good()){
            getline(fdeposito,dato);
            setCPisos(deposito, cadenaAentero(dato));
            getline (fdeposito, dato);
            setCUbicaciones(deposito, cadenaAentero(dato));
            getline (fdeposito,dato);
            setKc(deposito,cadenaAfloat(dato));
       }

        fdeposito.close();

    }

    else{

        cout << "Error al abrir el archivo configuracion." << endl << endl;

// system ("PAUSE");

    }
}

void imprimirDeposito(Deposito &deposito){
    cout<<"--------------------------------------"<<endl;
    cout<<"Nro Deposito: "<<deposito.nroDeposito<<endl;
    cout<<"Cantidad de Pisos: "<<deposito.cPisos<<endl;
    cout<<"Cantidad de Ubicaciones: "<<deposito.cUbicaciones<<endl;
    cout<<"Kilos por Camion: "<<deposito.kc<<endl;
    cout<<"--------------------------------------"<<endl;



}
