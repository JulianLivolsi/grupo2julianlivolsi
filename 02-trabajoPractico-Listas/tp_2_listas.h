#include <stdbool.h>
#include "../libs/listas/headers/listas.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/validaciones/headers/AUXILIARES.h"

#ifndef TP_2_Listas
#define TP_2_Listas

// ---- Tipos auxiliares ----

typedef struct resultadoStruct
{
    int pos;
    int valor;
    int pos_2;
    int valor_2;
} ResultadoValorMinimo;

typedef struct resultadoPromedio
{
    float prom1;
    float prom2;
} ResultadoPromedioAmbasListas;

// ---- Ejercicio 2 ----

// a: elementos de L1 que no estan en L2
Lista verElementosQueNoSeRepitenA(Lista l1, Lista l2);
// b: elementos de L2 que no estan en L1
Lista verElementosQueNoSeRepitenB(Lista l1, Lista l2);
// c: elementos comunes a ambas listas
Lista verElementosRepetidos(Lista l1, Lista l2);
// d: promedio de cada lista
float promedio(Lista l1);
ResultadoPromedioAmbasListas promedioAmbasListas(Lista l1, Lista l2);
// e: valor minimo de cada lista y su posicion
ResultadoValorMinimo valorMinimo(Lista l1, Lista l2);

// ---- Ejercicio 3 ----

typedef struct
{
    bool esMultiplo;
    bool escalar;
    int numEscalar;
} ResultadosMul;

ResultadosMul multiplo(Lista l1, Lista l2);

// ---- Ejercicio 4 ----
// Retorna 1 si L1 > L2, 2 si L2 > L1, 0 si son iguales
int CompararListas(Lista l1, Lista l2);

// ---- Ejercicio 5 ----

// Carga los coeficientes del polinomio en la lista (mayor grado primero)
void hacerPolinomio(Lista list);
// Evalua el polinomio en el valor x
float evaluarPolinomio(Lista list, float x);
// Calcula el polinomio en un rango de valores de x con paso sumando
Lista calcularRango(Lista list, double x, double y, double sumando);

// ---- Ejercicio 6 ----
// Retorna true si L2 es sublista de L1 (todos los elementos de L2 estan en L1)
bool esSublista(Lista l1, Lista l2);

#endif // TP_2_Listas