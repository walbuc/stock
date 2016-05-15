//
//  lista.cpp
//  stock
//
//  Created by Walter Buczacka on 5/15/16.
//  Copyright © 2016 Walter Buczacka. All rights reserved.
//

#include "lista.h"


/******************************************************************************/
/* DefiniciÛn de Tipos de Datos para manejo interno */
/*--------------------------------------------------*/

/******************************************************************************/
/* ImplementaciÛn de Primitivas */
/*------------------------------*/

void crearLista(Lista &lista, PFComparacion compara) {
    lista.primero = fin();
    lista.compara = compara;
}

/*----------------------------------------------------------------------------*/
bool listaVacia(Lista &lista) {
    
    return (primero(lista) == fin());
}

/*----------------------------------------------------------------------------*/
PtrNodoLista fin() {
    return nullptr;
}

/*----------------------------------------------------------------------------*/
PtrNodoLista primero(Lista &lista) {
    return lista.primero;
}

/*----------------------------------------------------------------------------*/
PtrNodoLista siguiente(Lista &lista, PtrNodoLista ptrNodo) {
    
    /* verifica si la lista est· vacia o si ptrNodo es el ˙ltimo */
    if ((! listaVacia(lista)) && (ptrNodo != fin()))
        return ptrNodo->sgte;
    else
        return fin();
}

/*----------------------------------------------------------------------------*/
PtrNodoLista anterior(Lista &lista, PtrNodoLista ptrNodo) {
    
    PtrNodoLista ptrPrevio = fin();
    PtrNodoLista ptrCursor = primero(lista);
    
    while (( ptrCursor != fin()) && (ptrCursor != ptrNodo)) {
        ptrPrevio = ptrCursor;
        ptrCursor = siguiente(lista,ptrCursor);
    }
    return ptrPrevio;
}

/*----------------------------------------------------------------------------*/
PtrNodoLista ultimo(Lista &lista) {
    
    /* el ˙ltimo nodo de la lista es el anterior al fin() */
    return anterior(lista,fin());
}

/*----------------------------------------------------------------------------*/
PtrNodoLista crearNodoLista(PtrDato ptrDato) {
    
    /* reserva memoria para el nodo y luego completa sus datos */
    PtrNodoLista ptrAux = new NodoLista;
    
    ptrAux->ptrDato = ptrDato;
    ptrAux->sgte = fin();
    
    return ptrAux;
}

/*----------------------------------------------------------------------------*/
PtrNodoLista adicionarPrincipio(Lista &lista, PtrDato ptrDato) {
    
    /* crea el nodo */
    PtrNodoLista ptrNuevoNodo = crearNodoLista(ptrDato);
    
    /* lo incorpora al principio de la lista */
    ptrNuevoNodo->sgte = lista.primero;
    lista.primero = ptrNuevoNodo;
    
    return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/
PtrNodoLista adicionarDespues(Lista &lista, PtrDato dato, PtrNodoLista ptrNodo) {
    
    PtrNodoLista ptrNuevoNodo = fin();
    
    /* si la lista est· vacia se adiciona la principio */
    if (listaVacia(lista))
        ptrNuevoNodo = adicionarPrincipio(lista,dato);
    
    else {
        if (ptrNodo != fin()) {
            
            /* crea el nodo y lo intercala en la lista */
            ptrNuevoNodo = crearNodoLista(dato);
            
            ptrNuevoNodo->sgte = ptrNodo->sgte;
            ptrNodo->sgte = ptrNuevoNodo;
        }
    }
    return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/
PtrNodoLista adicionarFinal(Lista &lista, PtrDato dato) {
    
    /* adiciona el dato despuÈs del ˙ltimo nodo de la lista */
    return adicionarDespues(lista,dato,ultimo(lista));
}

/*----------------------------------------------------------------------------*/
PtrNodoLista adicionarAntes(Lista &lista, PtrDato dato, PtrNodoLista ptrNodo) {
    
    PtrNodoLista ptrNuevoNodo = fin();
    
    if (! listaVacia(lista)) {
        if (ptrNodo != primero(lista))
            ptrNuevoNodo = adicionarDespues(lista,dato,anterior(lista,ptrNodo));
        else
            ptrNuevoNodo = adicionarPrincipio(lista,dato);
    }
    return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/
void eliminarNodo(Lista &lista, PtrNodoLista ptrNodo) {
    
    PtrNodoLista ptrPrevio;
    
    /* verifica que la lista no estÈ vacia y que nodo no sea fin*/
    if ((! listaVacia(lista)) && (ptrNodo != fin())) {
        
        if (ptrNodo == primero(lista))
            lista.primero = siguiente(lista,primero(lista));
        
        else {
            ptrPrevio = anterior( lista , ptrNodo );
            ptrPrevio->sgte = ptrNodo->sgte;
        }
        // Si el dato es un TDA, ac· habrÌa que llamar al destructor.
        
        delete ptrNodo;
    }
}

/*----------------------------------------------------------------------------*/
void eliminarNodoPrimero(Lista &lista) {
    
    if (! listaVacia(lista))
        eliminarNodo(lista,primero(lista));
}

/*----------------------------------------------------------------------------*/
void eliminarNodoUltimo(Lista &lista) {
    
    if (! listaVacia(lista))
        eliminarNodo(lista,ultimo(lista));
}

/*----------------------------------------------------------------------------*/
void eliminarLista(Lista &lista) {
    
    /* retira uno a uno los nodos de la lista */
    while (! listaVacia(lista))
        eliminarNodo(lista,primero(lista));
}

/*----------------------------------------------------------------------------*/
PtrNodoLista localizarDato(Lista &lista, PtrDato ptrDato) {
    
    bool encontrado = false;
    PtrNodoLista ptrCursor = primero(lista);
    
    /* recorre los nodos hasta llegar al ˙ltimo o hasta
     encontrar el nodo buscado */
    while ((ptrCursor != fin()) && (! encontrado)) {
        
        if (lista.compara(ptrCursor->ptrDato,ptrDato) == IGUAL)
            encontrado = true;
        else
            ptrCursor = siguiente(lista,ptrCursor);
        
    }
    
    /* si no lo encontrÛ devuelve fin */
    if (! encontrado)
        ptrCursor = fin();
    
    return ptrCursor;
}

/*----------------------------------------------------------------------------*/
void eliminarDato(Lista &lista, PtrDato ptrDato) {
    
    /* localiza el dato y luego lo elimina */
    PtrNodoLista ptrNodo = localizarDato(lista,ptrDato);
    if (ptrNodo != fin())
        eliminarNodo(lista,ptrNodo);
}

/*----------------------------------------------------------------------------*/
PtrNodoLista insertarDato(Lista &lista, PtrDato ptrDato) {
    
    PtrNodoLista ptrPrevio = primero(lista);
    PtrNodoLista ptrCursor = primero(lista);
    PtrNodoLista ptrNuevoNodo;
    bool ubicado = false;
    
    /* recorre la lista buscando el lugar de la inserciÛn */
    while ((ptrCursor != fin()) && (! ubicado)) {
        
        if (lista.compara(ptrCursor->ptrDato,ptrDato) == MAYOR)
            ubicado = true;
        
        else {
            ptrPrevio = ptrCursor;
            ptrCursor = siguiente(lista,ptrCursor);
        }
    }
    
    if (ptrCursor == primero(lista))
        ptrNuevoNodo = adicionarPrincipio(lista,ptrDato);
    else
        ptrNuevoNodo = adicionarDespues(lista,ptrDato,ptrPrevio);
    
    return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/

void reordenar(Lista &lista) {
    
    Lista temp = lista;
    PtrNodoLista ptrCursor = primero(temp);
    crearLista(lista, lista.compara);
    while ( ptrCursor != fin() ) {
        insertarDato( lista, ptrCursor->ptrDato );
        eliminarNodo( temp, ptrCursor );
        ptrCursor = primero(temp);
    }
    eliminarLista( temp );
}


/*----------------------------------------------------------------------------*/

int longitud(Lista &lista){
    PtrNodoLista ptrCursor = primero(lista);
    int longitud = 0;
    while ( ptrCursor != fin() ) {
        longitud++;
        ptrCursor = siguiente( lista, ptrCursor);
    }
    return longitud;
}

/*----------------------------------------------------------------------------*/

