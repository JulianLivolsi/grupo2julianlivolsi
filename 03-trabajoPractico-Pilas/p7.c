#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tp_pilas.h"

Pila p_ej7_elementoscomunes(Pila p1, Pila p2)
{
    Pila aux3 = p_crear();
    Pila aux1 = p_crear();
    Pila aux2 = p_crear();
    while (!p_es_vacia(p1)){
        TipoElemento  element1 = p_desapilar(p1);
        while (!p_es_vacia(p2)){
            TipoElemento  element2 = p_desapilar(p2);
            if (element1->clave == element2->clave) {
                p_apilar(aux3,element1);
            }
            p_apilar(aux2,element2);
        }
        p_apilar(aux1,element1);
        p_intercambiar(p2, aux2);
    }
    p_intercambiar(p1, aux1);
    p_intercambiar(p2, aux2);
    Pila resultado =  p_ej5_invertir(aux3);
    return resultado;
}

int ejercicio7()
{
    limpiarConsola();
    srand(time(NULL));
    printf("\n------ Ejercicio 7 - Elementos en comun ------\n");
    Pila pila1 = rellenarPila(-1), pila2 = rellenarPila(-1);
    printf("\nPila 1: \n--> ");
    p_mostrar(pila1);
    printf("\nPila 2: \n--> ");
    p_mostrar(pila2);
    Pila pilaComun = p_ej7_elementoscomunes(pila1, pila2);
    printf("\nPila elementos en Comun: \n--> ");
    p_mostrar(pilaComun);
    printf(
        "\nLa complejidad algoritmica de esta funcion es de O(n * m). Es decir, complejidad cuadratica." 
        " Esto es asi ya que la funcion tiene dos bucles 'while' anidados: uno para la pila 1 y otro para la pila 2." 
        " El O(n * m) se debe a que por cada elemento de pila 1 (que tiene n elementos), se comparan con todos los elementos de pila 2 (que tiene m elementos)." 
        "Asi, para cada elemento en pila 1, realizas m comparaciones, lo que da como resultado una complejidad de n * m operaciones." 
        " Y es de complejidad cuadrática ya que en el peor de los casos ,cuando ambas pilas son del mismo tamaño, se tiene O(n * n) es decir O(n^2).\n" 
    );

    int eleccion = pedirEntero("\nSalir (0) | Continuar (1): ", 0, 1);
    if (eleccion == 1)
        ejercicio7();
    else if (eleccion == 0)
        return 0;
}
