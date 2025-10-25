


#include "TADTablero.h"
#include <cstdlib>
#include <cmath>

// PRE: filas>0, columnas>0, filas<=MAX_FILAS, columnas<=MAX_COLUMNAS
// POST: inicializa un tablero con todas las casillas vacias
// complejidad: O(filas*columnas)
void iniciarTableroVacio(Tablero &t, int filas, int columnas){
    t.numFilas = filas;
    t.numColumnas = columnas;
    int i;
    int j;
    i = 0;
    j = 0;

    while (i < filas){
        j = 0;
        while (j < columnas){
            t.casillas[i][j] = crearCasilla();
            j=j+1;
        }
        i=i+1;
    }
}

// PRE: filas>0, columnas>0, filas<=MAX_FILAS, columnas<=MAX_COLUMNAS
// POST: inicializa un tablero con valores aleatorios siendo potencias de dos en las primeras filas
// complejidad: O(filas*columnas)
void iniciarTableroAleatorio(Tablero &t, int filas, int columnas, int filasIniciales, int maximo){
    iniciarTableroVacio(t, filas, columnas);
    int i;
    int j;
    int valor;
    i = 0;
    j = 0;
    valor = 0;

    while (i < filasIniciales){
        j = 0;
        while (j < columnas){
            valor = pow(2, rand() % maximo + 1);
            ponerValorCasilla(t.casillas[i][j], valor);
            j=j+1;
        }
        i=i+1;
    }
}

// PRE: fila y columna están dentro del rango del tablero
// POST: coloca el valor en la casilla especificada
// complejidad: O(1)
void ponerValorTablero(Tablero &t, int fila, int columna, int valor){
    ponerValorCasilla(t.casillas[fila][columna], valor);
}

// PRE: fila y columna están dentro del rango del tablero
// POST: devuelve el valor de la casilla especificada en el parámetro resultado
// complejidad: O(1)
void obtenerValorTablero(const Tablero &t, int fila, int columna, int &resultado){
    resultado = obtenerValorCasilla(t.casillas[fila][columna]);
}

// PRE: fila y columna están dentro del rango del tablero
// POST: devuelve true en resultado si la casilla está vacía,false en caso contrario
// complejidad: O(1)
void estaVaciaCasillaTablero(const Tablero &t, int fila, int columna, bool &resultado){
    resultado = estaVaciaCasilla(t.casillas[fila][columna]);
}

// PRE: fila y columna están dentro del rango del tablero
// POST: vacía la casilla especificada
// complejidad: O(1)
void vaciarCasillaTablero(Tablero &t, int fila, int columna){
    vaciarCasilla(t.casillas[fila][columna]);
}

// PRE: columna está dentro del rango del tablero
// POST: devuelve true en resultado si la columna está llena,false en caso contrario
// complejidad: O(filas)
void estaLlenaColumnaTablero(const Tablero &t, int columna, bool &resultado){
    resultado = true;
    int i;
    i = 0;

    while (i < t.numFilas && resultado){
        if (estaVaciaCasilla(t.casillas[i][columna])){
            resultado = false;
        }
        i=i+1;
    }
}

// PRE: columna está dentro del rango del tablero
// POST: devuelve la primera fila vacía de la columna en el parámetro resultado
// si no hay posición vacía,resultado=-1
// complejidad: O(filas)
void obtenerPosicionVaciaColumnaTablero(const Tablero &t, int columna, int &resultado){
    resultado = -1;
    int i;
    i = 0;

    while (i<t.numFilas){

    	bool estaVacia;
    	estaVaciaCasillaTablero(t, i, columna, estaVacia);

        if (estaVacia){
            resultado = i;
            break;
        }
        i=i+1;
    }
}

// PRE: -
// POST: devuelve true en resultado si el tablero está lleno,false en caso contrario
// complejidad: O(filas*columnas)
void estaLlenoTablero(const Tablero &t, bool &resultado){
    resultado = true;
    int i;
    int j;
    i = 0;
    j = 0;

    while (i < t.numFilas && resultado){
        j = 0;
        while (j < t.numColumnas && resultado) {
            if (estaVaciaCasilla(t.casillas[i][j])){
                resultado = false;
            }
            j=j+1;
        }
        i=i+1;
    }
}

// PRE: -
// POST: devuelve el número de filas del tablero en el parámetro resultado
// complejidad: O(1)
void obtenerNumFilas(const Tablero &t, int &resultado){
    resultado = t.numFilas;
}

// PRE: -
// POST: devuelve el número de columnas del tablero en el parámetro resultado
// complejidad: O(1)
void obtenerNumColumnas(const Tablero &t, int &resultado){
    resultado = t.numColumnas;
}

//FUNCION PARA FUSIONAR LAS FICHAS EN EL TABLERO

// PRE: la posicion (fila, columna) esta dentro de los limites del tablero
// POST: fusioina las fichas adyacentes con el mismo valor que la ficha en (fila, columna).
//       Actualiza el tablero después de la fusión.
// complejidad: O(1)
void fusionarFichas(Tablero &t, int fila, int columna, int &puntuacion) {
    int valor;
    obtenerValorTablero(t, fila, columna, valor);

    // revisar arriba
    if (fila > 0) {
        int valorArriba;
        obtenerValorTablero(t, fila - 1, columna, valorArriba);
        if (valor == valorArriba) {
            int nuevoValor = valor * 2;
            ponerValorTablero(t, fila - 1, columna, nuevoValor);	// sumar los valores en una única ficha arriba
            entornoPonerNumero(fila - 1, columna, nuevoValor);		// actualizar visualmente en el entorno
            vaciarCasillaTablero(t, fila, columna);					// vaciar la casilla actual en el tablero
            entornoEliminarNumero(fila, columna);					// actualizar visualmente en el entorno
            puntuacion = puntuacion + nuevoValor;					// actualizar puntuación
        }
    }

    // revisar izquierda
    if (columna > 0) {
        int valorIzquierda;
        obtenerValorTablero(t, fila, columna - 1, valorIzquierda);
        if (valor == valorIzquierda) {
            int nuevoValor = valor * 2;
            ponerValorTablero(t, fila, columna - 1, nuevoValor);
            entornoPonerNumero(fila, columna - 1, nuevoValor);
            vaciarCasillaTablero(t, fila, columna);
            entornoEliminarNumero(fila, columna);
            puntuacion = puntuacion + nuevoValor;
        }
    }

    // revisar derecha
    if (columna < t.numColumnas - 1) {
        int valorDerecha;
        obtenerValorTablero(t, fila, columna + 1, valorDerecha);
        if (valor == valorDerecha) {
            int nuevoValor = valor * 2;
            ponerValorTablero(t, fila, columna + 1, nuevoValor);
            entornoPonerNumero(fila, columna + 1, nuevoValor);
            vaciarCasillaTablero(t, fila, columna);
            entornoEliminarNumero(fila, columna);
            puntuacion = puntuacion + nuevoValor;
        }
    }
}
