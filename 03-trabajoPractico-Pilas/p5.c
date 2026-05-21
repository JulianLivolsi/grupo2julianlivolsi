#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tp_pilas.h"

Pila p_ej5_invertir(Pila p)
{
    Pila invertida = p_crear();
    Pila aux = p_crear();
    TipoElemento X = te_crear(0);
    while (!(p_es_vacia(p)))
    {
        X = p_desapilar(p);
        p_apilar(aux, X);
        p_apilar(invertida, X);
    }
    while (!(p_es_vacia(aux)))
    {
        X = p_desapilar(aux);
        p_apilar(p, X);
    }

    return invertida;
}

int ejercicio5()
{
    limpiarConsola();
    srand(time(NULL));
    printf("\n------ Ejercicio 5 - Invertir Pila ------\n");
    Pila pila = rellenarPila(-1);
    printf("\nPila original: ");
    p_mostrar(pila);
    printf("\nPila invertida: ");
    Pila invertida = p_ej5_invertir(pila);
    p_mostrar(invertida);
    printf("\nPila original: ");
    p_mostrar(pila);
    printf(
        "\nLa complejidad algoritmica de esta funcion es de 0(n). Es decir, complejidad lineal."
        "Esto es asi ya que los dos bucles 'while' recorren una sola vez, de manera secuencial, las 2 pilas. Ya sea para crear la pila invertida o para restaurar la pila original." 
        "Pero al no haber una utilizacion de ciclos anidados ni operaciones costosas por elemento, el número total de operaciones crece linealmente con respecto a la cantidad de elementos de las pilas."
        "En resumen, si las pilas tienen 'n' elementos, se realizan aproximadamente '2n' iteraciones (una pasada para crear la pila invertida y otra para restaurar la original)." 
        "Sin embargo, en notación Big O los factores constantes como el 2 se descartan,por lo que la complejidad sigue siendo O(n).\n"
    );

    int eleccion = pedirEntero("\nSalir (0) | Continuar (1): ", 0, 1);
    if (eleccion == 1)
        ejercicio5();
    else if (eleccion == 0)
        return 0;
}
