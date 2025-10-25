


#ifndef TADTABLERO_H
#define TADTABLERO_H
#include "TADCasilla.h"
#include "entorno.h"



struct Tablero{
    Casilla casillas[MAX_FILAS][MAX_COLUMNAS];
    int numFilas;
    int numColumnas;
};


// PRE: filas > 0, columnas > 0, filas <= MAX_FILAS, columnas <= MAX_COLUMNAS
// POST: inicializa un tablero con todas las casillas vacías
// complejidad: O(filas * columnas)
void iniciarTableroVacio(Tablero &t, int filas, int columnas);

// PRE: filas > 0, columnas > 0, filas <= MAX_FILAS, columnas <= MAX_COLUMNAS
// POST: inicializa un tablero con valores aleatorios siendo potencias de dos en las primeras filas
// compejidad: O(filas * columnas)
void iniciarTableroAleatorio(Tablero &t, int filas, int columnas, int filasIniciales, int maximo);

// PRE: fila y columna están dentro del rango del tablero
// POST: coloca el valor en la casilla especificada
// complejidad: O(1)
void ponerValorTablero(Tablero &t, int fila, int columna, int valor);

// PRE: fila y columna están dentro del rango del tablero
// POST: devuelve el valor de la casilla especificada en el parámetro resultado
// complejidad: O(1)
void obtenerValorTablero(const Tablero &t, int fila, int columna, int &resultado);

// PRE: fila y columna están dentro del rango del tablero
// POST: devuelve true en resultado si la casilla está vacía, false en caso contrario
// complejidad: O(1)
void estaVaciaCasillaTablero(const Tablero &t, int fila, int columna, bool &resultado);

// PRE: fila y columna están dentro del rango del tablero
// POST: vacía la casilla especificada
// cmplejidad: O(1)
void vaciarCasillaTablero(Tablero &t, int fila, int columna);

// PRE: columna está dentro del rango del tablero
// POST: devuelve true en resultado si la columna está llena, false en caso contrario
// complejidad: O(filas)
void estaLlenaColumnaTablero(const Tablero &t, int columna, bool &resultado);

// PRE: columna está dentro del rango del tablero
// POST: devuelve la primera fila vacía de la columna en el parámetro resultado
// si no hay posición vacía, resultado = -1
// complejidad: O(filas)
void obtenerPosicionVaciaColumnaTablero(const Tablero &t, int columna, int &resultado);

// PRE: -
// POST: devuelve true en resultado si el tablero está lleno, false en caso contrario
// complejidad: O(filas * columnas)
void estaLlenoTablero(const Tablero &t, bool &resultado);

// PRE: -
// POST: devuelve el número de filas del tablero en el parámetro resultado
// complejidad: O(1)
void obtenerNumFilas(const Tablero &t, int &resultado);

// PRE: -
// POST: devuelve el número de columnas del tablero en el parámetro resultado
// complejidad: O(1)
void obtenerNumColumnas(const Tablero &t, int &resultado);

// PRE: la posicion (fila, columna) esta dentro de los limites del tablero
// POST: fusioina las fichas adyacentes con el mismo valor que la ficha en (fila, columna).
//       Actualiza el tablero después de la fusión.
// complejidad: O(1)
void fusionarFichas(Tablero &t, int fila, int columna, int &puntuacion);

#endif /* TADTABLERO_H_ */
