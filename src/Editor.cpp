#include "Editor.h"

using namespace std;

Editor::Editor()
{
    //ctor
}

Editor::~Editor()
{
    cout << "Eliminado Lector" << endl;
}


//metodo que muestra todos los datos
bool Editor::leerArchivo()
{

    //abrimos el archivo en modo lectura mediante ios::in
    ifstream enContactoArchivo( "estudiantes.dat", ios::in );

    // si no abre el archivo
    if(!enContactoArchivo )
        return true;

    //variables que serviran para almacenar los datos del archivo.
    string numero = "";
    string nombre ="";
    string apellido ="";
    string calificacion = "";

    // imprimimos la cabecera mediante left, right, setw para el ancho de campos
     cout << left << setw( 14 )<<"| Numero |"<<setw( 14 )<<"| Nombre |"
            << setw( 14 )<<right << setw( 14 ) << "| Apellido |" << left << setw( 7 )
            << apellido  << "| Calificacion |" <<endl;

    // cargamos los datos a sus respectivas variables
    while(enContactoArchivo >> numero >> nombre >> apellido >> calificacion )
    {
        // imprimimos los mediante left, right, setw para el ancho de campos
        cout << left << setw( 14 )<< numero << setw( 14 ) << nombre << setw( 14 )
            << right  << setw( 10 ) << apellido  << setw( 19 )
            << calificacion<< endl;
    }
    // si todo a salido bien retorna false;
    return false;
}


// metodo que permite localizar el estudiante rebi como parametro el numero
int Editor::localizarEstudiante( string posicion )
{
    int contador = 0;

    //variables auxiliares para almacenar los datos del arcivo
    string buffer_numero ="";
    string nombre = "";
    string apellido="";
    string calificacion="";

    // apertura del archivo en modo lectura
    ifstream enContactoArchivo( "estudiantes.dat", ios::in );

    //si no se abre el archivo
    if ( !enContactoArchivo )
    {
         cout << "Problemas leiendo el archivo\n" << endl;
         return 0;
    }

    // cargamos cada una de las variables con los datos linea por linea
    while ( enContactoArchivo >> buffer_numero  >> nombre >> apellido >> calificacion )
    {
        contador++;
        if ( posicion == buffer_numero ) // si encontro el numero buscado
        {
            cout << "\nEstudiante encontrado: " << nombre << endl;

            enContactoArchivo.close();
            return contador;
        }
    }

    enContactoArchivo.close();
    return 0;
}



//metodo Agregar un nuevo contacto

bool Editor::nuevoEstudiante(Estudiante estudiante)
{
    //abrimos el archivo en modo escritura y anexo
    ofstream insertarEnArchivo("estudiantes.dat", ios::app);
    if ( !insertarEnArchivo )
    {
        return true;
    }

    if ( localizarEstudiante( convierteAString(estudiante.get_numero() )))
        {
            cout << "El estudiante ya existe ";
            return true;
        }

    // insertamos los datos en el archivo separados por ' ' para desplazarnos dato por dato
    insertarEnArchivo << convierteAString(estudiante.get_numero()) << ' ' << estudiante.get_nombre() << ' '
    << estudiante.get_apellido() << ' ' << convierteAString(estudiante.get_calificacion()) << endl;

    insertarEnArchivo.close();
    return false;
}


//Implementacion del metodo eliminar
bool Editor::eliminarEstudiante( int numero_a_eliminar )
{

    // variables para almacenar los datos del archivo
    string posicionBuscada = convierteAString(numero_a_eliminar);
    string numero="";
    string nombre ="";
    string apellido = "";
    string calificacion="";


    // si se encuentra el estudiante
    if ( localizarEstudiante( posicionBuscada ) )
    {
       // abrimos el archivo estudiantes en modo lectura
       fstream archivoLectura("estudiantes.dat",ios::in | ios::out | ios::binary);

       // el constructor de ofstream abre el crear el archivo auxliar que
       // incluira los datos menos el que eliminaresmos
       ofstream archivoEscritura( "auxiliar.dat", ios::out );

        // si no se puede abrir el archivo estudinates o no se crea el axiliar
       if ( !archivoLectura || !archivoEscritura )
       {
           cout << "Problemas con el archivo de lectura";
           return false;
       }

        // leemos los datos a su correspondiente a su variable
       while( archivoLectura >> numero >> nombre >> apellido >> calificacion )
       {
           // si el numero es el que buscamos no lo incluimos en el auxilar
           if ( numero == posicionBuscada ){}
                //has nada
           else
           {    // inclumimos los datos en el archivo auxliar
               archivoEscritura << numero << ' ' << nombre << ' ' << apellido << ' '
                << calificacion << endl;
           }
       }
        // cerramos los respectivo archovos
       archivoEscritura.close();
       archivoLectura.close();

       remove("estudiantes.dat"); // eliminamos el archivo estudiantes
       rename( "auxiliar.dat", "estudiantes.dat" ); // renombramos el aulizar por estudiantes

       cout << "\n\nEl estudiante se ha eliminado con exito" << endl;
       return true;
    }
    else
    {
        cout << "\n\nEl estudiante no existe en el archivo" << endl;
        return false;
    }
}


//funcion que convierte un numero a string
std::string  Editor::convierteAString(int numero)
{

    stringstream stream_numero; //declaromos un objecto stringstream
    stream_numero << numero;    // enviamos el numero a el onjecto stringstream
    string numero_str = stream_numero.str(); // mediante el metodo stringstream devolvemos el numero
                                            //como un string
    return numero_str;
}

void Editor::cargar_datos(Cola* cola)
{
    ifstream enContactoArchivo( "estudiantes.dat", ios::in );
    // si no abre el archivo
    if(!enContactoArchivo )
        return;

    //variables que serviran para almacenar los datos del archivo.
    string numero = "";
    string nombre ="";
    string apellido ="";
    string calificacion = "";

    // cargamos los datos a sus respectivas variables
    while(enContactoArchivo >> numero >> nombre >> apellido >> calificacion )
    {
        //creamos un nuevo nodo y covertimos la calificacion a un enteo
        //mediante la funcion atoi la cual le pasamos una representacion
        // de un objeto string c_str
        Nodo* nodo = new Nodo(atoi(calificacion.c_str()));
        cola->push(nodo);
    }
}

