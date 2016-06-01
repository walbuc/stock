#ifndef sucursal_h
#define sucursal_h


/* Tipo de Estructura Sucursal. */
struct Sucursal {
    int codigoSucursal;
} sucursal;

void constructor(Sucursal &sucursal);

void destructor(Sucursal &sucursal);

int getCodigoSucursal(Sucursal &sucursal);

void setCodigoSucursal(Sucursal &sucursal, int codigo);

#endif sucursal_h
