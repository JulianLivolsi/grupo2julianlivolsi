#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "tp_2_listas.h"
#include "../libs/validaciones/headers/AUXILIARES.h"

// A
Lista verElementosQueNoSeRepitenA(Lista l1, Lista l2)
{ // BUSCA LOS ELEMENTOS DE L1 EN L2. SI NO ESTAN EN L2 LOS AGREGA A RESULTADO
    Lista resultado = l_crear();

    for (int i = 1; i <= l_longitud(l1); i++)
    {
        TipoElemento elemento = l_recuperar(l1, i);

        if (l_buscar(l2, elemento->clave) == NULL)
        {
            l_agregar(resultado, te_crear(elemento->clave));
        }
    }
    return resultado;
}

// B
Lista verElementosQueNoSeRepitenB(Lista l1, Lista l2)
{ // BUSCA LOS ELEMENTOS DE L2 EN L1. SI NO ESTAN EN L1 LOS AGREGA A RESULTADO
    Lista resultado = l_crear();

    for (int i = 1; i <= l_longitud(l2); i++)
    {
        TipoElemento elemento = l_recuperar(l2, i);

        if (l_buscar(l1, elemento->clave) == NULL)
        {
            l_agregar(resultado, te_crear(elemento->clave));
        }
    }
    return resultado;
}

// C
Lista verElementosRepetidos(Lista l1, Lista l2)
{
    Lista resultado = l_crear();

    for (int i = 1; i <= l_longitud(l1); i++)
    {
        TipoElemento elemento = l_recuperar(l1, i);

        if (l_buscar(l2, elemento->clave) != NULL)
        {
            l_agregar(resultado, te_crear(elemento->clave));
        }
    }
    return resultado;
}

// D
float promedio(Lista l1)
{
    float total = 0;
    if (l_es_vacia(l1))
        return 0;

    for (int i = 1; i <= l_longitud(l1); i++)
    {
        total += l_recuperar(l1, i)->clave;
    }
    return total / l_longitud(l1);
}

ResultadoPromedioAmbasListas promedioAmbasListas(Lista l1, Lista l2)
{
    ResultadoPromedioAmbasListas r;
    r.prom1 = promedio(l1);
    r.prom2 = promedio(l2);
    return r;
}

// E
ResultadoValorMinimo valorMinimo(Lista l1, Lista l2)
{
    ResultadoValorMinimo resultado;
    resultado.pos = -1;
    resultado.valor = -1;
    resultado.pos_2 = -1;
    resultado.valor_2 = -1;

    if (!l_es_vacia(l1))
    {
        resultado.valor = l_recuperar(l1, 1)->clave;
        resultado.pos = 1;

        for (int i = 2; i <= l_longitud(l1); i++)
        {
            TipoElemento elemento = l_recuperar(l1, i);
            if (elemento->clave < resultado.valor)
            {
                resultado.valor = elemento->clave;
                resultado.pos = i;
            }
        }
    }

    if (!l_es_vacia(l2))
    {
        resultado.valor_2 = l_recuperar(l2, 1)->clave;
        resultado.pos_2 = 1;

        for (int i = 2; i <= l_longitud(l2); i++)
        {
            TipoElemento elemento = l_recuperar(l2, i);
            if (elemento->clave < resultado.valor_2)
            {
                resultado.valor_2 = elemento->clave;
                resultado.pos_2 = i;
            }
        }
    }

    return resultado;
}

void ejercicio2()
{
    int continuar;
    do
    {
        limpiarConsola();
        srand(time(NULL));
        printf("\n----- Ejercicio 2: Operaciones sobre dos listas -----\n");

        int largo1 = pedirEntero("Ingrese el largo de la Lista 1: ", 1, 100);
        Lista l1 = rellenarLista(largo1);

        int largo2 = pedirEntero("Ingrese el largo de la Lista 2: ", 1, 100);
        Lista l2 = rellenarLista(largo2);

        printf("\n### Lista 1: \n");
        l_mostrar(l1);
        printf("### Lista 2: \n");
        l_mostrar(l2);

        // A
        Lista soloEnL1 = verElementosQueNoSeRepitenA(l1, l2);
        printf("\na) Elementos de L1 que NO estan en L2: \n");
        if (l_es_vacia(soloEnL1))
            printf("(ninguno)\n");
        else
            l_mostrar(soloEnL1);

        // B
        Lista soloEnL2 = verElementosQueNoSeRepitenB(l1, l2);
        printf("\nb) Elementos de L2 que NO estan en L1: \n");
        if (l_es_vacia(soloEnL2))
            printf("(ninguno)\n");
        else
            l_mostrar(soloEnL2);

        // C
        Lista comunes = verElementosRepetidos(l1, l2);
        printf("\nc) Elementos comunes a L1 y L2: \n");
        if (l_es_vacia(comunes))
            printf("(ninguno)\n");
        else
            l_mostrar(comunes);

        // D
        ResultadoPromedioAmbasListas promedios = promedioAmbasListas(l1, l2);
        printf("\nd) Promedio de L1: %.2f", promedios.prom1);
        printf("\n   Promedio de L2: %.2f\n", promedios.prom2);

        // E
        ResultadoValorMinimo minimos = valorMinimo(l1, l2);
        printf("\ne) Minimo de L1: %d (posicion %d)", minimos.valor, minimos.pos);
        printf("\n   Minimo de L2: %d (posicion %d)\n", minimos.valor_2, minimos.pos_2);

        continuar = pedirEntero("\nSalir (0) | Continuar (1): ", 0, 1);
    } while (continuar == 1);
}