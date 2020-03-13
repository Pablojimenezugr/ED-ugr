/**
 * @file ingrediente.h
 * @author Pablo Jiménez Jiménez [pablojj1808@correo.ugr.es]
 * @brief Definición de la clase ingrediente.
 * @version 1.0
 * @date 2019-10-11
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef ingrediente_h
#define ingrediente_h

#include <string>
#include <iostream>
using namespace std;


class ingrediente {
    string nombre;
    double calorias;
    double hc;
    double proteinas;
    double grasas;
    double fibra;
    string tipo;
    
public:
    /**
     * @brief Constructor por defecto
     */
    ingrediente() = default;
    
    /**
     * @brief Constructor por parámetros. Construye objetos de tipo
     *  Ingrediente con todos sus atributos inicializados. Permite asignarle al ingrediente
     *  únicamente un nombre
     */
    ingrediente(string nombre, double cal=0.0, double hc=0.0, double prot=0.0, double grasas=0.0, double fibra=0.0, string tipo="");
    
    /**
     * @brief Constructor de copia por defecto (no tenemos memoria dinámica)
     */
    ingrediente(const ingrediente& otro) = default;
    
    /**
     * @brief Destructor por defecto (no tenemos memoria dinámica)
    */
    ~ingrediente() = default;
    
    /**
     * @brief Consultor del atributo nombre.
     */
    string getNombre() const;
    
    /**
     * @brief Modificador del atributo nombre
     * @param nombre nuevo nombre a asignar
     */
    void setNomre(string nombre);
    
    /**
     * @brief Establece nuevas calorias.
     * @param calorias: nuevas calorias.
     */
    void setCalorias(double calorias);
    
    /**
     * @brief Establece nuevos hidratos de carbono.
     * @param hc: nuevos hidratos de carbono.
    */
    void setHc(double hc);
    
    /**
     * @brief Establece nuevas proteinas.
     * @param proteinas: nuevas proteinas.
     */
    void setProteinas(double proteinas);
    
    /**
     * @brief Establece nuevas grasas.
     * @param grasas: nuevas grasas.
     */
    void setGrasas(double grasas);
    
    /**
     * @brief Establece nueva fibra.
     * @param fibra: fibra.
     */
    void setFibra(double fibra);
    
    /**
    * @brief Establece nuevo tipo.
    * @param calorias: nuevo tipo.
    */
    void setTipo(string tipo);
    
    /**
     * @brief Consultor del atributo calorias.
     */
    double getCalorias() const;
    
    /**
     * @brief Consultor del atributo hidratos de carbono.
     */
    double getHc() const;
    
    /**
     * @brief Consultor del atributo proteinas.
    */
    double getProteinas() const;
    
    /**
     * @brief Consultor del atributo grasas.
     */
    double getGrasas() const;
    
    /**
     * @brief Consultor del atributo fibra.
     */
    double getFibra() const;
    
    /**
     * @brief Consultor del atributo tipo de alimento.
    */
    string getTipo() const;
    
    /**
     *@brief Sobrecarga el operador de extracción de flujo para sacar
     *por la salida estándar un objeto de tipo Ingrediente.
     * @param flujo es el flujo de salida.
     * @param otro el objeto a representar.
     */
    friend ostream& operator<<(ostream& flujo, const ingrediente& otro);
    
    /**
     *@brief Sobrecarga el operador de insercion para rellenar un objeto
     * de la clase Ingrediente.
     * @param flujo es el flujo de datos de entrada.
     * @param otro el objeto a rellenar.
     */
    friend istream& operator>>(istream& flujo, ingrediente& otro);
};

#endif /* ingrediente_h */
