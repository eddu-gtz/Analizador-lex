#include "cnodo.h"

void CNodo::insertarAdelante(Token* dat)
{
    //Crea un nuevo nodo
    CNodo* pNuevo = new (CNodo);
    //se asigna el dato al nodo
    pNuevo->dato = dat;
    //El nuevo nodo en su campo anterior apunta a this
    pNuevo->pAnt = this;
    //Se en laza el puntero siguiente
    pNuevo->pSig = this->pSig;
    //Se enlazan los punteros de los nodos existentes al nuevo nodo
    pNuevo->pSig->pAnt = pNuevo;

    this->pSig = pNuevo;
}

Token* CNodo::eliminarAdelante()
{
    //Variable para poder guardar el dato
    Token* dat;
    //Se crea un putero auxiliar para posteriormente eliminar el nodo
    CNodo* aux = this->pSig;
    //Se quita el enlace al nodo a eliminar
    aux->pSig->pAnt = this;

    this->pSig = aux->pSig;
    //Se recupera el dato
    dat = aux->dato;
    //Se elimina el nodo
    delete aux;
    //Retorna el dato
    return dat;
}
