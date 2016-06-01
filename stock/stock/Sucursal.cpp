#include <cstdlib>
#include <iostream>
#include <string>
#include "Sucursal.h"


using namespace std;

#ifndef __SUCURSAL_H__
#define __SUCURSAL_H__
#ifndef NULL
#define NULL 0
#endif



void constructor(Sucursal &sucursal)
{
	sucursal.codigoSucursal = 0;
}

void destructor(Sucursal &sucursal)
{
}

int getCodigoSucursal(Sucursal &sucursal)
{
	return sucursal.codigoSucursal;
}

void setCodigoSucursal(Sucursal &sucursal, int codigo)
{
	if (codigo >= 0) 
	{
		sucursal.codigoSucursal = codigo;
	}
}
#endif __SUCURSAL_H__
