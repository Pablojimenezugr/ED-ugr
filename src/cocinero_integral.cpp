/**
 * @file cocinero_integral.cpp
 * @author Pablo Jiménez Jiménez [pablojj1808@correo.ugr.es]
 * @brief Fichero principal
 * @date 2019-12-29
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <iostream>
#include "color.h"
#include <fstream>
#include "acciones.h"
#include "ingredientes.h"
#include "instrucciones.h"
#include "recetas.h"
#include "funciones.h"
using namespace std;

acciones accions;

void args_incorrectos();

int main(int argc, char * argv[]) {

    if( argc != 4 )
        args_incorrectos();

    ifstream f( argv[1] );
    ifstream fi( argv[2] );
    ifstream f_r( argv[3] );
    f >> accions;
    ingredientes i;
    fi >> i;
    recetas r;
    f_r >> r;

    r.calcularNutrientes(i);
    r.mostrarInfoPocoDetallada(cout); // muestro todas las recetas
    
    string cod;
    do {
        cout << "Sobre que código quieres recibir información: ";
        cin >> cod;
    } while(r[cod].getNombre() == "Undefined");
    
    cout << endl << endl;


    string nom_fich = cod + "m.txt";


    receta elegida = r[cod];
    instrucciones ins;

    ifstream fich("datos/instrucciones/" + nom_fich);

    fich >> ins;
    
    elegida.setInstrucciones(ins);


    MostrarRecetaCompleta(cout, elegida);

    string cod1, cod2;
    cout << "Introduce los dos códigos de las recetas a fusionar" << endl;
    bool parar;
    do {
        cout << YEL("~> ");
        cin >> cod1;
        cout << YEL("~> ");
        cin >> cod2;
        if (r[cod1].getNombre() == "Undefined" || r[cod2].getNombre() == "Undefined"){
            parar = true;
        }
    } while( parar );

    cout << endl << endl;

    // FUSIÓN DE RECETAS ----------------------------------------------------------------------


    receta r1 = r[cod2];
    string final = "datos/instrucciones/" + cod1 + "m.txt";
    ifstream _f(final);
    instrucciones _i;
    _f >> _i;

    r1.cargarInstrucciones(_i);
   
    receta r2 = r[cod1];
    final = "datos/instrucciones/" + cod2 + "m.txt";
    ifstream _f2(final);
    _f2 >> _i;

    r2.cargarInstrucciones(_i);


    receta fusion = r1.fusionarReceta( r2 );


    // Muestro la receta que es fusión de las dos elegidas.
    MostrarRecetaCompleta(cout, fusion);

    return 0;
}

void args_incorrectos() {
    cout << _RED("Uso incorrecto:") << endl;
    cout << _RED("./cocinero_integral datos/Acciones.txt datos/ingredientes.txt datos/recetas.txt");
    cout << endl;
    exit(-1);
}