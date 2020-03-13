/**
 * @file nutricion_receta.cpp
 * @author Pablo Jiménez Jiménez [pablojj1808@correo.ugr.es]
 * @brief Main() del módulo nutricion_receta
 * @version 0.1
 * @date 2019-11-24
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <iostream>
#include <fstream>
#include "recetas.h"
#include "ingredientes.h"
#include "funciones.h"
using namespace std;

int main(int argc, char const *argv[])
{
    if( argc != 4) {
        cerr << "Error de argumentos. Ejemplo de llamada:" << endl;
        cerr << "./bin/nutricion_receta datos/recetas.txt datos/ingredientes.txt 500" << endl;
        exit(-1);
    }    

    double calorias_max = atof( argv[3] );
    ifstream nutrientes( argv[2] ); // fichero con los ingredientes
    ifstream frecetas( argv[1] );   // fichero con las recetas

    if(!nutrientes || !frecetas) {
        cerr << "Error con los archivos " << endl;
        exit(-1);
    }

    string s;
    getline(nutrientes, s);

    ingredientes all;
    nutrientes >> all;
    recetas r;
    frecetas >> r;
    r.calcularNutrientes(all);

    

    MostrarNutrientes(cout, r);

    cout << "===================================================================" << endl;

    MostrarRecetasEscogidas( cout, Mochila(r, calorias_max) );


    
    return 0;
}
