#include "Camion.h"

/* Implementación de Primitivas */

/*-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- */

void crearCamion(Camion &camion){

	camion.nroCamion=0;
	camion.kgCapacidad=0;
	camion.cargaTotal=0.0;
	camion.porcentajeOcupado=0.0;
}
void destruirCamion(Camion &camion){}

void setNroCamion(Camion &camion, int dato){

camion.nroCamion=dato;

}

void setKGcapacidad(Camion &camion, float dato){

camion.kgCapacidad=dato;

}

void setCargaTotal(Camion &camion, float dato){

camion.cargaTotal=dato;

}

int getNroCamion(Camion &camion){

return camion.nroCamion;

}

float getKGcapacidad(Camion &camion){

return camion.kgCapacidad;

}

float getCargaTotal(Camion &camion){

return camion.cargaTotal;

}
float getPorcentajeCarga(Camion &camion){
return camion.porcentajeOcupado;
}

void setPorcentajeCarga(Camion &camion, float porcentaje){
camion.porcentajeOcupado=porcentaje;
}


float calcularPorcentajeOcupado(Camion &camion){

    return ((camion.cargaTotal * 100)/camion.kgCapacidad);

}

