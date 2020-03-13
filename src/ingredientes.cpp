/**
 * @file ingredientes.cpp
 * @author Pablo Jiménez Jiménez [pablojj1808@correo.ugr.es]
 * @brief Implementación de la clase ingredientes.
 * @version 1.0
 * @date 2019-10-11
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <utility>
#include <algorithm>
#include <cassert>
#include <istream>
#include "ingredientes.h"

void ingredientes::Clear() {
    datos.clear();
    indices.clear();
}

pair<bool, int> ingredientes::Esta_en_Datos(const ingrediente& ing) {
    
    pair<bool, int> salida(false, 0);
    
    if(datos.size() != 0) {
      int izda = 0;
      int dcha = datos.size()-1;
      bool encontrado = false;
      int centro;

      while (izda <= dcha  &&  !encontrado){
          centro = (izda + dcha) / 2;

          if (datos[centro].getNombre() == ing.getNombre()) {
              encontrado = true;
              salida.first = true;
              salida.second = centro;
              return salida;
          } else if (ing.getNombre() < datos[centro].getNombre()) {
              dcha = centro-1;
          } else {
              izda = centro + 1;
          }
      }
      salida.first = false;
      salida.second = izda;
      return salida;
    } else {
      return salida;
    }
}

pair<bool, int> ingredientes::Esta_en_Datos(const string& nombre) const {
    
    pair<bool, int> salida(false, 0);
    
    if(datos.size() != 0) {
      int izda = 0;
      int dcha = datos.size()-1;
      bool encontrado = false;
      int centro;

      while (izda <= dcha  &&  !encontrado){
          centro = (izda + dcha) / 2;
            
          if (datos[centro].getNombre() == nombre) {
              encontrado = true;
              salida.first = true;
              salida.second = centro;
              
              return salida;
          } else if (nombre < datos[centro].getNombre()) {
              dcha = centro-1;
          } else {
              izda = centro + 1;
          }
      }
      salida.first = false;
      salida.second = izda;
      return salida;
    } else {
      return salida;
    }
}

pair<bool, int> ingredientes::Esta_en_Indices(const ingrediente &ing) {
    
    pair<bool, int> salida(false, 0);
    
    if(indices.size() != 0){
      int izda = 0;
      int dcha = indices.size()-1;
      bool encontrado = false;
      int centro = 0;

      while (izda <= dcha  &&  !encontrado){
          centro = (izda + dcha) / 2;
          
          bool iguales = ( datos[indices[centro]].getTipo() == ing.getTipo() && datos[indices[centro]].getNombre() == ing.getNombre() );
          
          if ( iguales ) { // y el nombre
              encontrado = true;
              salida.first = true;
              salida.second = centro;
              return salida;
          } else if (datos[indices[centro]].getTipo() < ing.getTipo()) {
              izda = centro + 1;
          } else if(datos[indices[centro]].getTipo() > ing.getTipo()) { // >
              dcha = centro - 1;
          } else if(datos[indices[centro]].getTipo() == ing.getTipo() && datos[indices[centro]].getNombre() < ing.getNombre()) {
              
              izda = centro + 1;
              
          } else if ( datos[indices[centro]].getTipo() == ing.getTipo() && datos[indices[centro]].getNombre() > ing.getNombre() ) {
              
              dcha = centro - 1;
              
          }
        }
        salida.first = false;
        salida.second = izda;
        return salida;
    } else {
      return salida;
    }
}

void ingredientes::Insertar(const ingrediente& i) {
    pair<bool, int> dat = Esta_en_Datos(i);
    pair<bool, int> indice = Esta_en_Indices(i);
    
    datos.insert(datos.begin() + dat.second , i);
    for (unsigned i=0; i<indices.size(); i++)
        if ( indices[i] >= dat.second )
            indices[i]++;
    
    indices.insert(indices.begin() + indice.second , dat.second);
}

void ingredientes::borrar(string nombre){
    ingrediente i(nombre);
    int pos_indices = 0;
    pair <bool, int> a = Esta_en_Datos(i);
    do{
        // Busco en indices donde está.
        bool enco = false;
        for (unsigned i=0; i<indices.size() && !enco; i++) {
            if(indices[i] == a.second) {
                pos_indices = i;
                enco = true;
            }
        }
        //Decremento los índices.
        for (unsigned i=0; i<indices.size(); i++)
            if ( indices[i] > pos_indices )
                indices[i]--;
        // Borro las posiciones
        datos.erase(datos.begin() + a.second);
        indices.erase(indices.begin() + pos_indices);
        
        // Para ver si hay que repetir el bucle
        a = Esta_en_Datos(i);
    } while(a.first);
}


void ingredientes::ModificaIngrediente(unsigned i, const ingrediente& ing){
    assert(i>=0 && i<=datos.size());
    datos[i] = ing;
}

bool ingredientes::isIngrediente(string nombre) {
    ingrediente i = get(nombre);
    return (i.getNombre() != "Undefined") ? true : false;
}

vector<string> ingredientes::getTipos() {
    vector<string> salida;
    
    for (unsigned i = 0; i < datos.size(); i++)
        salida.push_back(datos[indices[i]].getTipo());
    
    auto i = unique(salida.begin(), salida.end());
    salida.resize(distance(salida.begin(), i));
    
    return salida;
}

ingredientes ingredientes::getIngredienteTipo(string tipo) {
    ingredientes salida;
    
    //tipo += "\r"; Ya se lo he eliminado en el operador >>
    for(unsigned i=0; i<datos.size(); i++)
        if(datos[i].getTipo() == tipo)
            salida.Insertar(datos[i]);
            
    return salida;
}

ingrediente ingredientes::get(string nombre) {
    
    ingrediente ing(nombre);
    pair<bool, int> esta = Esta_en_Datos(ing);
    
    if(esta.first)
        return datos[esta.second];
    else {
        ing.setNomre("Undefined");
        return ing;
    }
}



ingrediente ingredientes::get(string nombre) const {

    for(unsigned i=0; i<datos.size(); i++) {
        if (datos[i].getNombre() == nombre) {
            return datos[i];
        }
    }
    return ingrediente("Undefined");
}

void ingredientes::ImprimirPorTipo(ostream &flujo) {
    
    for(unsigned i=0; i<indices.size(); i++)
        flujo << datos[indices[i]];
    
}

int ingredientes::size() const {
    return datos.size();
}

const ingrediente& ingredientes::operator[](unsigned i){
    assert(i>=0 && i<=datos.size());
    return datos[i];
}


const ingrediente& ingredientes::operator[](unsigned i) const{
    assert(i>=0 && i<=datos.size());
    return datos[i];
}

ostream& operator<<(ostream& flujo, const ingredientes& otro) {
    for(unsigned i=0; i<otro.datos.size(); i++) {
        cout << otro.datos[i];
    }
    flujo << endl << endl;
    return flujo;
}

istream& operator>>(istream& flujo, ingredientes& ings){
    
    ings.Clear();
    ingrediente ing;

    string basura;
    getline( flujo, basura);
    
    while (flujo >> ing) {
        ings.Insertar(ing);
    }
    
    return flujo;
}

ingredientes::iterator ingredientes::begin() {
    iterator i;
    i.it = datos.begin();
    return i;
}
    
ingredientes::iterator ingredientes::end() {
    iterator i;
    i.it = datos.end();
    return i;
}
    
ingredientes::const_iterator ingredientes::begin() const {
    const_iterator i;
    i.it = datos.begin();
    return i;
}
    
ingredientes::const_iterator ingredientes::end() const {
    const_iterator i;
    i.it = datos.end();
    return i;
}