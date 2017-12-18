#include "Estudiante.h"
#include <iostream>
#include <iomanip>
#include <exception>


Estudiante::Estudiante(int numero, std::string nombre, std::string apellido, int calificacion)
{
    set_numero(numero);
    this->nombre = nombre;
    this->apellido = apellido;
    set_calificacion(calificacion);
}

int Estudiante::get_numero()
{
    return numero;
}

void Estudiante::set_numero(int numero)
{
    if ( numero == 0 )
        throw "Nombre no valido";
    else
        this->numero = numero;
}

std::string Estudiante::get_nombre() const
{
    return nombre;
}

void Estudiante::set_nombre(std::string nombre)
{
    this->nombre = nombre;
}

std::string Estudiante::get_apellido() const
{
    return apellido;
}

void Estudiante::set_apellido(std::string apellido)
{
    this->apellido = apellido;
}

int Estudiante::get_calificacion() const
{
    return calificacion;
}

void Estudiante::set_calificacion(int calificacion)
{
    if ( calificacion < -1 )
        throw "Error calificacion no valida";
    else
        this->calificacion = calificacion;
}
