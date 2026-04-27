#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#include "tp_2_listas.h"
#include "../libs/validaciones/headers/AUXILIARES.h"

// P4 Retorna 1 si L1 > L2, 2 si L2 > L1, 0 si son iguales
int CompararListas(Lista l1, Lista L2)
{
    int mayoresL1 = 0, mayoresL2 = 0; // Crea contadores de mayores para cada lista | Complejidad 0(1)

    Iterador it1 = iterador(l1); // Crea iteradores para cada lista | Complejidad O(1)
    Iterador it2 = iterador(L2);

    while (hay_siguiente(it1) && hay_siguiente(it2)) // Itera las listas mientras que AMBAS tengan siguiente elemento | Complejidad O(N)
    {
        TipoElemento e1 = siguiente(it1); // Sacamos los elementos y avanzamos el iterador un paso
        TipoElemento e2 = siguiente(it2);

        if (e1->clave > e2->clave) // Compara las claves y aumento el contador de la lista que tiene el mayor valor
        {
            mayoresL1++;
        }
        else if (e1->clave < e2->clave)
        {
            mayoresL2++;
        }
    }

    free(it1); free(it2); // Libera la memoria de los iteradores

    if (mayoresL1 > mayoresL2) return 1;
    else if (mayoresL1 < mayoresL2) return 2;
    else return 0;

    // El algoritmo tiene complejidad O(N), debido al while que depende de la N cantidad de elementos de la lista mas corta
}