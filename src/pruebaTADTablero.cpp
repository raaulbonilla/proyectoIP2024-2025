


#include "pruebaTADTablero.h"

// PRE: -
// POST: prueba la inicializacion de un tablero vacio
// complejidad: O(filas * columnas)
void pruebasIniciarTableroVacio() {
    Tablero t;
    iniciarTableroVacio(t, 3, 3);

    cout <<"-----Pruebas de iniciarTablero-INICIO-----"<<endl;

    bool error = false;
    int i;
    int j;
    i = 0;
    j = 0;

    while (i < 3 && !error) {
        j = 0;
        while (j < 3 && !error) {
            bool vacia;
            estaVaciaCasillaTablero(t, i, j, vacia);
            if (!vacia) {
                error = true;
                cout << "Error en iniciarTableroVacio: casilla (" << i << "," << j << ") no está vacía" << endl;
            }
            j=j+1;
        }
        i=i+1;
    }

    int filas, columnas;
    obtenerNumFilas(t, filas);
    obtenerNumColumnas(t, columnas);
    if (filas != 3 || columnas != 3) {
        error = true;
        cout << "Error en iniciarTableroVacio: dimensiones incorrectas" << endl;
    }
    cout <<"-Pruebas de iniciarTablero-FINAL"<<endl;
}

// PRE: -
// POST: prueba la inicializacion de un tablero con valores aleatorios
// complejidad: O(filas * columnas)
void pruebasIniciarTableroAleatorio() {
    Tablero t;
    iniciarTableroAleatorio(t, 4, 4, 2, 3);

    bool error = false;
    int i;
    int j;
    i = 0;
    j = 0;

    cout <<"-----Pruebas de iniciarTableroAleatorio-INICIO-----"<<endl;

    while (i < 2 && !error) {
        j = 0;
        while (j < 4 && !error) {
            bool vacia;
            estaVaciaCasillaTablero(t, i, j, vacia);
            if (vacia) {
                error = true;
                cout << "Error en iniciarTableroAleatorio: casilla (" << i << "," << j << ") está vacía" << endl;
            }
            j=j+1;
        }
        i=i+1;
    }

    while (i < 4 && !error) {
        j = 0;
        while (j < 4 && !error) {
            bool vacia;
            estaVaciaCasillaTablero(t, i, j, vacia);
            if (!vacia) {
                error = true;
                cout << "Error en iniciarTableroAleatorio: casilla (" << i << "," << j << ") no está vacía" << endl;
            }
            j=j+1;
        }
        i=i+1;
    }
    cout <<"-Pruebas de iniciarTableroAleatorio-FINAL"<<endl;

}

// PRE: el tablero debe estar inicializado
// POST: prueba la asignacion de un valor a una casilla del tablero
// complejidad: O(1)
void pruebasPonerValorTablero() {
    Tablero t;
    iniciarTableroVacio(t, 3, 3);

    ponerValorTablero(t, 1, 1, 8);

    cout <<"-----Pruebas de ponerValorTAblero-INICIO-----"<<endl;


    int valor;
    obtenerValorTablero(t, 1, 1, valor);
    if (valor != 8) {
        cout << "Error en ponerValorTablero: el valor en (1,1) no es 8" << endl;
    }

    cout <<"-Pruebas de ponerValorTablero-FINAL"<<endl;

}

// PRE: el tablero debe estar inicializado
// POST: prueba la obtencion del valor de una casilla del tablero
// complejidad: O(1)
void pruebasObtenerValorTablero() {
    Tablero t;
    iniciarTableroVacio(t, 3, 3);

    cout <<"-----Pruebas de obternerValorTablero-INICIO-----"<<endl;


    int valor;
    obtenerValorTablero(t, 0, 0, valor);
    if (valor != 0) {
        cout << "Error en obtenerValorTablero: el valor inicial no es 0" << endl;
    }

    cout <<"-Pruebas de obtenerValorTablero-FINAL"<<endl;

}

// PRE: el tablero debe estar inicializado
// POST: prueba si una casilla del tablero esta vacia
// complejidad: O(1)
void pruebasEstaVaciaCasillaTablero() {
    Tablero t;
    iniciarTableroVacio(t, 3, 3);

    cout <<"-----Pruebas de estaVaciaCasillaTablero-INICIO-----"<<endl;


    bool vacia;
    estaVaciaCasillaTablero(t, 0, 0, vacia);
    if (!vacia) {
        cout << "Error en estaVaciaCasillaTablero: casilla (0,0) no está vacía" << endl;
    }

    cout <<"-Pruebas de estaVaciaCasillaTablero-FINAL"<<endl;

}

// PRE: el tablero debe estar inicializado
// POST: prueba la funcionalidad de vaciar una casilla del tablero
// complejidad: O(1)
void pruebasVaciarCasillaTablero() {
    Tablero t;
    iniciarTableroVacio(t, 3, 3);

    ponerValorTablero(t, 1, 1, 8);
    vaciarCasillaTablero(t, 1, 1);

    cout <<"-----Pruebas de vaciarCasillaTablero-INICIO-----"<<endl;


    bool vacia;
    estaVaciaCasillaTablero(t, 1, 1, vacia);
    if (!vacia) {
        cout << "Error en vaciarCasillaTablero: casilla (1,1) no se vació" << endl;
    }

    cout <<"-Pruebas de vaciarCasillaTablero-FINAL"<<endl;

}

// PRE: el tablero debe estar inicializado
// POST: prueba si una columna especifica del tablero esta llena
// complejidad: O(filas)
void pruebasEstaLlenaColumnaTablero() {
    Tablero t;
    iniciarTableroVacio(t, 3, 3);

    cout <<"-----Pruebas de estaLlenoColumnaTablero-INICIO-----"<<endl;


    bool llena;
    estaLlenaColumnaTablero(t, 0, llena);
    if (llena) {
        cout << "Error en estaLlenaColumnaTablero: columna vacía detectada como llena" << endl;
    }

    cout <<"-Pruebas de estaLlenoColumnaTablero-FINAL"<<endl;

}

// PRE: el tablero debe estar inicializado y la columna debe ser valida
// POST: prueba la obtencion de la posicion de la primera casilla vacia en una columna
// complejidad: O(filas)
void pruebasObtenerPosicionVaciaColumnaTablero() {
    Tablero t;
    iniciarTableroVacio(t, 4, 4);

    ponerValorTablero(t, 3, 2, 2);
    int posicion;
    obtenerPosicionVaciaColumnaTablero(t, 2, posicion);

    cout << "------Pruebas de obtenerPosicionVaciaColumnaTablero-INICIO-----"<< endl;
    if (posicion != 0) {
        cout << "Error: primera posición vacía incorrecta, esperado 2, recibido " << posicion<< endl;
    }
    cout << "-Pruebas obtenerPosicionVaciaColumnaTablero-FINAL"<< endl;
}

// PRE: el tablero debe estar inicializado
// POST: prueba si el tablero esta lleno
// complejidad: O(filas * columnas)
void pruebasEstaLlenoTablero() {
    Tablero t;
    iniciarTableroVacio(t, 2, 2);

    bool lleno;
    estaLlenoTablero(t, lleno);

    cout << "------Pruebas de estaLlenoTablero-INICIO------"<< endl;
    if (lleno) {
        cout << "Error: tablero vacío detectado como lleno"<< endl;
    }
    ponerValorTablero(t, 0, 0, 2);
    ponerValorTablero(t, 0, 1, 2);
    ponerValorTablero(t, 1, 0, 2);
    ponerValorTablero(t, 1, 1, 2);
    estaLlenoTablero(t, lleno);
    if (!lleno) {
        cout << "Error: tablero lleno detectado como vacío"<< endl;
    }
    cout << "-Pruebas estaLlenoTablero-FINAL"<< endl;
}

// PRE: el tablero debe estar inicializado
// POST: prueba la obtencion del numero de filas del tablero
// complejidad: O(1)
void pruebasObtenerNumFilas() {
    Tablero t;
    iniciarTableroVacio(t, 4, 5);

    int filas;
    obtenerNumFilas(t, filas);

    cout << "------Pruebas de obtenerNumFilas-INICIO------"<< endl;
    if (filas != 4) {
        cout << "Error: número de filas incorrecto, esperado 4, recibido " << filas<< endl;
    }
    cout << "-Pruebas obtenerNumFilas-FINAL"<< endl;
}

// PRE: el tablero debe estar inicializado
// POST: prueba la obtencion del numero de columnas del tablero
// complejidad: O(1)
void pruebasObtenerNumColumnas() {
    Tablero t;
    iniciarTableroVacio(t, 4, 5);

    int columnas;
    obtenerNumColumnas(t, columnas);

    cout << "------Pruebas de obtenerNumColumnas-INICIO------"<< endl;
    if (columnas != 5) {
        cout << "Error: número de columnas incorrecto, esperado 5, recibido " << columnas<< endl;
    }
    cout << "-Pruebas obtenerNumColumnas-FINAL"<< endl;
}

// PRE: el tablero debe estar inicializado y la casilla indicada debe ser valida
// POST: prueba la fusion de fichas adyacentes con el mismo valor
// complejidad: O(1)
void pruebasFusionarFichas() {
    Tablero t;
    iniciarTableroVacio(t, 4, 4);

    ponerValorTablero(t, 1, 1, 2);
    ponerValorTablero(t, 0, 1, 2);
    int puntuacion = 0;
    fusionarFichas(t, 1, 1, puntuacion);

    cout << "------Pruebas de fusionarFichas-INICIO------"<< endl;
    if (puntuacion != 4) {
        cout << "Error: puntuación incorrecta tras fusión, esperado 4, recibido " << puntuacion<< endl;
    }
    cout << "-Pruebas fusionarFichas-FINAL"<< endl;
}

// PRE: -
// POST: ejecuta todas las pruebas relacionadas con el tad tablero
// complejidad: O(n)
void ejecutarPruebasTablero() {
    cout << "--------<:>Inicio de pruebas TADTablero<:>-------" << endl;

    pruebasIniciarTableroVacio();
    pruebasIniciarTableroAleatorio();
    pruebasPonerValorTablero();
    pruebasObtenerValorTablero();
    pruebasEstaVaciaCasillaTablero();
    pruebasVaciarCasillaTablero();
    pruebasEstaLlenaColumnaTablero();
    pruebasObtenerPosicionVaciaColumnaTablero();
    pruebasEstaLlenoTablero();
    pruebasObtenerNumFilas();
    pruebasObtenerNumColumnas();


    cout << "--------<:>Fin de pruebas TADTablero<:>--------" << endl;
}
