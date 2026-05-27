#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tp_pilas.h"

Pila p_ej5_invertir(Pila p)
{
    if (p_es_vacia(p)) return p_crear();

    Pila invertida = p_crear();
    Pila aux = p_crear();

    while (!(p_es_vacia(p)))
    {
        TipoElemento X = p_desapilar(p);
        p_apilar(aux, X);
        p_apilar(invertida, X);
    }
    while (!(p_es_vacia(aux)))
    {
        TipoElemento X = p_desapilar(aux);
        p_apilar(p, X);
    }

    free(aux);
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
        "Esto es asi ya que los dos bucles 'while' recorren una sola vez, de manera secuencial, las 2 pilas. " 
        "Como no hay ciclos anidados ni operaciones costosas, el número total de operaciones crece linealmente con respecto a la cantidad de elementos de las pilas."
        "Asi, si las pilas tienen 'n' elementos, se realizan aproximadamente '2n' iteraciones " 
        "Descartando el factor constante '2' se obtiene que la complejidad es O(n).\n"
    );

    int eleccion = pedirEntero("\nSalir (0) | Continuar (1): ", 0, 1);
    if (eleccion == 1)
        ejercicio5();
    else if (eleccion == 0)
        return 0;
}
