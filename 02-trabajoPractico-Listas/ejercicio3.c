#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#include "tp_2_listas.h"

// EJERCICIO 3

ResultadosMul multiplo(Lista l1, Lista l2)
{
    ResultadosMul resultado;
    resultado.esMultiplo = false;
    resultado.escalar = false;
    resultado.numEscalar = 0;

    if (l_es_vacia(l1) || l_es_vacia(l2)) return resultado;

    int seguir = 1, i = 1;
    while (seguir){
        TipoElemento elemento = l_recuperar(l1, i);
        TipoElemento elemento2 = l_recuperar(l2, i);

        if (elemento->clave % elemento2->clave != 0){
            seguir = 0;
        }
    }
}

void ejercicio3()
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
}