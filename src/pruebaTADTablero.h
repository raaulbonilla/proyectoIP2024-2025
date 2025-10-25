


#ifndef PRUEBATADTABLERO_H
#define PRUEBATADTABLERO_H

#include "TADTablero.h"
#include <iostream>
using namespace std;

// PRE: -
// POST: prueba la inicializacion de un tablero vacio
// complejidad: O(filas * columnas)
void pruebasIniciarTableroVacio();

// PRE: -
// POST: prueba la inicializacion de un tablero con valores aleatorios
// complejidad: O(filas * columnas)
void pruebasIniciarTableroAleatorio();

// PRE: el tablero debe estar inicializado
// POST: prueba la asignacion de un valor a una casilla del tablero
// complejidad: O(1)
void pruebasPonerValorTablero();

// PRE: el tablero debe estar inicializado
// POST: prueba la obtencion del valor de una casilla del tablero
// complejidad: O(1)
void pruebasObtenerValorTablero();

// PRE: el tablero debe estar inicializado
// POST: prueba si una casilla del tablero esta vacia
// complejidad: O(1)
void pruebasEstaVaciaCasillaTablero();

// PRE: el tablero debe estar inicializado
// POST: prueba la funcionalidad de vaciar una casilla del tablero
// complejidad: O(1)
void pruebasVaciarCasillaTablero();

// PRE: el tablero debe estar inicializado
// POST: prueba si una columna especifica del tablero esta llena
// complejidad: O(filas)
void pruebasEstaLlenaColumnaTablero();

// PRE: el tablero debe estar inicializado y la columna debe ser valida
// POST: prueba la obtencion de la posicion de la primera casilla vacia en una columna
// complejidad: O(filas)
void pruebasObtenerPosicionVaciaColumnaTablero();

// PRE: el tablero debe estar inicializado
// POST: prueba si el tablero esta lleno
// complejidad: O(filas * columnas)
void pruebasEstaLlenoTablero();

// PRE: el tablero debe estar inicializado
// POST: prueba la obtencion del numero de filas del tablero
// complejidad: O(1)
void pruebasObtenerNumFilas();

// PRE: el tablero debe estar inicializado
// POST: prueba la obtencion del numero de columnas del tablero
// complejidad: O(1)
void pruebasObtenerNumColumnas();

// PRE: el tablero debe estar inicializado y la casilla indicada debe ser valida
// POST: prueba la fusion de fichas adyacentes con el mismo valor
// complejidad: O(1)
void pruebasFusionarFichas();


// PRE: -
// POST: ejecuta todas las pruebas relacionadas con el tad tablero
// complejidad: O(n)
void ejecutarPruebasTablero();


#endif /* PRUEBATADTABLERO_H_ */
