#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "tp_2_listas.h"
#include "../libs/validaciones/headers/AUXILIARES.h"


bool esSublista(Lista l1, Lista l2)
{
    if (l_es_vacia(l2))
        return true; // Lista vacia es sublista de cualquier lista
    if (l_es_vacia(l1))
        return false; // L1 vacia no puede contener elementos de L2

    for (int i = 1; i <= l_longitud(l2); i++) // Recorre cada elemento de L2 | O(N)
    {
        TipoElemento elem = l_recuperar(l2, i);
        if (l_buscar(l1, elem->clave) == NULL) // Busca el elemento en L1 | O(M)
        {
            return false; // Si falta alguno, no es sublista
        }
    }
    return true;
}

void ejercicio6()
{
    int continuar;
    do
    {
        limpiarConsola();
        srand(time(NULL));

        printf("\n----- Ejercicio 6: Sublista -----\n");

        int largo1 = pedirEntero("Ingrese el largo de la Lista 1 (lista principal): ", 1, 100);
        Lista l1 = rellenarLista(largo1);

        int largo2 = pedirEntero("Ingrese el largo de la Lista 2 (posible sublista): ", 1, 100);
        Lista l2 = rellenarLista(largo2);

        printf("\n### Lista 1: \n");
        l_mostrar(l1);
        printf("### Lista 2: \n");
        l_mostrar(l2);

        if (esSublista(l1, l2))
            printf("\nL2 ES sublista de L1: todos los elementos de L2 se encuentran en L1.\n");
        else
            printf("\nL2 NO es sublista de L1: hay al menos un elemento de L2 que no esta en L1.\n");

        printf("\nComplejidad algoritmica: O(N * M), donde N = longitud de L2 y M = longitud de L1.\n");

        continuar = pedirEntero("\nSalir (0) | Continuar (1): ", 0, 1);
    } while (continuar == 1);
}