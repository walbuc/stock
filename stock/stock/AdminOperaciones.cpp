//
//  AdminOperaciones.cpp
//  stock
//
//  Created by Walter Buczacka on 5/25/16.
//  Copyright © 2016 Walter Buczacka. All rights reserved.
//

#include "AdminOperaciones.h"
#include "fstream"
#include <iostream>
#include <stdio.h>

using namespace std;

void leerArchivosOperaciones(){
    
    ifstream fingresos, fsolicitudes;
    string dato;
    int idCodigo, hora, minuto, segundo;
    float cantidad;
    
    fingresos.open("ingresos.db");
    fsolicitudes.open("solicitudes.db");
    
    if (fingresos.is_open() && fsolicitudes.is_open()){
        
        while (fingresos.good() && fsolicitudes.good()){
            
            getline(fingresos,dato,';');
            idCodigo = cadenaAentero(dato);
            
            getline(fingresos,dato,';');
            cantidad = cadenaAfloat(dato);
            
            getline(fingresos,dato,':');
            hora = cadenaAentero(dato);
            
            getline(fingresos,dato,':');
            minuto = cadenaAentero(dato);
            
            getline(fingresos,dato);
            segundo = cadenaAentero(dato);
            
            
            
        }
        
        fingresos.close();
        
    }
    
    else{
        
        cout << "Error al abrir los archivos." << endl << endl;
        
        system ("PAUSE");
        
    }
}