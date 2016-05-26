#ifndef ADMINESTANTERIA_H
#define ADMINESTANTERIA_H

#include "Lista.h"
#include "Articulo.h"
#include "Pila.h"
#include "Estanteria.h"
#include "Funciones.h"

void configurarEstanteria(Estanteria &estanteria);

void estadoUbicacion(Pila &pilaUbicacion, int piso);

void estadoPiso(Lista &listaPiso);

void imprimirUbicacion(Ubicacion ubicacion);

void imprimirEstanteria(Estanteria &estanteria);









#endif // ADMINESTANTERIA_H
