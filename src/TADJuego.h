


#ifndef TAD_JUEGO_H
#define TAD_JUEGO_H

#include "TADTablero.h"
#include "entorno.h"

struct Juego {
    Tablero tablero;
    int numFilas;
    int comoIniciar;
    int numColumnas;
    int columnaLanzador;
    int valorLanzador;
    int puntuacion;
    bool salir;
    std::string mensaje;
};

// PRE: numFilas > 0, numColumnas > 0
// POST: inicializa el juego
// complejidad: O(filas * columnas)
void iniciarJuego(Juego &juego, int numFilas, int numColumnas, int comoIniciar, int filasIniciales, int m[MAX_FILAS][MAX_COLUMNAS]);

// PRE: tecla es una tecla valida
// POST: procesa la tecla y actualiza el juego
// complejidad: O(1) en el procesamiento de la tecla, más el costo de actualizar el tablero (dependiente de la acción)
void procesarTecla(Juego &juego, TipoTecla tecla);

// PRE: el estado del juego es valido
// POST: devuelve true si el juego ha terminado
// complejidad: O(filas * columnas)
bool juegoTerminado(const Juego &juego);

#endif /* TAD_JUEGO_H */

