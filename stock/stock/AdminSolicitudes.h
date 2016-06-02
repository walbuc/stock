


#ifndef AdminSolicituides_h
#define AdminSolicitudes_h

#include "lista.h"
#include "cola.h"
#include "solicitud.h"
#include "funciones.h"

PtrNodoLista crearSolicitud(Lista &listaSolicitudes,int idSucursal, int idArticuloSucursal, float cantidadSucursal, float cantidadCumplida);

PtrNodoCola crearPendiente(Cola &colaPendiente, int idSucursal, int idArticuloSucursal, float cantidadSucursal, float cantidadCumplida);

void estadoListaSolicitud(Lista &listaSolicitud);

void estadoColaPendiente(Cola &colaPendiente);

void imprimirSolicitud(Solicitud &solicitud);

#endif /* AdminSolicitud_h */
