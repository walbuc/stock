//
//  main.cpp
//  stock
//
//  Created by Walter Buczacka on 5/14/16.
//  Copyright © 2016 Walter Buczacka. All rights reserved.
//

#include <iostream>
#include "AdminArticulos.h"
#include "AdminEstanteria.h"
#include "lista.h"
#include "funciones.h"
#include "estanteria.h"
#include "Articulo.h"
using namespace std;

int main(int argc, const char * argv[]) {
    
    
    Lista listaArticulo;
    crearLista(listaArticulo, &compararDatoArticulo);
    
    cargarMaestroDeArticulos(listaArticulo);
    
    Estanteria estanteria;
    construirEstanteria(estanteria);
    
    configurarEstanteria(estanteria);
    imprimirEstanteria(estanteria);//imprime el nro de calle, cantidad de pisos y ubicaciones, y Kilos por camion
    
    
    
    
    cout << "Hello, World!\n";
    return 0;
}
