/**
 * @file instrucciones.cpp
 * @author Pablo Jiménez Jiménez [pablojj1808@correo.ugr.es]
 * @brief Implementación de instrucciones
 * @version 0.1
 * @date 2019-12-29
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <iostream>
#include <stack>
#include "color.h"
#include "arbolbinario.h"
#include "instrucciones.h"
using namespace std;

extern acciones accions;

acciones & instrucciones::acc = accions;


ostream& operator<< (ostream &os, const instrucciones &ins){
    ArbolBinario<string> ab(ins.getAbb());
    string palabra= "";
    ArbolBinario<string>::postorden_iterador it= ab.beginpostorden();
    stack<string> pila;
    while(it!=ab.endpostorden()){
        palabra= *it;
        if(ins.acc.isAccion((*it))){
            if(!pila.empty()) {
                os << "\t" << (*it) << "\t" << pila.top()<<endl;
                pila.pop();
            }else{
                os << "\t" << (*it) << endl;
            }
        }else{
            pila.push(*it);
        }
        ++it;
    }
    return os;
}

instrucciones instrucciones::fusionarInstrucciones(const instrucciones &otro) {
    instrucciones nuevo;
    ArbolBinario<string> res("Acompañar");
    //ArbolBinario<string> aux1(datos);
    ArbolBinario<string> aux2(otro.getAbb());
    
    res.Insertar_Hi(res.getRaiz(), datos);

    res.Insertar_Hd(res.getRaiz(), aux2);


    nuevo.setAbb(res);

    return nuevo;
}



ArbolBinario<string> instrucciones::getAbb() const {
	return datos;
}

void instrucciones::setAbb(const ArbolBinario<string>& ab) {
	datos = ab;
}

istream & operator>>(istream & f, instrucciones & ins){

	if ( f ) {
		
		stack<ArbolBinario<string> > pila;
		ingrediente un_ingrediente;

		while( !f.eof() ) {
			string linea;
			getline(f, linea);
			
			int pos = linea.find(" ");
			string accion = linea.substr(0, pos);

			linea = linea.substr(pos + 1);
			if(pos==-1){
				linea="";
			}
			ArbolBinario<string> ab(accion);

			if(ins.acc.ariedad(accion) == 2) {  
				if( linea.size() == 0) { // SI No tiene nada al lado

					ab.Insertar_Hd(ab.getRaiz(), pila.top());
					pila.pop();
					ab.Insertar_Hi(ab.getRaiz(), pila.top());
					pila.pop();

				} else {

					ab.Insertar_Hi(ab.getRaiz(), pila.top());
					pila.pop();	
					ab.Insertar_Hd(ab.getRaiz(), linea);

				}

			} else {  

				if(linea.size()==0) { // SI No tiene nada al lado
					ab.Insertar_Hi(ab.getRaiz(), pila.top());
					pila.pop();
				} else { // Si está en la linea
					ab.Insertar_Hi(ab.getRaiz(), linea);
				}       	
			}

			pila.push( ab );
			
			ins.datos = pila.top();
		}
	}

	return f;
}
