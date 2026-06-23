#ifndef AUXILIARES_H
#define AUXILIARES_H

#include "../../listas/headers/listas.h"
#include "../../pilas/headers/pilas.h"
#include "../../colas/headers/colas.h"
#include "../../conjuntos/headers/conjuntos.h"

// Macros para el menu
// #define MENU_MIN 0
// #define MENU_MAX 10

//-------------- Validaciones de entreda ------//
int pedirEntero(char mensaje[], int min, int max);
// Valida que la entrada sea un entero, recibe mensaje para el usuario, minimo y maximo del ingreso
float pedirFloat(const char* mensaje, float min, float max);
// Valida que la entrada sea un entero, recibe mensaje para el usuario, minimo y maximo del ingreso
void pedirCadena(char mensaje[], char buffer[], int max_len);
// Valida que la entrada sea una cadena, recibe mensaje para el usuario, destino y longitud maxima

//-------------- Generales --------------------//
int mostrarMenu(const char *titulo, const char *opciones[], int cantidadOpciones);
// Muestra el menu
void limpiarBuffer();
// Limpiador de buffer 
void limpiarConsola();
// Limpiar consola

//-------------- Listas -----------------------//
Lista rellenarLista(int elementos);

//-------------- Pilas -----------------------//
Pila rellenarPila(int elementos);
// Rellena Pila, si elementos = -1, pregunta el largo
Pila pilaClon(Pila p);
// Clona una pila sin perder la original
void p_intercambiar(Pila P, Pila Paux);
// Pasa el contenido de una pila P a otra (modificando el orden de los elementos)
int p_tamanio(Pila P);
// Retorna el tamanio de la pila

//-------------- Colas -----------------------//
Cola rellenarCola(int elementos);
// Rellena Cola, si elementos = -1, pregunta el largo
void c_intercambiar(Cola c, Cola aux);
// Pasa el contenido de una cola C a otra
int c_contarElementos(Cola c);
// Cuenta la cantidad de elementos de una cola
Cola colaClon(Cola c);
// Clona una cola sin perder la original

//-------------- Conjuntos -----------------------//
Conjunto rellenarConjunto(int elementos);

Lista cargarColeccionConjuntos(int N);

bool es_subconjunto(Conjunto X, Conjunto Y);

#endif // AUXILIARES_H
