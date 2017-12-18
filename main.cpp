#include <iostream>
#include "Cola.h"
#include "Ordenador.h"
#include "Buscador.h"
#include "Calculadora.h"
#include "Editor.h"

using namespace std;

// Declariacion de las variables
Cola* cola = new Cola();
Ordenador* ordenador = new Ordenador();
Buscador* buscador = Buscador::get_instance();
Editor* editor = new Editor();
Calculadora* calculadora = Calculadora::get_instance();
int* arreglo;     // puntero arreglo que almacenara las calificaciones
int tamano = 0;   // tanaño del arreglo
bool cambio_en_archivo = false;    // variable que indica si ha cambiado el archivo

//enum de las opciones del menu
enum Opciones { IMPRIMIR = 1, NUEVO, ELIMINAR, MOSTRAR_DESC, MOSTRAR_ASC,
    BUSQUEDA_LINEAL, BUSQUEDA_BINARIA, MOSTRAR_MAYOR, MOSTRAR_MENOR ,
    CALCULAR_PROMEDIO, SALIR};

void agregarContaco()
{
    cout << "\t\t======================================" << endl;
    cout << "\t\t||   AGREGAR UN NUEVO ESTUDIANTE    ||" << endl;
    cout << "\t\t======================================\n\n" << endl;
    int numero = 0;
    string nombre ="";
    string apellido = "";
    int calificacion = 0;
    cout << "Digite el numero: ";
    cin >> numero;

    // si introdujeron una letra lanzara una execpcion
    if ( numero == 0 )
    {
        throw invalid_argument("Numero no valido.");
    }

    // variables
    cout << "Digite el nombre: ";
    cin >> nombre;
    cout << "Digite el  apellido: ";
    cin >> apellido;
    cout << "Digite la calificacion: ";
    cin >> calificacion;

    // si introdujeron una letra lanzara una execpcion
    if ( calificacion == 0 )
    {
        throw invalid_argument("Calificacion no valido.");
    }

    // se crea un nuevo estudiante
    Estudiante estudiante( numero, nombre, apellido, calificacion);

    // si no se ingreso el estudiante
    if ( editor->nuevoEstudiante( estudiante ) )
        cerr << "\nNo se pudo agregar el estudiante." << endl;
    else
    {
        Nodo* nodo = new Nodo(calificacion);
        cola->push(nodo);
        cambio_en_archivo = true;
        cout << "\nEstudiante agregado satisfactoriamente\n";
    }

}

void eliminar_estudiante()
{
    if( editor->leerArchivo())
    {
        cout << "No hay estudiante que eliminar" << endl;
        return;
    }
    int numero_eliminar = NULL;
    cout << "Digite el numero: ";
    cin >> numero_eliminar;
    if(editor->eliminarEstudiante(numero_eliminar))
    {
        delete cola;
        cola = new Cola();
        editor->cargar_datos(cola);
        cambio_en_archivo = true;
    }
    cout << "No hay dato a eliminar";
}

// funcion que agrega las calificacione al arreglo
void cargar_datos()
{
    tamano =  cola->get_tamano(); // almacenanos el tamaño del arreglo
    Nodo* nodo = cola->get_primero();

    arreglo = new int [cola->get_tamano()];
    int a = 0; //variable contador
    while( nodo != NULL )
    {
        arreglo[a] = nodo->get_dato();
        nodo = nodo->get_siguiente();
        a++;
    }
    // llamos el metodo de ordenador y le pasamos el puntero arreglo y su tamaño
    ordenador->ordenar( arreglo, tamano );
}

void mostrar_ascendente()
{
    // si la cola no esta vacia
    if (cola->get_tamano() != 0)
    {
        if (cambio_en_archivo)
        {
            cargar_datos();
            cambio_en_archivo = false;
        }
        editor->leerArchivo();
        cout << endl << endl;
        cout << "Las calificaciones: ";
        ordenador->mostrar_acendente( arreglo, tamano);

    }
    else
        cout << "No hay datos";
}

void mostrar_descendente()
{
    // si la cola no esta vacia
     if (cola->get_tamano() != 0)
    {
        // si ha ocurrido un cambio en el archivo
        if (cambio_en_archivo)
        {
            cargar_datos();
            cambio_en_archivo = false;
        }

        editor->leerArchivo(); //mostramos los datos del archivo estudiantes.dat
        cout << endl << endl; // dos saltos de linea
        cout << "Las calificaciones: ";
        ordenador->mostrar_descendente(arreglo, tamano);
    }
    else
        cout << "No hay datos";
}

void mayor_calificacion()
{
     if (cola->get_tamano() != 0)
    {
        if (cambio_en_archivo)
        {
             cargar_datos();
             cambio_en_archivo = false;
        }
        editor->leerArchivo();
        cout << endl << endl;
        cout << "La calificion mayor es: " << arreglo[tamano-1] << endl;
    }
    else
        cout << "No hay datos";
}

void menor_calificacion()
{
    if (cola->get_tamano() != 0)
    {
        if (cambio_en_archivo)
        {
             cargar_datos();
             cambio_en_archivo = false;
        }
        editor->leerArchivo();
        cout << endl << endl;
        cout << "La calificion menor es: " << arreglo[0] << endl ;
    }
    else
        cout << "No hay datos";
}



void buscar()
{
    if (cola->get_tamano() != 0)
    {
        if (cambio_en_archivo)
        {
             cargar_datos();
             cambio_en_archivo = false;
        }

        int numero_buscado = 0;

        cout << "\n\nDigite la calicacion a buscar: ";
        cin >> numero_buscado;

        int posicion = buscador->buscar_lineal( arreglo, numero_buscado, tamano);
         if( posicion != -1 )
        {
            //Leyendo el archivo para encontrar la posicion dada
            ifstream enContactoArchivo( "estudiantes.dat", ios::in );
            //atributos para cargar la data
            string numero = "";
            string nombre ="";
            string apellido ="";
            string calificacion = "";
            cout << "\nLa calificacion existe mostrando estudinates con la califiacion\n" << endl;
            //Cargando la data en los atributos de arriba
            while(enContactoArchivo >> numero >> nombre >> apellido >> calificacion )
            {
                //Un for en el arreglo que contiene la data
                for(int i = 0; i <= tamano; i++){
                    //si la posicion de arreglo coincide con la posicion que se busca entonces has esto
                    if(i == posicion && numero_buscado == atoi(calificacion.c_str())){
                        // imprimimos los mediante left, right, setw para el ancho de campos
                        cout << left << setw( 14 )<< numero << setw( 14 ) << nombre << setw( 14 )
                        << right  << setw( 10 ) << apellido  << setw( 19 )
                        << calificacion<< endl;
                    }
                }
            }
        }
    }
    else
        cout << "no hay datos";
}

void buscar_binaria()
{
    if (cola->get_tamano() != 0)
    {
       if (cambio_en_archivo)
        {
             cargar_datos();
             cambio_en_archivo = false;
        }

        int numero_buscado = 0;

        cout << "\nDigite la calificacion a buscar: ";
        cin >> numero_buscado;

        int posicion = buscador->busqueda_binaria( arreglo, numero_buscado, tamano);
        if( posicion != -1 )
        {
            cout << "\nLa calificacion existe mostrando estudinates con la califiacion\n" << endl;
            //Leyendo el archivo para encontrar la posicion dada
            ifstream enContactoArchivo( "estudiantes.dat", ios::in );
            //atributos para cargar la data
            string numero = "";
            string nombre ="";
            string apellido ="";
            string calificacion = "";

                //Cargando la data en los atributos de arriba
                while(enContactoArchivo >> numero >> nombre >> apellido >> calificacion )
                {
                    //Un for en el arreglo que contiene la data
                    for(int i = 0; i <= tamano; i++){
                        //si la posicion de arreglo coincide con la posicion que se busca entonces has esto
                        if(i == posicion && numero_buscado == atoi(calificacion.c_str())){
                            // imprimimos los mediante left, right, setw para el ancho de campos
                            cout << left << setw( 14 )<< numero << setw( 14 ) << nombre << setw( 14 )
                            << right  << setw( 10 ) << apellido  << setw( 19 )
                            << calificacion<< endl;
                        }
                    }
                }
            }
        else
             cout << "No se encuentra la calificacion: " << numero_buscado << endl;
    }
    else
        cout << "no hay datos";
}

void mostrar_promedio()
{
    if (cambio_en_archivo)
    {
             cargar_datos();
             cambio_en_archivo = false;
    }
    editor->leerArchivo();
    cout << endl << endl;
    cout << "El promedio es: "
        << calculadora->calcula_promedio(arreglo,tamano)
        << endl;
}

int escribirOpcion()
{
    system("color F0");
    cout << "\t\t==================================================" << endl;
    cout << "\t\t||   BIENVENIDO AL REGISTRO DE CALIFICACIONES   ||" << endl;
    cout << "\t\t==================================================\n\n" << endl;

    cout <<"1-  Mostrar Estudiantes" << endl
        <<"2-  Agregar Un Nuevo Estudiante" << endl
        <<"3-  Eliminar Un Nuevo Estudiante" << endl
        <<"4-  Mostrar Calificaciones Descendentemente" << endl
        <<"5-  Mostrar Calificaciones Ascendentemente  " << endl
        <<"6-  Busqueda Normal Si Una Calificacion Exite " << endl
        <<"7-  Busqueda Rapida Si Una Calificacion Exite " << endl
        <<"8-  Mostrar Calificacion Mayor" << endl
        <<"9-  Mostrar Calificacion Menor" << endl
        <<"10- Calcular Promedio" << endl
        <<"11- Fin del programa\n" << endl
        <<"Escriba su opcion: ";


     int opcionMenu;
     try
     {
        cin >> opcionMenu;
        if (opcionMenu == 0)
        {
            throw invalid_argument("Las letras no son numeros.");
        }
     }catch( invalid_argument& e)
     {
        cerr << e.what() << endl;
        exit(1);
     }
     return opcionMenu;
}

int main()
{
    system("color f0");
    cout << "\t===============================================================" << endl;
    cout << "\t||  PROTECTO FINAL ESTRUCTURA DE DATOS DESARROLLADO by: NJGB ||" << endl;
    cout << "\t===============================================================\n\n" << endl;
    system("pause");
    system("cls");

    //si existen datos en el archivo los agregamos a la cola
    editor->cargar_datos(cola);

    cargar_datos(); // cargamos los datos al array

    //varaible que servira para guardar la opcion digitada
    int opcion;

    while ( ( opcion = escribirOpcion() ) != SALIR )
    {
        switch ( opcion )
        {
            case IMPRIMIR:
                system( "cls" );
                system( "color F0" );
                cout << "\t\t==============================================" << endl;
                cout << "\t\t||      ESTUDIANTES EN EL REGISTRO          ||" << endl;
                cout << "\t\t==============================================\n\n" << endl;
                if ( editor->leerArchivo())
                    cout << "No hay datos que mostrar" << endl;
                    cout << endl;
                system("pause");
                system( "cls" );
                break;
            case NUEVO:
                system( "cls" );
                system("color A0");
                try
                {
                    agregarContaco();
                }catch( invalid_argument& e)
                {
                    cerr << e.what() << endl;
                    return -1;
                }

                system( "pause" );
                system("cls");
                break;
            case ELIMINAR:
                system("cls");
                system("color C0");
                 cout << "\t\t================================================" << endl;
                cout << "\t\t||     ELIMINAR UN ESTUDIANTE EN EL REGISTRO   ||" << endl;
                cout << "\t\t=================================================\n\n" << endl;
                eliminar_estudiante();
                system("pause");
                system("cls");
                break;
            case MOSTRAR_DESC:
                system("cls");
                system("color F0");
                cout << "\t\t=========================================================" << endl;
                cout << "\t\t|| MOSTRANDO CALIFICACIONES DESCENDENTE EN EL REGISTRO ||" << endl;
                cout << "\t\t=========================================================\n\n" << endl;
                mostrar_descendente();
                system("pause");
                system("cls");
                break;
            case MOSTRAR_ASC:
                system("cls");
                system("color F0");
                cout << "\t\t========================================================" << endl;
                cout << "\t\t|| MOSTRANDO CALIFICACIONES ASCENDENTE EN EL REGISTRO ||" << endl;
                cout << "\t\t========================================================\n\n" << endl;
                mostrar_ascendente();
                system("pause");
                system("cls");
                break;
            case BUSQUEDA_LINEAL:
                system("cls");
                system("color F0");
                cout << "\t========================================================" << endl;
                cout << "\t||     BUSQUEDA NORMAL SI UNA CALIFICACION EXISTE      ||" << endl;
                cout << "\t=========================================================\n\n" << endl;
                buscar();
                system("pause");
                system("cls");
                break;
            case BUSQUEDA_BINARIA:
                system("cls");
                system("color F0");
                cout << "\t=====================================================" << endl;
                cout << "\t||  BUSQUEDA  RAPIDA   SI UNA CALIFICACION EXISTE   ||" << endl;
                cout << "\t======================================================\n\n" << endl;
                buscar_binaria();
                system("pause");
                system("cls");
                break;
            case MOSTRAR_MAYOR:
                system("cls");
                system("color F0");
                cout << "\t\t=================================================" << endl;
                cout << "\t\t||        MOSTRANDO CALIFICACION MAYOR         ||" << endl;
                cout << "\t\t=================================================\n\n" << endl;
                mayor_calificacion();
                system("pause");
                system("cls");
                break;
             case MOSTRAR_MENOR:
                system("cls");
                system("color F0");
                cout << "\t\t===================================================" << endl;
                cout << "\t\t||         MOSTRANDO CALIFICACION MENOR          ||" << endl;
                cout << "\t\t===================================================\n\n" << endl;
                menor_calificacion();
                system("pause");
                system("cls");
                break;
             case CALCULAR_PROMEDIO:
                system("cls");
                system("color F0");
                cout << "\t\t=========================================="<< endl;
                cout << "\t\t||         MOSTRANDO EL PROMEDIO         ||" << endl;
                cout << "\t\t===========================================\n\n" << endl;
                mostrar_promedio();
                system("pause");
                system("cls");
                break;
            default:
                system("color C");
                cout << "Opcion incorrecta" << endl;
                system("pause");
                system("cls");
                break;
        }
    }
    cout << "\n\nLimpiado memoria\n" << endl;
    delete cola;
    delete ordenador;
    delete buscador;
    delete editor;
    delete calculadora;
    delete arreglo;
    return 0;
}
