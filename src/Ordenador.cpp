#include "Ordenador.h"
#include <iostream>

using namespace std;

Ordenador::Ordenador()
{

}

Ordenador::~Ordenador()
{
    cout << "Ordenador eliminado" << endl;
}

void Ordenador::mostrar_descendente(int* arreglo, int tamano)
{
    if ( tamano == 1 )
    {
        cout << arreglo[0];
        return;
    }
    for (int i = tamano-1 ; i >= 0 ; i--)
    {
        cout << arreglo[i] << " ";
    }
     cout << "\n" << endl;

}

void Ordenador::mostrar_acendente(int* arreglo, int tamano)
{
    for (int i = 0; i < tamano ;i++)
    {
        cout << arreglo[i] << " ";

    }
     cout << "\n" << endl;
}

void Ordenador::ordenar(int* arreglo,int tamano)
{
    bool cambio = true;
	int aux;
	while(cambio)
	{
		cambio = false;
		for( int i = 1; i < tamano ;i++ )
		{
			if( arreglo[i] < arreglo[i-1] )
			{
				cambio = true;
				aux = arreglo[i];
				arreglo[i] = arreglo[i-1];
				arreglo[i-1] = aux;
			}
		}
	}
}


