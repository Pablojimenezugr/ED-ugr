/**
 * @file receta.cpp
 * @author Pablo Jiménez Jiménez [pablojj1808@correo.ugr.es]
 * @brief Implementación de la clase receta.
 * @version 1.0
 * @date 2019-11-07
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <string>
#include <iostream>
#include "receta.h"
#include "color.h"
#include "ingredientes.h"
using namespace std;


unsigned receta::getPlato() const {
    return plato;
}

void receta::cargarInstrucciones(const instrucciones & ins) {

    inst = ins;

}


bool receta::esIngrediente(const string & ing) const {
    receta::const_iterator it = begin();
    bool salida = false;
    while( it != end() ) {
        
        string sin_espacio = ((*it).first).substr(0, ((*it).first).length() -1 );
        if( sin_espacio == ing )
            salida = true;

        ++it;
    }
    return salida;
}

void receta::setInstrucciones(const instrucciones & ins) {
    inst = ins;
}


void receta::calcularNutrientes(const ingredientes & ing) {
    iterator it = begin();

    while(it != end()) {
        string n = (*it).first;
        n = n.substr(0, n.size() - 1);
        
        ingrediente j = ing.get( n );

        if( j.getNombre() != "Undefined" ) {
            calorias += ((*it).second) * j.getCalorias() / 100;
            hc += ((*it).second) * j.getHc() / 100;
            grasas += ((*it).second) * j.getGrasas() / 100;
            proteinas += ((*it).second) * j.getProteinas() / 100;
            fibra += ((*it).second) * j.getFibra() / 100;
        }
        ++it;
    }

    razon = proteinas / hc;

}

bool receta::isIngrediete(const string & ing) const {

    receta::const_iterator it = begin();
    while( it != end() ) {

        if( (*it).first == ing )
            return true;

        ++it;
    } 
    return false;
}


instrucciones receta::getInstrucciones() const {
	return inst;
}



void receta::aniadirIngrediente(const string & ing, int gramos) {
    ings.push_back( make_pair(ing, gramos) );
}

void receta::modificarCantidad(const string & ing, int gramos) {
    receta::iterator it = begin();
    bool parar = false;
    
    while( it != end() && !parar ) {
        if( (*it).first == ing ) {
            (*it).second = gramos;
            parar = true;
        }
        
        ++it;
    } 
}

void receta::modificarValoresNutricionales(double nuevos[]) {
    this->calorias = nuevos[0];
    this->hc = nuevos[1];
    this->grasas = nuevos[2];
    this->proteinas = nuevos[3];
    this->fibra = nuevos[4];
    this->razon = nuevos[5];
}

receta receta::fusionarReceta(const receta& otra) const {
    receta nueva( otra );

    nueva.nombre = "Fusión " + getNombre() + " y " + otra.getNombre();
    nueva.code = "F_" + getCode() + "_" + otra.getCode();
    int _plato;
    _plato = (plato < otra.getPlato()) ? plato : otra.getPlato();
    nueva.plato = _plato;

    receta::const_iterator it = begin();

    while(it != end()) {
        
        // 1. Modificamos ingredientes
        if( nueva.isIngrediete( (*it).first ) ) {

            nueva.modificarCantidad((*it).first , (*it).second + otra.getGramos((*it).first));

        } else {
            nueva.aniadirIngrediente((*it).first, (*it).second);
        }

        // 2. Modificamos los valores nutricionales
        double * n = new double[6];
        n[0] = getCalorias() + otra.getCalorias();
        n[1] = getHc() + otra.getHc();
        n[2] = getGrasas() + otra.getGrasas();
        n[3] = getProteinas() + otra.getProteinas();
        n[4] = getFibra() + otra.getFibra();
        n[5] = getRazon() + otra.getRazon();

        nueva.modificarValoresNutricionales(n);

        delete n;


        // 3. Añadimos pasos de la receta
       
        instrucciones fusion = getInstrucciones().fusionarInstrucciones(otra.getInstrucciones());


        nueva.setInstrucciones(fusion);

        ++it;
    }

    return nueva;
}

double receta::getGramos(const string& ing) const {
    int salida = 0;

    if(isIngrediete(ing)) {
        receta::const_iterator it = begin();
        while( it != end() ) {

            if( (*it).first == ing )
                return (*it).second;

            ++it;
        } 
    }

    return salida;
}



receta::receta( const string & nombre) {
    this->nombre = nombre;
}

string receta::getNombre() const {
    return nombre;
}

int receta::ningredientes() const {
    return ings.size();
}

double receta::getCalorias() const {
    return calorias;
}

double receta::getHc() const {
    return hc;
}

double receta::getGrasas() const {
    return grasas;
}

double receta::getProteinas() const {
    return proteinas;
}

double receta::getFibra() const {
    return fibra;
}

const string receta::getCode() const {
    return code;
}

double receta::getRazon() const {
    return razon;
}

ostream & operator<<(ostream & flujo, const receta & otro) {
    
    flujo << otro.code << "; " << otro.plato << "; " << otro.nombre << "; ";
    
    list< pair<string, unsigned int> >::const_iterator i;
    for(i=otro.ings.begin(); i!=otro.ings.end(); ++i)
        flujo << i->first << " " << i->second << "; ";
    
    flujo << endl;

    return flujo;
}

void receta::Clear() {
    this->code="";
    this->plato=0;
    string nombre="";
    ings.clear();
    calorias= hc= grasas= proteinas= fibra= 0;
}

istream & operator>>(istream & flujo, receta & otro) 
{
    otro.Clear();
    string linea;
    getline(flujo, linea);

    unsigned long pos = linea.find(";");
    otro.code = linea.substr(0, pos);
    
    linea = linea.substr(pos + 1);

    pos = linea.find(";");
    otro.plato = atoi(linea.substr(0, pos).c_str());
    
    linea = linea.substr(pos + 1); 
    
    pos = linea.find(";");
    otro.nombre = linea.substr(0, pos);
    
    linea = linea.substr(pos + 1);
    
    string::const_iterator i;
    pair<string, unsigned int> p;
    string n1="", n="";
    for(i=linea.cbegin(); i!=linea.cend(); ++i) {
        
        if (*i == ';') {
            p.first = n1;
            p.second = atoi(n.c_str());
            otro.ings.push_back(p);
            n1 = "";
            n = "";
        } else if(!isdigit(*i)) {
            n1 += *i;
        } else if (isdigit(*i)) {
            n += *i;
        } 
    }
    //Recupero el ultimo que no tiene ';'
    p.first = n1;
    p.second = atoi(n.c_str());   
    otro.ings.push_back(p); 

    otro.calorias=otro.hc=otro.fibra=otro.grasas=otro.proteinas = 0;

    return flujo;
}

receta::iterator receta::begin() {
    iterator i;
    i.it = ings.begin();
    return i;
}

receta::iterator receta::end() {
    iterator i;
    i.it = ings.end();
    return i;
}

receta::const_iterator receta::begin() const {
    const_iterator i;
    i.it = ings.begin();
    return i;
}

receta::const_iterator receta::end() const {
    const_iterator i;
    i.it = ings.end();
    return i;
}