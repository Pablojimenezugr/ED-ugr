/**
 * @file recetas.h
 * @author Pablo Jiménez Jiménez [pablojj1808@correo.ugr.es]
 * @brief Definición de la clase receta.
 * @version 1.0
 * @date 2019-11-07
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef recetas_h
#define recetas_h

#include "receta.h"
#include <string>
#include <map>
using namespace std;

class recetas {
    
    map<string, receta> datos;

public:
    /**
     * @brief constructor por defecto para crear colecciones de
     * recetas.
     */
    recetas() = default;

    /**
     * @brief Número de recetas almacenadas.
     * 
     * @return número de recetas almacenadas. 
     */
    int size() const;

    /**
     * @brief Sobrecarga del operador []
     * 
     * @param codigo clave para buscar la receta asociada.
     * @return receta constante para que no se pueda modificar. 
     *          Si no la encuentra saca un "Undefined"
     */
    const receta operator[](const string & codigo);

    /**
     * @brief Sobrecarga del operador [] versión constante.
     * 
     * @param codigo clave para buscar la receta asociada.
     * @return receta constante para que no se pueda modificar
     *         Si no la encuentra saca un "Undefined"
     */
    const receta operator[](const string & codigo) const;

    /**
     * @brief Inserta una pareja nombre (clave) , receta.
     * 
     * @param p la pareja
     * @return pair<map<string, receta>::iterator, bool> iterador donde se ha insertado
     * y se ha realizado la inserción o ya estaba repetido.
     */
    pair<map<string, receta>::iterator, bool> insert(const pair<string, receta> & p);

    /**
     * @brief Borra si existe la receta asociada al parámetro
     * 
     * @param codigo es la clave asociada a la receta
     */
    void borrar(const string codigo);

    /**
     * @brief Se encarga de calcular las calorias, hidratos de carbono, 
     * grasas, fibra, proteinas de cada una de las receta del objeto.
     * 
     * @param ing los ingredientes de donde se obtienen los datos.
     */
    void calcularNutrientes(const ingredientes & ing);

    /**
     * @brief Muestra el código, nombre y plato de
     * todas las recetas.
     * @param os flujo donde se escriben los datos.
     */
    void mostrarInfoPocoDetallada(ostream & os);

    class iterator {
        map<string, receta>::iterator it;
    public:
        iterator() = default;
        bool operator==(const iterator & i) const { return it == i.it; }
        bool operator!=(const iterator & i) const { return it != i.it; }
        const receta & operator*() { return it->second; }
        iterator & operator++() { ++it; return *this; }
        iterator & operator--() { --it; return *this; }

        friend class recetas;
    };

    class const_iterator {
        map<string, receta>::const_iterator it;
    public:
        const_iterator() = default;
        bool operator==(const const_iterator & i) const { return it == i.it; }
        bool operator!=(const const_iterator & i) const { return it != i.it; }
        const receta & operator*() const { return it->second; }
        const_iterator & operator++() { ++it; return *this; }
        const_iterator & operator--() { --it; return *this; }

        friend class recetas;
    };

    /**
     * @brief Obtiene un iterador posiconado
     * en el primer elemento del contenedor.
     * @return iterator 
     */
    iterator begin();

    /**
     * @brief Obtiene un iterador posiconado
     * en el último elemento del contenedor.
     * @return iterator 
     */
    iterator end();

    /**
     * @brief Obtiene un iterador posiconado
     * en el primer elemento del contenedor.
     * @return iterator constante
     */
    const_iterator begin() const;

    /**
     * @brief Obtiene un iterador posiconado
     * en el último elemento del contenedor.
     * @return iterator constante
     */
    const_iterator end() const;
    
    /**
     * @brief Sobrecarga el operador de extracción de flujo para sacar
     * por la salida estándar un objeto de tipo recetas.
     * @param flujo es el flujo de salida.
     * @param otro el objeto a representar.
     */
    friend ostream& operator<<(ostream& flujo, const recetas & otro);
    
    /**
     * @brief Sobrecarga el operador de insercion para rellenar un objeto
     * de la clase recetas.
     * @param flujo es el flujo de datos de entrada.
     * @param otro el objeto a rellenar.
     */
    friend istream& operator>>(istream& flujo, recetas & otro);

};

#endif /* recetas_h */