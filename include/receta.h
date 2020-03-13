/**
 * @file receta.h
 * @author Pablo Jiménez Jiménez [pablojj1808@correo.ugr.es]
 * @brief Definición de la clase receta.
 * @version 1.0
 * @date 2019-11-07
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef receta_h
#define receta_h

#include "instrucciones.h"
#include "ingredientes.h"
#include <string>
#include <list>
using namespace std;

class receta {
    string code;
    unsigned int plato;
    string nombre;
    list< pair<string, unsigned int> > ings;

    double calorias;
    double hc;
    double grasas;
    double proteinas;
    double fibra;
    double razon;

    instrucciones inst;


    /**
     * @brief Esta el ingrediente en la lista de ingredientes de la
     * receta?
     * 
     * @param ing ingrediente a buscar si está
     * @return true si está
     * @return false no está
     */
    bool isIngrediete(const string & ing) const;

    /**
     * @brief Añade un ingrediente nuevo a la lista de ingredientes
     * a la receta.
     * 
     * @param ing ingrediente nuevo añadir
     * @param gramos cantidad en gramos de {ing}
     */
    void aniadirIngrediente(const string & ing, int gramos);

    /**
     * @brief Modifica la cantidad de gramos de un ingrediente
     * 
     * @param ing ingrediente a modificar
     * @param gramos nueva cantidad asignada
     */
    void modificarCantidad(const string & ing,int gramos);

    /**
     * @brief Modifica los valores nutricionales de toda la receta. Recibe
     * un vector que tomará los nuevos valores en este orden: {calorias,
     * hidratos de carbono, grasas, proteinas, fibra, razon}
     * 
     * @param nuevos el array con los nuevos valores. tamaño = 6
     */
    void modificarValoresNutricionales(double nuevos[]);

    

public:

    /**
     * @brief Cambia el código de la receta
     * 
     * @param nuevo nuevo codigo
     */
    void setCode(const string& nuevo);


    /**
     * @brief constructor por defecto para crear objetos
     * de tipo receta
     */
    receta() = default;

    /**
     * @brief constructor con parámetro. Se pasan las instrucciones
     * de la receta.
     */
    receta(const instrucciones& ins) :inst(ins) {  }

    /**
     * @brief Constructor con parámetro para crear
     * objetos de tipo receta
     * 
     * @param nombre nombre de la receta
     */
    receta( const string & nombre);

    /**
     * @brief Constructor de copia
     * 
     * @param otra Receta a copiar
     */
    receta(const receta & otra) = default;

    /**
     * @brief Se encarga de vaciar todos los atributos
     * de un objeto de tipo receta. 
     */
    void Clear();

    /**
     * @brief Get the Code object
     * 
     * @return const string el código de la receta
     */
    const string getCode() const;

    /**
     * @brief Obtiene el nombre de la receta
     * 
     * @return string nombre
     */
    string getNombre() const;

    /**
     * @brief Establece un nuevo nombre
     * 
     * @param nuevo nuevo nombre
     */
    void setNombre(const string & nuevo);


    /**
     * @brief Obtiene el número de ingredientes que necesita
     * la receta
     * 
     * @return int número de ingredientes
     */
    int ningredientes() const;

    /**
     * @brief Obtenemos la cantidad de gramos necesarios
     * de un ingrediente
     * 
     * @param ing ingrediente que nos interesa
     * @return int gramos. 0 si no está el ingrediente en la receta
     */
    double getGramos(const string& ing) const;

    /**
     * @brief Get the Calorias object
     * @note se tiene que invocar antes el método {calcularNutrientes(const ingredientes & ings)}
     * para obtener el valor real.
     * @return double calorias
     */
    double getCalorias() const;

    /**
     * @brief Get the Hc object
     * @note se tiene que invocar antes el método {calcularNutrientes(const ingredientes & ings)}
     * para obtener el valor real.
     * @return double hidratos de carbono
     */
    double getHc() const;

    /**
     * @brief Get the Proteinas object
     * @note se tiene que invocar antes el método {calcularNutrientes(const ingredientes & ings)}
     * para obtener el valor real.
     * @return double proteinas
     */
    double getProteinas() const;

    /**
     * @brief Get the Fibra object
     * @note se tiene que invocar antes el método {calcularNutrientes(const ingredientes & ings)}
     * para obtener el valor real.
     * @return double fibra
     */
    double getFibra() const;

    /**
     * @brief Get the Grasas object
     * @note se tiene que invocar antes el método {calcularNutrientes(const ingredientes & ings)}
     * para obtener el valor real.
     * @return double grasas
     */
    double getGrasas() const;

    /**
     * @brief Obtiene al razón de proteinas/hidratos de carbono 
     * de la receta
     * @note se tiene que invocar antes el método {calcularNutrientes(const ingredientes & ings)}
     * para obtener el valor real.
     * @return double razón 
     */
    double getRazon() const;

    /**
     * @brief Get the Plato object
     * 
     * @return unsigned 
     */
    unsigned getPlato() const;

    /**
     * @brief Set the instrucciones object
     * 
     * @param ins instrucciones object
     */
    void setInstrucciones(const instrucciones & ins);


    /**
     * @brief Retorna si lo pasado como argumento es un ingrediente 
     * o no.
     * 
     * @param ing ingrediente en cuestión
     * @return true se encuentra el ingrediente
     * @return false no se encuentra el ingrediente
     */
    bool esIngrediente(const string & ing) const;

    /**
     * @brief Se encarga de calcular las calorias, hidratos de carbono, 
     * grasas, fibra, proteinas de la receta
     * 
     * @param ings los ingredientes de donde se obtienen los datos.
     */
    void calcularNutrientes(const ingredientes & ings);

    /**
     * @brief Se encarga de adjuntar al objeto sus instrucciones
     * de cocina.
     * 
     * @param ins Objeto que implementa las instrucciones
     */
    void cargarInstrucciones(const instrucciones & ins);

    /**
     * @brief Se encarga de fusionar dos recetas dadas
     * 
     * @param otra la otra receta
     * @return receta receta fruto de la fusión de las dos anteriores.
     */
    receta fusionarReceta(const receta& otra) const;

    /**
     * @brief Retorna las instrucciones de dicha receta
     * 
     * @return instrucciones 
     */
    instrucciones getInstrucciones() const;

    class iterator {
        list< pair<string, unsigned int> >::iterator it;
    public:
        iterator() = default;
        bool operator==(const iterator & i) const { return it == i.it; }
        bool operator!=(const iterator & i) const { return it != i.it; }
        pair<string, unsigned int> & operator*() { return *it; }
        iterator & operator++() { ++it; return *this; }
        iterator & operator--() { --it; return *this; }

        friend class receta;
    };

    class const_iterator {
        list< pair<string, unsigned int> >::const_iterator it;
    public:
        const_iterator() = default;
        bool operator==(const const_iterator & i) const { return it == i.it; }
        bool operator!=(const const_iterator & i) const { return it != i.it; }
        const pair<string, unsigned int> & operator*() const { return (*it); }
        const_iterator & operator++() { ++it; return *this; }
        const_iterator & operator--() { --it; return *this; }

        friend class receta;
    };

    /**
     * @brief Obtiene un iterador posiconado
     * en el primer elemento del contenedor.
     * @return iterator 
     */
    iterator begin();

    /**
     * @brief Obtiene el iterador posiconado
     * en el último elemento del contenedor.
     * @return const_iterator 
     */
    iterator end();

    /**
     * @brief Obtiene un iterador constante posiconado
     * en el primer elemento del contenedor.
     * @return iterator 
     */
    const_iterator begin() const;

    /**
     * @brief Obtiene el iterador constante posiconado
     * en el último elemento del contenedor.
     * @return const_iterator 
     */
    const_iterator end() const;
    
    /**
     * @brief Sobrecarga el operador de extracción de flujo para sacar
     * por la salida estándar un objeto de tipo receta.
     * @param flujo es el flujo de salida.
     * @param otro el objeto a representar.
     */
    friend ostream& operator<<(ostream& flujo, const receta & otro);
    
    /**
     * @brief Sobrecarga el operador de insercion para rellenar un objeto
     * de la clase receta.
     * @param flujo es el flujo de datos de entrada.
     * @param otro el objeto a rellenar.
     */
    friend istream& operator>>(istream& flujo, receta & otro);

};

#endif /* receta_h */