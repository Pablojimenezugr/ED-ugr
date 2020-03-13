#ifndef acciones_h
#define acciones_h

#include <map>
#include <iostream>
using namespace std;

class acciones {
	
	map<string, unsigned> datos;

public:
	acciones() = default;

    bool isAccion(string acc);

    int ariedad(string acc);

	class iterator {
        map<string, unsigned>::iterator it;
    public:
        iterator() = default;
        bool operator==(const iterator & i) const { return it == i.it; }
        bool operator!=(const iterator & i) const { return it != i.it; }
        const  pair<string, unsigned> operator*() { return *it; }
        iterator & operator++() { ++it; return *this; }
        iterator & operator--() { --it; return *this; }

        friend class acciones;
    };

    class const_iterator {
        map<string, unsigned>::const_iterator it;
    public:
        const_iterator() = default;
        bool operator==(const const_iterator & i) const { return it == i.it; }
        bool operator!=(const const_iterator & i) const { return it != i.it; }
        const pair<string, unsigned> operator*() const { return *it; }
        const_iterator & operator++() { ++it; return *this; }
        const_iterator & operator--() { --it; return *this; }

        friend class acciones;
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
     * por la sida estándar un objeto de tipo acciones.
     * @param flujo es el flujo de salida.
     * @param otro el objeto a representar.
     */
	friend ostream & operator<<(ostream & f, const acciones & acc);

    /**
     * @brief Sobrecarga el operador de insercion para rellenar un objeto
     * de la clase acciones.
     * @param flujo es el flujo de datos de entrada.
     * @param otro el objeto a rellenar.
     * hacer un clear que vacíe los vectores
     */
	friend istream & operator>>(istream & f, acciones & acc);
};

#endif /* acciones_h */