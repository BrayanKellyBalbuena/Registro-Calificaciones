#ifndef EDITOR_H
#define EDITOR_H

#include <iostream>
#include <stdexcept>
#include <fstream> // flujo de archivo
#include <cstdlib>
#include <iomanip> // header file que nos permite manipular el formato de entrada y salida de flujos
#include <sstream> //header file habilita la inter operacion entre un flujo de bufer y un objeto string
#include "Estudiante.h"
#include "Cola.h"

class Editor
{
    public:
        Editor();
        virtual ~Editor();
        bool leerArchivo();
        bool nuevoEstudiante( Estudiante );
        bool eliminarEstudiante(int numero_a_eliminar);
        std::string convierteAString(int);
        int localizarEstudiante( std::string numero );
        void cargar_datos( Cola* cola );
    private:

};

#endif // EDITOR_H
