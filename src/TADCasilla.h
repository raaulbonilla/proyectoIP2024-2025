


#ifndef TADCASILLA_H
#define TADCASILLA_H


struct Casilla{
    int valor;
    bool vacia;
};


// PRE: -
// POST: crea una casilla vacía
// Complejidad: O(1)
Casilla crearCasilla();

// PRE: la casilla tiene que estar creada
// POST: asigna un valor a la casilla
// Complejidad: O(1)
void ponerValorCasilla(Casilla &c, int valor);

// PRE: la casilla tiene que estar creada
// POST: devuelve el valor almacenado en la casilla
// Complejidad: O(1)
int obtenerValorCasilla(const Casilla &c);

// PRE: la casilla tiene que estar creada
// POST: devuelve true si la casilla está vacía
// Complejidad: O(1)
bool estaVaciaCasilla(const Casilla &c);

// PRE: la casilla tiene que estar creada
// POST: vacía el contenido de la casilla. VACIAR UNA CASILLA SIGNIFICA ASIGNARLE EL VALOR 0
// Complejidad: O(1)
void vaciarCasilla(Casilla &c);

#endif /* TADCASILLA_H_ */
