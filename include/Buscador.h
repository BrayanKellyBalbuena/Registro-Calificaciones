#ifndef BUSCADOR_H
#define BUSCADOR_H

class Buscador
{
    public:
        Buscador();
        static Buscador* get_instance();
        virtual ~Buscador();
        int buscar_lineal(int* arreglo,int numeroBuscado, int tamano );
        int busqueda_binaria(int* arreglo, int numeroBuscado, int tamano );
    private:
        static Buscador* instance;
};

#endif // BUSCADOR_H
