#include "../../listas/headers/listas.h"

#ifndef AUXILIARES_H
#define AUXILIARES_H

// Macros para el menu
#define MENU_MIN 0
#define MENU_MAX 10

// Prototipos

// Valida que la entrada sea un entero, recibe mensaje para el usuario, minimo y maximo del ingreso
int pedirEntero(char mensaje[], int min, int max);

// Valida que la entrada sea un entero, recibe mensaje para el usuario, minimo y maximo del ingreso
int pedirFloat(const char* mensaje, float min, float max);

// Muestra el menu
int mostrarMenu(const char *titulo, const char *opciones[], int cantidadOpciones);

// Limpiador de buffer
void limpiarBuffer();

// Valida que la entrada sea una cadena, recibe mensaje para el usuario, destino y longitud maxima
void pedirCadena(char mensaje[], char buffer[], int max_len);
 
void limpiarConsola();

// LISTAS

Lista rellenarLista(int elementos);

#endif // AUXILIARES_H