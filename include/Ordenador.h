#ifndef ORDENADOR_H
#define ORDENADOR_H
#include "Cola.h"

class Ordenador
{
    public:
        Ordenador();
        virtual ~Ordenador();
        void ordenar(int* arreglo,int tamano);
        void mostrar_descendente(int* arreglo, int tamano);
        void mostrar_acendente(int* arreglo,int);

    private:
};

#endif // ORDENADOR_H
