#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tp_3_pilas.h"
#include "utilidades.h"
/*
 3.	Dadas dos pilas, determinar si sus contenidos son exactamente iguales (solo por la clave), sin destruirlas.
	Utilizar para la resolución del problema una única pila auxiliar.
	Determinar la complejidad algorítmica de la solución.
    retorna true si son exactamente iguales, caso contrario retorna false
*/

bool p_ej3_iguales(Pila p1, Pila p2){
    bool resultado = true;
    Pila aux = p_crear();
    TipoElemento elem1, elem2;
    int tamanio1 = p_tamanio(p1);
    int tamanio2 = p_tamanio(p2);
    if (tamanio1 != tamanio2)
        return false;
    for (int i = 0; i < tamanio1; i++){
        elem1 = p_desapilar(p1);
        elem2 = p_desapilar(p2);
        if (elem1->clave != elem2->clave){
            resultado = false;
        }
        p_apilar(aux, elem1);
        p_apilar(aux, elem2);
    }
    for ( int i = 0; i < tamanio1; i++)
    {
        elem2 = p_desapilar(aux);
        elem1 = p_desapilar(aux);
        p_apilar(p1, elem1);
        p_apilar(p2, elem2);
    }
    
    return resultado;
}


int ejercicio3()
{
    limpiarConsola();
    srand(time(NULL));
    printf("\n------ Ejercicio 3 - Son Iguales? ------\n");
    Pila p1 = rellenarPila(-1);
    Pila p2 = rellenarPila(-1);
    printf("\nPila 1: \n");
    p_mostrar(p1);
    printf("\nPila 2: \n");
    p_mostrar(p2);
    printf("\n--> Las pilas son %s\n", p_ej3_iguales(p1, p2) ? "IGUALES" : "DIFERENTES");
    printf(\
        "\nLa complejidad algoritmica de esta funcion es de 0(n). Es decir, complejidad lineal."
        "Esto es asi ya que los dos bucles 'for' recorren una sola vez, de manera secuencial, las 2 pilas. Ya sea para desarmarlas y comparar elementos o para restaurarlas."
        "Pero al no haber una utilizacion de ciclos anidados ni operaciones costosas por elemento, el número total de operaciones crece linealmente con respecto a la cantidad de elementos de las pilas."
        "En resumen, si las pilas tienen 'n' elementos, se realizan aproximadamente '2n' iteraciones (una pasada para comparar y otra para restaurar)."
        "Sin embargo, en notación Big O los factores constantes como el 2 se descartan,por lo que la complejidad sigue siendo O(n).\n"
    );

    int eleccion = leer_entero("\nSalir (0) | Continuar (1): ", 0, 1);
    if (eleccion == 1)
        ejercicio3();
    else if (eleccion == 0)
        return 0;
}
