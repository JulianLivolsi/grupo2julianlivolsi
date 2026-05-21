#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tp_pilas.h"

Pila p_ej6_eliminarclave(Pila p, int clave)
{
    Pila aux = p_crear();
    Pila resultado = p_crear();
    while (!p_es_vacia(p))
    {
        TipoElemento elem = p_desapilar(p);
        p_apilar(aux, elem);
    }
    while (!p_es_vacia(aux))
    {
        TipoElemento elem = p_desapilar(aux);
        p_apilar(p, elem);
        if (elem->clave != clave)
        {
            p_apilar(resultado, elem);
        }
    }
    return resultado;
}

// Para el caso recursivo del ejercicio 6
Pila p_ej6_eliminarclave_r(Pila p, int clave)
{
    if (p_es_vacia(p))
        return p_crear();
    TipoElemento elem = p_desapilar(p);
    Pila resultado = p_ej6_eliminarclave_r(p, clave);
    if (elem->clave != clave)
        p_apilar(resultado, elem);
    p_apilar(p, elem);
    return resultado;
}

int ejercicio6()
{
    limpiarConsola();
    srand(time(NULL));
    printf("\n------ Ejercicio 6 - Eliminar un Valor ------\n");
    Pila pila = rellenarPila(-1);
    printf("--> ");
    p_mostrar(pila);
    int elemEliminar = pedirEntero("Ingrese el elemento a eliminar: ", -100, 100);
    int tipo = pedirEntero("\nIterativa (0) | Recursiva (1): ", 0, 1);
    
    Pila resultado;
    if (tipo == 0)
    {
        printf("\n -- Iterativa --\n");
        resultado = p_ej6_eliminarclave(pila, elemEliminar);
        printf("\nPila sin el elemento %i: \n", elemEliminar);
        p_mostrar(resultado);
        printf("\nPila original sin modificar: \n");
        p_mostrar(pila);
        printf(
            "\nLa complejidad algorítmica de esta funcion es de O(n). Es decir, complejidad lineal.\n"
            "Esto es asi ya que los dos bucles 'while' recorren una sola vez, de manera secuencial, las 2 pilas, "
            "ya sea para armar una pila auxiliar con los elementos de la pila original o para restaurar la pila original "
            "y armar una pila con los elementos de la pila original sin el elemento 'clave'.\n"
            "Pero al no haber una utilizacion de ciclos anidados ni operaciones costosas por elemento, el numero total de operaciones "
            "crece linealmente con respecto a la cantidad de elementos de las pilas.\n"
            "En resumen, si las pilas tienen 'n' elementos, se realizan aproximadamente '2n' iteraciones (una pasada para armar el auxiliar "
            "y otra para restaurar la pila original y armar el duplicado sin la 'clave').\n"
            "Sin embargo, en notacion Big O los factores constantes como el 2 se descartan, "
            "por lo que la complejidad sigue siendo O(n).\n"
        );
        
    }
    else
    {
        printf("\n -- Recursiva --\n");
        resultado = p_ej6_eliminarclave_r(pila, elemEliminar);
        printf("\nPila sin el elemento %i: \n", elemEliminar);
        p_mostrar(resultado);
        printf("\nPila original sin modificar: \n");
        p_mostrar(pila);
        printf(
            "\nLa complejidad algoritmica de esta funcion es de O(n). Es decir, complejidad lineal.\n"
            "\nEsto es asi ya que en cada llamada recursiva se desapila un elemento de la pila original (que puede tener 'n' elementos), "
            "y luego de la llamada recursiva se apila el elemento en una nueva pila bajo determinadas condiciones y se restaura la pila original.\n"
            "\nEl numero total de llamadas recursivas, en este caso, crece linealmente con respecto a la cantidad de elementos de las pilas, "
            "lo mismo pasa con las operaciones posteriores a cada llamada.\n"
            "\nEn resumen, se hace una llamada mas una operacion por elemento, dando como resultado O(n) de complejidad algoritmica.\n"
        );
    }
    
    int eleccion = pedirEntero("\nSalir (0) | Continuar (1): ", 0, 1);
    if (eleccion == 1)
        ejercicio6();
    else if (eleccion == 0)
        return 0;
}