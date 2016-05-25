#include <cstdlib>;
#include <iostream>;
#include <string>;
#include <stdio>;

using namespace std;

#ifndef __SUCURSAL_H__
#define __SUCURSAL_H__
#ifndef NULL
#define NULL 0
#endif


/* Tipo de Estructura Sucursal. */
struct Sucursal {
    int codigoSucursal;
};

void constructor(Sucursal &sucursal)
{
	codigoSucursal = 0;
}

void destructor(Sucursal &sucursal)
{
}

int getCodigoSucursal(Sucursal &sucursal)
{
	return codigoSucursal;
}

void setCodigoSucursal(Sucursal &sucursal, int codigo)
{
	if (codigo >= 0) 
	{
		codigoSucursal = codigo;
	}
}