#include "Calculadora.h"
#include <iostream>

Calculadora* Calculadora::instance = NULL;

Calculadora::Calculadora()
{

}

Calculadora* Calculadora::get_instance()
{
    if (instance == NULL)
    {
        instance = new Calculadora;
    }
    return instance;
}

Calculadora::~Calculadora()
{
    std::cout << "Elimina calculadora " << std::endl;
}

int Calculadora::calcula_promedio(int* arreglo, int tamano) const
{
    int promedio=0;
    for (int i = 0; i < tamano; i++)
    {
        promedio += arreglo[i];
    }
    return promedio/tamano;
}
