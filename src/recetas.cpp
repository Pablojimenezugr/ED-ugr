/**
 * @file recetas.cpp
 * @author Pablo Jiménez Jiménez [pablojj1808@correo.ugr.es]
 * @brief Implementación de la clase recetas.
 * @version 1.0
 * @date 2019-11-07
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <fstream>
#include "recetas.h"
#include "color.h"
#include <iostream>
using namespace std;

int recetas::size() const {
    return datos.size();
}

void recetas::calcularNutrientes(const ingredientes & ing) {
    map<string, receta>::iterator it;
    for(it = datos.begin(); it != datos.end(); ++it) {
        
        ((*it).second).calcularNutrientes( ing );
    }

}

void recetas::mostrarInfoPocoDetallada(ostream & os){
    map<string, receta>::iterator it;
    for(it = datos.begin(); it != datos.end(); ++it) {
        os << BLUE("CODE:") << " " << ((*it).second).getCode();
        os << "   ";
        os << BLUE("RECETA:") << " " << ((*it).second).getNombre();
        os << "   ";
        os << BLUE("PLATO:") << " " << ((*it).second).getPlato();
        os << endl;
    }
}

const receta recetas::operator[](const string & codigo) {
    auto it = datos.find(codigo);
    if ( it == datos.end() )
        return receta("Undefined");
    else
        return it->second;
}

const receta recetas::operator[](const string & codigo) const {
    auto it = datos.find(codigo);
    
    if ( it == datos.end() )
        return receta("Undefined");
    else
        return it->second;
}

void recetas::borrar(const string codigo) {
    auto itlow = datos.lower_bound(codigo);
    auto itupper = datos.upper_bound(codigo);

    datos.erase(itlow, itupper);
}

recetas::iterator recetas::begin() {
    iterator i;
    i.it = datos.begin();
    return i;
}

recetas::iterator recetas::end() {
    iterator i;
    i.it = datos.end();
    return i;
}

recetas::const_iterator recetas::begin() const {
    const_iterator i;
    i.it = datos.begin();
    return i;
}

pair<map<string, receta>::iterator, bool> recetas::insert(const pair<string, receta> & p) {
    return datos.insert(p);
}

recetas::const_iterator recetas::end() const {
    const_iterator i;
    i.it = datos.end();
    return i;
}

ostream& operator<<(ostream& flujo, const recetas & otro) {
    /*
     * Como los iteradores solo devuelven la receta no puedo usarlos
     */
    recetas::const_iterator it;
    for(it=otro.begin(); it!=otro.end(); ++it)
        flujo << *it << endl;

    flujo << endl;

    return flujo;
}

istream& operator>>(istream& flujo, recetas & otro) {
    otro.datos.clear();
    receta r;
    pair<string, receta> ele;

    while(flujo >> r) {
        ele.first = r.getCode();
        ele.second = r;
        otro.insert( ele );
    }
    
    return flujo;
}