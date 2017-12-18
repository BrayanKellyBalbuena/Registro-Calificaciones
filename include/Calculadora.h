#ifndef CALCULADORA_H
#define CALCULADORA_H
#include <cstdlib>

class Calculadora
{
    public:
        Calculadora();
        virtual ~Calculadora();
        static Calculadora* get_instance();
        int calcula_promedio( int* arreglo,  int tamano ) const;
    private:
        static Calculadora* instance;
};

#endif // CALCULADORA_H
