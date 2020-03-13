/**
 * @file funciones.cpp
 * @author Pablo Jiménez Jiménez [pablojj1808@correo.ugr.es]
 * @brief Implementación de las funciones encargadas de dar funcionalidad al 
 *        módulo nutricion_receta
 * @version 0.1
 * @date 2019-11-24
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "color.h"
#include "funciones.h"
#include <ostream>
#include <algorithm>
using namespace std;

void MostrarNutrientes(ostream & f , const receta & r) {
    
    f << BOLD(UNDL("Información nutricional: ")) << endl;
    f << "\tCalorias    : " << r.getCalorias() << endl;
    f << "\tHidratos car: " << r.getHc() << endl;
    f << "\tProteinas   : " << r.getProteinas() << endl;
    f << "\tGrasas      : " << r.getGrasas() << endl;
    f << "\tFibra       : " << r.getFibra() << endl;
    f << endl;
}

void MostrarIngredientes(std::ostream & f , const receta & r) {
    receta::const_iterator it = r.begin();
    f << endl << BOLD(UNDL("Ingredientes: ")) << endl;
    ++it;
    ++it;
    while(  it != r.end() ) {

        f << "\t" << (*it).first << " " << (*it).second << endl;

        ++it;
    }
    f << endl;
}

void MostrarPasos(std::ostream & f , const receta & r) {
    f << endl << BOLD(UNDL("Pasos a seguir:")) << endl;
    
    instrucciones i = r.getInstrucciones();
    f << i << endl;
}

void MostrarRecetaCompleta(std::ostream & f , const receta & r) {
    f << BLUE(BOLD("CODE: ")) << r.getCode() << "  " << BLUE(BOLD("RECETA: ")) << r.getNombre()
        << "   " << BLUE(BOLD("PLATO: ")) << r.getPlato() << endl;
    MostrarIngredientes(f, r);
    MostrarNutrientes(f, r);
    MostrarPasos(f, r);
    f << endl << endl;
}
    
void MostrarRecetasEscogidas(ostream & f , const vector<receta> & r) {
    double cal = 0, prot= 0;
    f << "Las recetas escogidas son: " << endl;
    vector<receta>::const_reverse_iterator i = r.rbegin();
    while( i != r.rend() ) {
        f << *i;
        cal += (*i).getCalorias();
        prot += (*i).getProteinas();
        ++i;
    }
    f << endl << "Calorías totales: " << cal << "  Proteinas totales: " << prot << endl;
}

vector<receta> Mochila(const recetas & rs, int c_max) {
    // Inicializamos la matriz
    vector< vector<double> > tabla( rs.size() + 1 );
    for(unsigned i=0; i<tabla.size(); i++)
        tabla[i] = vector<double>( c_max + 1 , 0.0 );


    recetas::const_iterator it = rs.begin();
    
    //Algoritmo de la mochila
    for(int i=1; i <= rs.size(); i++) {
        for(int j=1; j <= c_max; j++) {
            if (j < (*it).getCalorias()) { 
                tabla[i][j] = tabla[i - 1][j];
            } else {
                tabla[i][j] = max(tabla[i - 1][j] , tabla[i - 1][j - (*it).getCalorias()] + (*it).getRazon());
            }
        }
        ++it;
    }


    it = rs.end();
    --it;
    vector<receta> salida; // filas escogidas
    int j = c_max;
    for (int i = rs.size(); i>0 && j>0; --i) {
        if (tabla[i][j] != tabla[i - 1][j]) {
            
            salida.push_back( *it );
            j -= (*it).getCalorias();
        }
        --it; 
    }
    
    return salida; 
}