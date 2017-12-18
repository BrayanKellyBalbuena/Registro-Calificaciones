#ifndef COLA_H
#define COLA_H
#include "Nodo.h"


class Cola
{
    public:
        Cola();
        virtual ~Cola();
        void push( Nodo*  );
        Nodo* pop();
        bool esta_vacia();
        int get_tamano() const;
        Nodo* get_primero() const;


        friend class Editor;
    private:
        int tamano;
        Nodo* primero;
        Nodo* ultimo;
};

#endif // COLA_H
