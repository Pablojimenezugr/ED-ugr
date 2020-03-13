/**
 * @file acciones.cpp
 * @author Pablo Jiménez Jiménez [pablojj1808@correo.ugr.es]
 * @version 0.1
 * @date 2019-12-29
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "acciones.h"
#include <iostream>
#include <fstream>
using namespace std;

int acciones::ariedad(string acc){
    return datos[acc];
}

ostream & operator<<(ostream & f, const acciones & acc) {
    acciones::const_iterator it = acc.begin();
    while( it != acc.end() ) {
        f << (*it).first << " " << (*it).second << endl;
        ++it;
    }
    f << endl;
    return f;
}

bool acciones::isAccion(string acc) {
    auto it = datos.find(acc);
    return (it != datos.end()) ? true : false;
}

istream & operator>>(istream & f, acciones & acc) {
    acc.datos.clear();
    string linea;
    pair<string, unsigned> p;

    while( ! f.eof() ) {
        getline(f, linea);
        int pos = linea.find(" ");
        p.first = linea.substr(0, pos);
        linea = linea.substr(pos + 1);
        p.second = atoi( linea.c_str() );
        
        acc.datos.insert( p );
    }
    return f;
}

acciones::iterator acciones::begin() {
    iterator i;
    i.it = datos.begin();
    return i;
}
    
acciones::iterator acciones::end() {
    iterator i;
    i.it = datos.end();
    return i;
}

acciones::const_iterator acciones::begin() const {
    const_iterator i;
    i.it = datos.begin();
    return i;
}

acciones::const_iterator acciones::end() const {
    const_iterator i;
    i.it = datos.end();
    return i;
}