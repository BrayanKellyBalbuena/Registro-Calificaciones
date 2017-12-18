#include "Cola.h"
#include <iostream>

using namespace std;

Cola::Cola():primero(NULL),ultimo(NULL),tamano(0)
{

}

Cola::~Cola()
{
    if ( !esta_vacia())
    {
        Nodo* nodo_actual = primero;
        Nodo* nodo_temp;
        while( nodo_actual != NULL )
        {
            nodo_temp = nodo_actual;
            nodo_actual = nodo_actual->siguiente;
            delete nodo_temp;
        }
    }
}

Nodo* Cola::get_primero() const
{
    return primero;
}


int Cola::get_tamano() const
{
    return this->tamano;
}

void Cola::push( Nodo* nodo )
{
    this->tamano++;
    if( esta_vacia() )
    {
        primero = ultimo = nodo;
    }
    else
    {
       ultimo->siguiente = nodo;
       ultimo = nodo;
    }
}

Nodo* Cola::pop()
{

    if (esta_vacia())
        return NULL;

    Nodo* retorno = primero;
    if ( primero == ultimo )
    {
        primero = ultimo = NULL;
        this->tamano--;
    }
    else
    {
        primero = primero->siguiente;
        this->tamano--;
        return retorno;
    }
    return retorno;
}

bool Cola::esta_vacia()
{
    return primero == NULL;
}
