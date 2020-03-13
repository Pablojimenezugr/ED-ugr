/**
 * @file ingrediente.h
 * @author Pablo Jiménez Jiménez [pablojj1808@correo.ugr.es]
 * @brief Definición de la clase ingredientes.
 *
 * @version 1.0
 * @date 2019-10-11
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef Ingredientes_h
#define Ingredientes_h

#include "ingrediente.h"
#include <vector>
using namespace std;

class ingredientes {
    
    vector<ingrediente> datos;
    
    vector<int> indices;
    
    /**
     * @brief Método auxiliar para el método Insertar, get y Borrar que averigua si está el ingrediente
     * y en que posición se debe de hacer la modificación.
     * @param ing ingrediente en cuestión.
     * @return si ya se encuentra en la posición y en que posición de la colección.
     */
    pair<bool, int> Esta_en_Datos(const ingrediente& ing);

    /**
     * @brief Método auxiliar para el método Insertar, get y Borrar que averigua si está el ingrediente
     * y en que posición se debe de hacer la modificación.
     * @note versión constante del método
     * @param ing ingrediente en cuestión.
     * @return si ya se encuentra en la posición y en que posición de la colección.
     */
    pair<bool, int> Esta_en_Datos(const string& nombre) const;
    
    /**
     * @brief Método auxiliar para el método Insertar y Borrar que averigua si está el ingrediente
     * y en que posición se debe de hacer la modificación.
     * @param ing ingrediente en cuestión.
     * @return si ya se encuentra en la posición y en que posición de la colección.
     */
    pair<bool, int> Esta_en_Indices(const ingrediente& ing);

    /**
     * @brief Limpia los dos vectores (datos e indices) de contenidos y los deja
     * listos para rellenarse de nuevo.
     */
    void Clear();
    
public:

    /**
     * @brief constructor por defecto para crear colecciones de
     * Ingrediente ordenadas por tipo y nombre.
     */
    ingredientes() = default;
    
    /**
     * @brief Insertar un ingrediente i en la colección.
     * @param i Ingrediente a insertar en las colecciones ordenadas.
     */
    void Insertar(const ingrediente& i);
    
    /**
     * @brief Borra si existe un ingrediente.
     * @param nombre nombre del ingrediente a borrar.
     */
    void borrar(string nombre);
    
    /**
     * @brief Modifica un ingrediente por otro
     * @param i posición del ingrediente a modificar
     * @param ing ingrediente a ocupar su nueva posición
     */
    void ModificaIngrediente(unsigned i, const ingrediente& ing);
    
    /**
     * @brief Obtiene el ingrediente nombre
     * @param nombre nombre del ingrediente a obtener.
     */
    ingrediente get(string nombre);

    /**
     * @brief Obtiene el ingrediente nombre
     * @param nombre nombre del ingrediente a obtener.
     */
    ingrediente get(string nombre) const;

    /**
     * @brief Devuelve si es un ingrediente o no
     * 
     * @param nombre nombre del ingrediente
     * @return true es un ingrediente
     * @return false no es un ingrediente
     */
    bool isIngrediente(string nombre);
    
    /**
     * @brief Recoge todos los tipos de ingredientes.
     * @return Array con todos los tipos de ingredientes.
     */
    vector<string> getTipos();
    
    /**
     * @brief Consultor del tamaño de la colección.
     * @return tamaño de la colección.
     */
    int size() const;
    
    /**
     * @brief Devuelve una colección de ingredientes que tienen en común el tipo.
     * @return colección de ingredientes con el mismo tipo.
     */
    ingredientes getIngredienteTipo(string tipo);
    
    /**
     * @brief Imprime todos los ingredientes ordenados por tipo.
     * @param flujo Flujo de salida.
     */
    void ImprimirPorTipo(ostream& flujo);
    
    /**
     * @brief Sobrecarga del operador de indexación.
     */
    const ingrediente& operator[](unsigned i);
    
    /**
     * @brief Sobrecarga del operador de indexación.
     * @note Versión constante.
     */
    const ingrediente& operator[](unsigned i) const;
    
    /**
     * @brief Operador de asignación.
     * @param otro objeto de tipo ingredientes.
     * @return una referencia al objeto al que apunta this.
     * @note la sobrecarga la efectúa de oficio el compilador pues no
     * tenemos memoria dinámica en esta clase.
     */
    ingredientes& operator=(const ingredientes& otro) = default;
    
    /**
     * @brief Sobrecarga el operador de extracción de flujo para sacar
     * por la salida estándar un objeto de tipo Ingredientes.
     * @param flujo es el flujo de salida.
     * @param otro el objeto a representar.
     */
    friend ostream& operator<<(ostream& flujo, const ingredientes& otro);
    
    /**
     * @brief Sobrecarga el operador de insercion para rellenar un objeto
     * de la clase Ingredientes.
     * @param flujo es el flujo de datos de entrada.
     * @param otro el objeto a rellenar.
     * hacer un clear que vacíe los vectores
     */
    friend istream& operator>>(istream& flujo, ingredientes& otro);
    
    class iterator {
        vector<ingrediente>::iterator it;
    public:
        iterator() = default;
        bool operator==(const iterator & i) const { return it == i.it; }
        bool operator!=(const iterator & i) const { return it != i.it; }
        const ingrediente & operator*() { return *it; }
        iterator & operator++() { ++it; return *this; }
        iterator & operator--() { --it; return *this; }

        friend class ingredientes;
    };
    
    class const_iterator {
        vector<ingrediente>::const_iterator it;
    public:
        const_iterator() = default;
        const_iterator(const iterator & i) : it(i.it) { }
        bool operator==(const const_iterator & i) const { return it == i.it; }
        bool operator!=(const const_iterator & i) const { return it != i.it; }
        const ingrediente & operator*() const { return *it; }
        const_iterator & operator++() { ++it; return *this; }
        const_iterator & operator--() { --it; return *this; }

        friend class ingredientes;
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
     * @brief Obtiene el iterador constante posiconado
     * en el primer elemento del contenedor.
     * @return const_iterator 
     */
    const_iterator begin() const;
    
    /**
     * @brief Obtiene el iterador constante posiconado
     * en el último elemento del contenedor.
     * @return const_iterator 
     */
    const_iterator end() const;
    
};


#endif /* ingrediente_h */
