


#include "TADJuego.h"
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

// PRE: numFilas > 0, numColumnas > 0
// POST: inicializa el juego con el número de filas y columnas especificado, y el estado inicial definido por comoIniciar y filasIniciales. Si comoIniciar indica un estado inicial definido por m, lo utiliza.
// complejidad: O(filas * columnas)
void iniciarJuego(Juego &juego, int numFilas, int numColumnas, int comoIniciar, int filasIniciales, int m[MAX_FILAS][MAX_COLUMNAS]) {
    juego.numFilas = numFilas;
    juego.numColumnas = numColumnas;
    juego.columnaLanzador = 0;
    juego.valorLanzador = pow(2, (1 + rand() % 8));
    juego.puntuacion = 0;
    juego.salir = false;
    juego.mensaje = "";


//inicia el juego dependiendo de la configuracion
    if (comoIniciar == 0) {
//inicia un tablero vacio y carga los valores desde m
        iniciarTableroVacio(juego.tablero, numFilas, numColumnas);

        int fila = 0;

        while (fila < filasIniciales) {

            int columna = 0;
            while (columna < numColumnas) {
                ponerValorTablero(juego.tablero, fila, columna, m[fila][columna]);
                columna = columna + 1;
            }
            fila = fila + 1;
        }
    }
        else {
//inicia el tablero de juego con valores aleatorios
        	iniciarTableroAleatorio(juego.tablero, numFilas, numColumnas, filasIniciales, comoIniciar);
    }

//inicia el entorno visual
    entornoIniciar(numFilas, numColumnas);

//para mostrar los valores iniciales del entorno
    int fila = 0;

    while (fila < numFilas) {

        int columna = 0;
        while (columna < numColumnas) {
            int valorCasilla;
            obtenerValorTablero(juego.tablero, fila, columna, valorCasilla);

            if (valorCasilla != 0) {
                entornoPonerNumero(fila, columna, valorCasilla);
            }
            else {
                entornoEliminarNumero(fila, columna);
            }
            columna = columna + 1;
        }
        fila = fila + 1;
    }

//activar visualmente el lanzador y el contador de puntuacion
    entornoPonerNumeroLanzador(juego.valorLanzador, juego.columnaLanzador);
    entornoPonerPuntuacion(juego.puntuacion);
}

// PRE: tecla es una tecla valida
// POST: procesa la tecla introducida, actualiza el estado del juego, mueve la ficha en el lanzador y, si es necesario, actualiza el tablero
// complejidad: O(1)
void procesarTecla(Juego &juego, TipoTecla tecla) {
    switch (tecla) {

    case TEnter:
        int filaVacia;
        obtenerPosicionVaciaColumnaTablero(juego.tablero, juego.columnaLanzador, filaVacia);
        if (filaVacia != -1) { //si encuentra una posicion vacia

//coloca el valor lanzador en la posicion vacia de la columna correspondiente del tablero
            ponerValorTablero(juego.tablero, filaVacia, juego.columnaLanzador, juego.valorLanzador);

//actualiza la interfaz grafica para mostrar el numero en la posicion indicada
            entornoPonerNumero(filaVacia, juego.columnaLanzador, juego.valorLanzador);

//fusiona las fichas y actualiza la puntuacion
            fusionarFichas(juego.tablero, filaVacia, juego.columnaLanzador, juego.puntuacion);

//elimina del lanzador el numero que se coloco en el tablero
            entornoQuitarNumeroLanzador(juego.columnaLanzador);

//crea un nuevo numero al azar y lo coloca visualmente en el lanzador
            juego.valorLanzador = pow(2, (1 + rand() % 8));
            entornoPonerNumeroLanzador(juego.valorLanzador, juego.columnaLanzador);

//actualiza visualmente la puntuacion
            entornoPonerPuntuacion(juego.puntuacion);
        }
        else {
            cout << "La columna está llena" << endl;
        }
        break;

    case TF1:
    break;

    case TF2:
    break;

    case TDerecha:
//quitar la ficha de la posicion anterior del lanzador
        entornoQuitarNumeroLanzador(juego.columnaLanzador);

//mueve la ficha en el lanzador hacia la derecha
        juego.columnaLanzador = (juego.columnaLanzador + 1) % juego.numColumnas;

//pone la ficha en la nueva posicion del lanzador
        entornoPonerNumeroLanzador(juego.valorLanzador, juego.columnaLanzador);
        break;

        case TIzquierda:
//quitar la ficha de la posicion anterior del lanzador
            entornoQuitarNumeroLanzador(juego.columnaLanzador);

//mueve la ficha en el lanzador hacia la izquierda
            juego.columnaLanzador = (juego.columnaLanzador - 1 + juego.numColumnas) % juego.numColumnas;

//pone la ficha en la nueva posicion del lanzador
            entornoPonerNumeroLanzador(juego.valorLanzador, juego.columnaLanzador);
            break;

        case TSalir:
            juego.mensaje = "Has abandonado";
            juego.salir = true;
            break;

        case TNada:
            break;
    }
}

// PRE: el estado del juego es valido
// POST: devuelve true si el juego ha terminado, lo que sucede si el tablero está lleno o si el jugador decide salir del juego
// complejidad: O(filas * columnas)
bool juegoTerminado(const Juego &juego) {
    return juego.salir;
}

