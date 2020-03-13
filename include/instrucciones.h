#ifndef instrucciones_h
#define instrucciones_h

#include <fstream>
#include "arbolbinario.h"
#include "acciones.h"
#include "ingredientes.h"
#include "instrucciones.h"

class instrucciones {
	
	ArbolBinario<string> datos;
	static acciones & acc;

public:

     /**
      * @brief Constructor por defecto.
      * 
      */
	instrucciones() = default;

     /**
      * @brief Carga las instrucciones desde un fichero 
      * necesita conocer los ingredientes.
      * 
      * @param nf nombre del fichero donde se encuentran (ruta completa).
      * @param ing conjunto de ingredientes disponibles.
      */
     void cargarInstrucciones(std::string nf, ingredientes & ing);

     /**
      * @brief Get the Abb object
      * 
      * @return ArbolBinario<string> 
      */
     ArbolBinario<string> getAbb() const;

     /**
      * @brief Set the Abb object
      * 
      * @param ab ArbolBinario<string>
      */
     void setAbb(const ArbolBinario<string>& ab);

     /**
      * @brief Fusiona las instrucciones de dos recetas
      * para obtener la elaboración completa de la receta fusión.
      * 
      * @param otro instrucciones de la otra receta
      * @return instrucciones fusionadas.
      */
     instrucciones fusionarInstrucciones(const instrucciones & otro);

	/**
     * @brief Sobrecarga el operador de extracción de flujo para sacar
     * por la sida estándar un objeto de tipo acciones.
     * @param flujo es el flujo de salida.
     * @param otro el objeto a representar.
     */
	friend ostream & operator<<(ostream & f, const instrucciones & ins);

    /**
     * @brief Sobrecarga el operador de insercion para rellenar un objeto
     * de la clase acciones.
     * @param flujo es el flujo de datos de entrada.
     * @param otro el objeto a rellenar.
     * hacer un clear que vacíe los vectores
     */
	friend istream & operator>>(istream & f, instrucciones & ins);

};

#endif /* instrucciones_h */