#include "Camion.h";

/* Implementación de Primitivas */

/*-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- */

void crearCamion(Camion &amp;camion){

	camion.nroCamion=0;	
	camion.kgCapacidad=2500;	
	camion.cargaTotal=0.0;		
	camion.pilaSolicitudes;
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


void setPilaSolicitudes(Camion &camion, Pila pilaNueva){

camion.pilaSolicitudes=pilaNueva;

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


Pila getPilaSolicitudes(Camion &camion){

return camion.pilaSolicitudes;

}

float calcularPorcentajeOcupado(Camion &camion){

return ((camion.kgCapacidad * 100)/camion.cargaTotal);

}

