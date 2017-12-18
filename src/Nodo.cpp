#include "Nodo.h"

Nodo::Nodo(int dato): siguiente(NULL)
{
    this->dato = dato;
}

Nodo* Nodo::get_siguiente() const
{
    return siguiente;
}

int Nodo::get_dato()
{
    return dato;
}
