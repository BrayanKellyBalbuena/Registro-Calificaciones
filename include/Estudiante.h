#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <string>


class Estudiante
{
     public:
        Estudiante( int = 0, std::string = "", std::string = "" ,int = 0);
        int get_numero() ;
        void set_numero( int numero );
        std::string get_nombre() const;
        void set_nombre( std::string nombre );
        std::string get_apellido( ) const;
        void set_apellido(std::string apellido);
        int get_calificacion() const;
        void set_calificacion(int calificacion);
    private:
        int numero;
        std::string nombre;
        std::string apellido;
        int calificacion;
};

#endif // ESTUDIANTE_H
