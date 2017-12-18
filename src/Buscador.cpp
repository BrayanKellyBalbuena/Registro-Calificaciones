#include "Buscador.h"
#include <iostream>

Buscador* Buscador::instance = NULL;

Buscador::Buscador(){}


Buscador::~Buscador()
{
    std::cout << "Buscador Eliminado" << std::endl;
}


Buscador* Buscador::get_instance()
{
    if ( instance == 0 )
    {
        instance = new Buscador;
    }
    return instance;
}


int Buscador::buscar_lineal(int* arreglo, int numeroBuscado, int tamano)
{
    for ( int i = 0; i < tamano; i++ )
    {
        if ( numeroBuscado == arreglo[i] )
            return i;
    }
    return -1;
}

int Buscador::busqueda_binaria(int* arreglo, int numeroBuscado, int tamano)
{
    int inferior = 0; //parte inferior del vector
	int superior = tamano-1; //parte superior del vector
	int medio = ( inferior + tamano  ) / 2; // elemnto del medo
	int ubicacion = -1; //devuelve el valor; -1 si no lo encuentra

	do
	{
		// si encuentra el elemento en el medio
		if ( numeroBuscado == arreglo[ medio ]  )
			ubicacion = medio;       // ubicacion es el medio actual
		else if ( numeroBuscado < arreglo[medio] )  // el medio es demasiado alto
			superior = medio - 1;    // elimina la mitad superior
		else   // el elemeto medio es demasiado inferior
			inferior = medio + 1;  // elimina la mitad inferior
		medio = ( inferior + superior + 1  ) / 2;   // recalcula el elemento medio
	}while( ( inferior <= superior ) && (ubicacion == -1) );

	return ubicacion; //retorna la ubicacion
}




