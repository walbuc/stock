#ifndef ADMINDEPOSITO_H
#define ADMINDEPOSITO_H
#include "Deposito.h"
#include "Estanteria.h"
#include "Piso.h"
#include "lista.h"
#include "funciones.h"

void configurarDeposito(Deposito &deposito);
void imprimirDeposito(Deposito &deposito);
void saldosDetallados (Deposito &deposito);
void saldosAgrupados (Deposito &deposito);

#endif // ADMINDEPOSITO_H
