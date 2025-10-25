


#include "TADCasilla.h"

// PRE: -
// POST: crea una casilla vacia
// complejidad: O(1)
Casilla crearCasilla(){
    Casilla c;
    c.valor = 0;
    c.vacia = true;
    return c;
}

// PRE: la casilla tiene que estar creada
// POST: asigna un valor a la casilla
// complejidad: O(1)
void ponerValorCasilla(Casilla &c, int valor){
    c.valor = valor;
    c.vacia = false;
}

// PRE: la casilla tiene que estar creada
// POST: devuelve el valor almacenado en la casilla
// complejidad: O(1)
int obtenerValorCasilla(const Casilla &c){
    return c.valor;
}

// PRE: la casilla tiene que estar creada
// POST: devuelve true si la casilla está vacia
// complejidad: O(1)
bool estaVaciaCasilla(const Casilla &c) {
    return obtenerValorCasilla(c) == 0; //vacia si es 0
}


// PRE: la casilla tiene que estar creada
// POST: vacía el contenido de la casilla
// complejidad: O(1)
void vaciarCasilla(Casilla &c){
    c.valor = 0;
    c.vacia = true;
}
