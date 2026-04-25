#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

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
    if (l_es_vacia(l1)) return 0;

    for (int i = 1; i <= l_longitud(l1); i++)
    {
        total+= l_recuperar(l1, i)->clave;
    }
    return total / l_longitud(l1);
}

ResultadoPromedioAmbasListas promedioAmbasListas(Lista l1, Lista l2)
{
    ResultadoPromedioAmbasListas r; //crea la variable a retornar

    r.prom1 = promedio(l1);////asigna promedio de l1
    r.prom2 = promedio(l2);//asigna promedio de l2

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