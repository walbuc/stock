//
//  articulo.cpp
//  stock
//
//  Created by Walter Buczacka on 5/14/16.
//  Copyright © 2016 Walter Buczacka. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void cargarArchivo(const char ruta[]) {
    
    int id;
    float precio;
    char descripcion[100]; //no lo uso todavia

    FILE *fin = fopen(ruta, "r");
    
    if (fin != NULL) {
        while (fscanf(fin,"%d;%f", &id, &precio) > 0) {
            
            cout << id << " "  << precio ;
        
        }
        
        fclose(fin);
    } else
    {  
        cout << "No se puede abrir el archivo";
    }
}

void cargarMaestroDeArtículos() {

    const char ruta[] = "/Users/walter/Documents/personal-repositories/stock/stock/stock/articulos.db";
    
    cargarArchivo(ruta);
}


