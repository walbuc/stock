//
//  AdminArticulos.cpp
//  stock
//
//  Created by Walter Buczacka on 5/23/16.
//  Copyright © 2016 Walter Buczacka. All rights reserved.
//

#include <stdio.h>
#include "AdminArticulos.h"
#include "fstream"
#include <iostream>

using namespace std;

void cargarArticulos(Lista &listaArticulos){
    
    ifstream farticulos;
    string dato;
    
    farticulos.open("articulos.db");
    
    if (farticulos.is_open()){

        while (farticulos.good()){
            
            //new devuelve puntero al tipo de dato
            Articulo* ptrArticulo = new Articulo;
            
            constructor(*ptrArticulo);
            
            getline(farticulos,dato,';');
            
            setCodigoArticulo(*ptrArticulo, cadenaAentero(dato));

            getline (farticulos, dato,';');
            
            setPrecioArticulo(*ptrArticulo, cadenaAfloat(dato));
            
            getline (farticulos,dato);
            
            setDescripcionArticulo(*ptrArticulo, dato);

            adicionarFinal(listaArticulos, ptrArticulo);
            
        }
        
        farticulos.close();
        
    }
    
    else{
        
        cout << "Error al abrir el archivo." << endl << endl;
        
        system ("PAUSE");
        
    }
}


void cargarMaestroDeArticulos(Lista &listaArticulos) {
    
    cargarArticulos(listaArticulos);
    
    
}
