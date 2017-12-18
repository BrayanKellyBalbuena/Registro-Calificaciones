#ifndef NODO_H
#define NODO_H
#include <cstdlib>

class Nodo
{
    public:
        Nodo( int dato );
        int get_dato();
        Nodo* get_siguiente() const;
        friend class Cola;
        friend class Editor;
    private:
        Nodo* siguiente;
        int dato;
};


#endif // NODO_H
