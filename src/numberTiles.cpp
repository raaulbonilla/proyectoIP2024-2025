//============================================================================
// Name        : numberTiles.cpp
// Author      : Raúl Bonilla Cáceres
// Description : Programa principal del proyecto Number Tiles
//============================================================================

// En el proyecto no está implementada ninguna de las ampliaciones

#include "TADJuego.h"
#include "pruebaTADCasilla.h"
#include "pruebaTADTablero.h"

int main() {
    // PARA EJECUTAR LAS PRUEBAS HAY QUE QUITAR LOS COMENTARIOS EN LAS SIGUIENTES LÍNEAS CORRESPONDIENTES
    // A LOS MODULOS DE LAS PRUEBAS Y COMENTAR LA EJECUCIÓN DEL PROYECTO EN SÍ


/*
     ejecutarPruebasCasilla();
     ejecutarPruebasTablero();

}
*/

    Juego juego;
    int numFilas, numColumnas, comoIniciar, filasIniciales;
    int m[MAX_FILAS][MAX_COLUMNAS];

//para leer la config desde el archivo del proyecto
    if (entornoCargarConfiguracion(numFilas, numColumnas, comoIniciar, filasIniciales, m)) {
        iniciarJuego(juego, numFilas, numColumnas, comoIniciar, filasIniciales, m);

        while (!juegoTerminado(juego)) {
            procesarTecla(juego, entornoLeerTecla());
        }

        entornoMostrarMensajeFin(juego.mensaje);
    } else {
        entornoMostrarMensajeFin("Error al cargar la configuración");
    }

    entornoTerminar();
    return 0;
}



