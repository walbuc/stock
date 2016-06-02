#ifndef ADMINCAMIONES_H
#define ADMINCAMIONES_H
#include "Lista.h"
#include "Camion.h"
#include "Deposito.h"

void configurarKcCamion(Camion &camion,float kc);

void cargarCamiones(Deposito &deposito, Lista &listaSolicitudes, Lista &listaCamiones);

void listarCamiones (Lista &listaCamiones);

void utilizacionCamiones(Lista &listaCamiones);


#endif // ADMINCAMIONES_H
