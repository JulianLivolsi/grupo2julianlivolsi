#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#include "tp_2_listas.h"

ResultadosMul multiplo(Lista l1, Lista l2)
{
    ResultadosMul resultado; // Definimos el resultado base como false y escalar 0
    resultado.esMultiplo = false;
    resultado.escalar = false;
    resultado.numEscalar = 0;

    if (l_es_vacia(l1) || l_es_vacia(l2)) return resultado; // Si alguna esta vacia retornamos el resultado base
    if (l_longitud(l1) != l_longitud(l2)) return resultado; // Si son de distinta longitud retornamos el resultado base

    Iterador it1 = iterador(l1);
    Iterador it2 = iterador(l2);

    bool todosMultiplos = true, esEscalar = true;
    int k_base = 0;
    bool primerElemento = true; 

    while (hay_siguiente(it1) && hay_siguiente(it2))
    {
        TipoElemento e1 = siguiente(it1); // Sacamos los elementos y avanzamos el iterador un paso
        TipoElemento e2 = siguiente(it2);

        if (e1->clave == 0) // Verifica que no divida por 0
        { 
            if (e2->clave != 0) // Si la clave del otro elemento no es 0, no son multiplo
            {
                todosMultiplos = false;
                break;
            }
            continue; 
        }
        if (e2->clave % e1->clave != 0) // Verifica si NO es multiplo
        { 
            todosMultiplos = false;
            esEscalar = false;
            break; 
        }

        int k_actual = e2->clave / e1->clave; // Verifica la logica del escalar

        if (primerElemento)
        {
            k_base = k_actual; 
            primerElemento = false; // Apagamos la bandera para las siguientes vueltas
        }
        else
        {
            if (k_actual != k_base)
            {
                esEscalar = false; 
            }
        }
    }

    if (todosMultiplos) {
        resultado.esMultiplo = true;
        resultado.escalar = esEscalar;
        if (esEscalar) {
            resultado.numEscalar = k_base;
        }
    }

    free(it1); // Liberamos la memoria para los iteradores
    free(it2);

    return resultado;
}

/* void ejercicio3()
{
    limpiarConsola();
    srand(time(NULL));
    printf("\n------   Ejercicio 3: Multiplo   ------\n");
    int largo = pedirEntero("ingrese el largo de las listas (ambas tendran el mismo): ", 1, 100);
    Lista l1 = rellenarLista(largo);
    Lista l2 = rellenarLista(largo);
    printf("\n### Lista 1: \n");
    l_mostrar(l1);
    printf("### Lista 2: \n");
    l_mostrar(l2);

    ResultadosMul resultadoDeMultiplos = multiplo(l1,l2);

    if (resultadoDeMultiplos.esMultiplo){
        printf("Las listas son múltiplos entre si");
        if (resultadoDeMultiplos.escalar) {
            printf(" y ademas el multiplo es un escalar constante: %d\n", resultadoDeMultiplos.numEscalar);
        } else {
            printf(", pero el multiplo no es constante (varia entre posiciones).\n");
        }
    }else {
        printf("\nLas listas no son multiplos entre si");
    } printf("\nLas listas no son multiplos entre si");

    int continuar = pedirEntero("\nSalir (0) | Continuar (1): ", 0, 1);
    if (continuar == 1)
        ejercicio3();
} */


// Lo unico que cambie fue que en lugar de llamarse recursivamente, se use un do while para volverse a ejecutar hasta que el usuario salga, para usar menos memoria
void ejercicio3()
{
    int continuar;
    do
    {
        limpiarConsola();
        srand(time(NULL));

        printf("\n----- Ejercicio 3: Multiplo -----");
        int largo = pedirEntero("\nIngrese el largo de las listas (para que sean multiplo ambas tienen el mismo): ", 1, 100);

        Lista l1 = rellenarLista(largo); // Esta funcion auxiliar usa l_crear y rellena los elementos con 
        Lista l2 = rellenarLista(largo);

        printf("\n### Lista 1: \n");
        l_mostrar(l1);
        printf("\n### Lista 2: \n");
        l_mostrar(l2);

        ResultadosMul resultadoDeMultiplos = multiplo(l1,l2);

        if (resultadoDeMultiplos.esMultiplo)
        {
            printf("\nLas listas son multiplos entre si");
            if (resultadoDeMultiplos.escalar)
            {
                printf(", y son multiplos por un escalar constante = %d\n", resultadoDeMultiplos.numEscalar);
            } else
            {
                printf(", pero el multiplo no es constante (varia entre posiciones).\n");
            }
        } else
        {
            printf("\nLas listas no son multiplos entre si.\n");
        }
        continuar = pedirEntero("\nSalir (0) | Continuar (1): ", 0, 1);
    } while (continuar == 1);
}