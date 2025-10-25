


#include "TADCasilla.h"
#include "pruebaTADCasilla.h"
#include <iostream>

using namespace std;

// PRE: -
// POST: prueba la creacion de una casilla vacia
// complejidad: O(1)
void pruebasCrearCasilla(){
    cout << "-----Pruebas de crearCasilla-INICIO-----" << endl;

    Casilla c1 = crearCasilla();
    if (!estaVaciaCasilla(c1)){
    	cout << "Error en crearCasilla: caso 1" << endl;
    }

    if (obtenerValorCasilla(c1) != 0){
    	cout << "Error en crearCasilla: caso 2" << endl;
    }

    Casilla c2 = crearCasilla();
    ponerValorCasilla(c2, 5);
    if (estaVaciaCasilla(c2) || obtenerValorCasilla(c2) != 5){
        cout << "Error en crearCasilla: caso 3" << endl;
    }

    cout << "-Pruebas de crearCasilla-FINAL" << endl;
}

// PRE: la casilla debe estar creada
// POST: prueba la asignacion de un valor a una casilla
// complejidad: O(1)
void pruebasPonerValorCasilla(){
    cout << "-----Pruebas de ponerValorCasilla-INICIO-----" << endl;

    Casilla c = crearCasilla();
    ponerValorCasilla(c, 8);
    if (obtenerValorCasilla(c) != 8){
    	cout << "Error en ponerValorCasilla: caso 1" << endl;
    }

    ponerValorCasilla(c, 12);
    if (obtenerValorCasilla(c) != 12){
    	cout << "Error en ponerValorCasilla: caso 2" << endl;
    }

    ponerValorCasilla(c, 0);
    if (obtenerValorCasilla(c) != 0){
    	cout << "Error en ponerValorCasilla: caso 3" << endl;
    }

    cout << "-Pruebas de ponerValorCasilla-FINAL" << endl;
}

// PRE: la casilla debe estar creada
// POST: prueba la obtencion del valor almacenado en una casilla
// complejidad: O(1)
void pruebasObtenerValorCasilla(){
    cout << "-----Pruebas de obtenerValorCasilla-INICIO-----" << endl;

    Casilla c = crearCasilla();
    if (obtenerValorCasilla(c) != 0){
    	cout << "Error en obtenerValorCasilla: caso 1" << endl;
    }

    ponerValorCasilla(c, 7);
    if (obtenerValorCasilla(c) != 7){
    	cout << "Error en obtenerValorCasilla: caso 2" << endl;
    }

    vaciarCasilla(c);
    if (obtenerValorCasilla(c) != 0){
    	cout << "Error en obtenerValorCasilla: caso 3" << endl;
    }

    cout << "-Pruebas de obtenerValorCasilla-FINAL" << endl;
}

// PRE: la casilla debe estar creada
// POST: prueba si una casilla esta vacia correctamente
// complejidad: O(1)
void pruebasEstaVaciaCasilla(){
    cout << "-----Pruebas de estaVaciaCasilla-INICIO-----" << endl;

    Casilla c = crearCasilla();
    if (!estaVaciaCasilla(c)){
    	cout << "Error en estaVaciaCasilla: caso 1" << endl;
    }

    ponerValorCasilla(c, 3);
    if (estaVaciaCasilla(c)){
    	cout << "Error en estaVaciaCasilla: caso 2" << endl;
    }

    vaciarCasilla(c);
    if (!estaVaciaCasilla(c)){
    	cout << "Error en estaVaciaCasilla: caso 3" << endl;
    }


    cout << "-Pruebas de estaVaciaCasilla-FINAL" << endl;
}

// PRE: la casilla debe estar creada
// POST: prueba la funcionalidad de vaciar el contenido de una casilla
// complejidad: O(1)
void pruebasVaciarCasilla(){
    cout << "-----Pruebas de vaciarCasilla-INICIO-----" << endl;

    Casilla c = crearCasilla();
    ponerValorCasilla(c, 7);
    vaciarCasilla(c);
    if (!estaVaciaCasilla(c) || obtenerValorCasilla(c) != 0){
        cout << "Error en prueba 1: No se vació correctamente la casilla" << endl;
    }

    vaciarCasilla(c);
    if (!estaVaciaCasilla(c) || obtenerValorCasilla(c) != 0){
        cout << "Error en prueba 2: Vaciar una casilla vacía no debería afectar" << endl;
    }

    ponerValorCasilla(c, 12);
    vaciarCasilla(c);
    if (!estaVaciaCasilla(c) || obtenerValorCasilla(c) != 0){
        cout << "Error en prueba 3: No se vació correctamente tras sobrescribir" << endl;
    }

    cout << "-Pruebas de vaciarCasilla-FINAL" << endl;
}

// PRE: -
// POST: ejecuta todas las pruebas relacionadas con el tad casilla
// complejidad: O(n)
void ejecutarPruebasCasilla(){
    cout << "--------<:>Inicio de pruebas TADCasilla<:>--------" << endl;
    pruebasCrearCasilla();
    pruebasPonerValorCasilla();
    pruebasObtenerValorCasilla();
    pruebasEstaVaciaCasilla();
    pruebasVaciarCasilla();
    cout << "--------<:>Fin de pruebas TADCasilla<:>--------" << endl;
}
