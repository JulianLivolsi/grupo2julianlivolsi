#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "tp_2_listas.h"
#include "../libs/validaciones/headers/AUXILIARES.h"

// P4 Retorna 1 si L1 > L2, 2 si L2 > L1, 0 si son iguales
int CompararListas(Lista l1, Lista l2)
{
    int mayoresL1 = 0, mayoresL2 = 0; // Crea contadores de mayores para cada lista | Complejidad O(1)

    Iterador it1 = iterador(l1); // Crea iteradores para cada lista | Complejidad O(1)
    Iterador it2 = iterador(l2);

    while (hay_siguiente(it1) && hay_siguiente(it2)) // Itera las listas mientras que AMBAS tengan siguiente elemento | Complejidad O(N)
    {
        TipoElemento e1 = siguiente(it1); // Sacamos los elementos y avanzamos el iterador un paso
        TipoElemento e2 = siguiente(it2);

        if (e1->clave > e2->clave) // Compara las claves y aumenta el contador de la lista que tiene el mayor valor
        {
            mayoresL1++;
        }
        else if (e1->clave < e2->clave)
        {
            mayoresL2++;
        }
    }

    free(it1);
    free(it2); // Libera la memoria de los iteradores

    if (mayoresL1 > mayoresL2)
        return 1;
    else if (mayoresL1 < mayoresL2)
        return 2;
    else
        return 0;

    // El algoritmo tiene complejidad O(N), debido al while que depende de la N cantidad de elementos de la lista mas corta
}

void ejercicio4()
{
    int continuar;
    do
    {
        limpiarConsola();
        srand(time(NULL));

        printf("\n----- Ejercicio 4: Comparacion de listas -----\n");

        int largo = pedirEntero("Ingrese el largo de las listas (para comparar posicion a posicion ambas tienen el mismo): ", 1, 100);

        Lista l1 = rellenarLista(largo);
        Lista l2 = rellenarLista(largo);

        printf("\n### Lista 1: \n");
        l_mostrar(l1);
        printf("### Lista 2: \n");
        l_mostrar(l2);

        int resultado = CompararListas(l1, l2);

        if (resultado == 1)
            printf("\nL1 > L2: la lista 1 tiene mas claves mayores posicion a posicion.\n");
        else if (resultado == 2)
            printf("\nL1 < L2: la lista 2 tiene mas claves mayores posicion a posicion.\n");
        else
            printf("\nL1 = L2: ambas listas tienen la misma cantidad de claves mayores.\n");

        printf("\nComplejidad algoritmica: O(N), donde N es la longitud de la lista mas corta.\n");

        continuar = pedirEntero("\nSalir (0) | Continuar (1): ", 0, 1);
    } while (continuar == 1);
}