/**
 * @file ingrediente.cpp
 * @author Pablo Jiménez Jiménez [pablojj1808@correo.ugr.es]
 * @brief Implementación de la clase ingrediente.
 * @version 1.0
 * @date 2019-10-11
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "ingrediente.h"
#include <iostream>

ingrediente::ingrediente(std::string nombre, double cal, double hc, double prot, double grasas, double fibra, std::string tipo) {
    this->nombre = nombre;
    calorias = cal;
    this->hc = hc;
    proteinas = prot;
    this->grasas = grasas;
    this->fibra = fibra;
    this->tipo = tipo;
}

string ingrediente::getNombre() const {
    return nombre;
}

void ingrediente::setNomre(string nombre) {
    this->nombre = nombre;
}

void ingrediente::setCalorias(double calorias) {
    this->calorias = calorias;
}

void ingrediente::setHc(double hc) {
    this->hc = hc;
}

void ingrediente::setProteinas(double proteinas) {
    this->proteinas = proteinas;
}

void ingrediente::setGrasas(double grasas) {
    this->grasas = grasas;
}

void ingrediente::setFibra(double fibra) {
    this->fibra = fibra;
}

void ingrediente::setTipo(string tipo) {
    this->tipo = tipo;
}

double ingrediente::getHc() const {
    return hc;
}

std::string ingrediente::getTipo() const{
    return tipo;
}

double ingrediente::getFibra() const {
    return fibra;
}

double ingrediente::getCalorias() const{
    return calorias;
}

double ingrediente::getGrasas() const{
    return grasas;
}

double ingrediente::getProteinas() const {
    return proteinas;
}

ostream & operator<<(ostream& flujo, const ingrediente& otro) {
    
    flujo << endl;
    flujo << otro.nombre << "; "<< otro.calorias << "; "<< otro.hc
            << "; " << otro.proteinas << "; "<< otro.grasas << "; "
            << otro.fibra << "; " << otro.tipo;

    return flujo;
}

istream& operator>>(istream& flujo, ingrediente& otro) {
    string linea;
    getline(flujo, linea);
    
    unsigned long pos = linea.find(";");
    otro.nombre = linea.substr(0, pos);
    
    linea = linea.substr(pos + 1);
    pos = linea.find(";");
    
    otro.calorias = atof(linea.substr(0,pos).c_str() );
    
    linea = linea.substr(pos + 1);
    pos = linea.find(";");
    
    otro.hc = atof(linea.substr(0,pos).c_str());
    
    linea = linea.substr(pos + 1);
    pos = linea.find(";");
    
    otro.proteinas = atof(linea.substr(0,pos).c_str());
    
    linea = linea.substr(pos + 1);
    pos = linea.find(";");
    
    otro.grasas = atof(linea.substr(0,pos).c_str());
    
    linea = linea.substr(pos + 1);
    pos = linea.find(";");
    
    otro.fibra = atof(linea.substr(0,pos).c_str());
    
    linea = linea.substr(pos + 1);
    pos = linea.find("\r");  // último carácter a buscar. Retorno de carro
    
    otro.tipo = linea.substr(0,pos);
    
    return flujo;
}
