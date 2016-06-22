#ifndef ADMINDEPOSITO_H
#define ADMINDEPOSITO_H
#include "Deposito.h"
#include "Cola.h"

string procesaString(string dato);
void configurarDeposito(Deposito &deposito);
void imprimirDeposito(Deposito &deposito);

void saldosDetallados (Deposito &deposito);
void saldosAgrupados (Deposito &deposito);
void escribirFaltantes(Cola &colaPendiente);
void escribirVentas(Lista &listaSolicitud);
void ordenarListaCamion(Lista &listaCamiones);
void utilizacionDeCamiones(Lista &listaCamiones);
#endif // ADMINDEPOSITO_H
