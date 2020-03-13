/**
 * @file funciones.h
 * @author Pablo Jiménez Jiménez [pablojj1808@correo.ugr.es]
 * @brief Definición de las funciones que van a realizar el cálculo para 
 * obtener el mejor ingrediente
 * @version 1.0
 * @date 2019-11-23
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef funciones_h
#define funciones_h

#include <vector>
#include <iostream>
#include "recetas.h"

using namespace std;

/**
 * @brief Se encarga de visualizar todas las recetas del conjunto y descifrar
 * el número de calorias, hidratos de carbono, grasas, fibra de cada receta.
 * 
 * @param f flujo donde mostrar los resultados
 * @param r conjunto de recetas
 */
void MostrarNutrientes(std::ostream & f , const receta & r);

/**
 * @brief Imprime en {f} todos los ingredientes de la receta {r}
 * 
 * @param f Flujo de salida
 * @param r Receta de entrada
 */
void MostrarIngredientes(std::ostream & f , const receta & r);

/**
 * @brief Imprime en {f} los pasos que hay que dar para la elaboración
 * de la receta
 * 
 * @param f Flujo de salida
 * @param r Receta de entrada
 */
void MostrarPasos(std::ostream & f , const receta & r);


/**
 * @brief Se encarga de mostrar toda la información completa acerca 
 * de una receta. LLamada a MostrarIngredientes(..) + MostrarNutrientes(...)+
 * + MostrarPasos(..)
 * 
 * @param f Flujo de salida
 * @param r Receta de entrada
 */
void MostrarRecetaCompleta(std::ostream & f , const receta & r);

/**
 * @brief Se encarga de seleccionar el conjunto de recetas que maximizan 
 * la razón proteínas/hidratos sin pasar la cota {c_max} de calorias.
 * 
 * @note utiliza la técnica de programación dinámica.
 * 
 * @param rs Conjunto de inicial de recetas.
 * @param c_max Calorias máximas del conjunto elegido.
 * @return vector<receta> conjunto de recetas seleccionado.
 */
vector<receta> Mochila(const recetas & rs, int c_max);

/**
 * @brief Se encarga de visualizar todas las recetas que se le pasan en
 * el parámetro {r} e imprime las calorías y proteínas totales.
 * 
 * @param f flujo donde mostrar los resultados
 * @param r conjunto de recetas (requiere un objeto vector<receta>)
 */
void MostrarRecetasEscogidas(std::ostream & f , const vector<receta> & r);



#endif /* funciones_h */