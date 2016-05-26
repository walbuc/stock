//
//  main.cpp
//  stock
//
//  Created by Walter Buczacka on 5/14/16.
//  Copyright © 2016 Walter Buczacka. All rights reserved.
//

#include <iostream>
#include "AdminArticulos.h"
#include "lista.h"
#include "funciones.h"
using namespace std;

int main(int argc, const char * argv[]) {
    
    
    Lista listaArticulo;
    Lista listaIndice;
    
    crearLista(listaArticulo, &compararDatoArticulo);
    
    cargarMaestroDeArticulos(listaArticulo, listaIndice);
    
    
    
    cout << "Hello, World!\n";
    return 0;
}
