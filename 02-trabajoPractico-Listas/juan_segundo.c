#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#include "tp_2_listas.h"
#include "../libs/validaciones/headers/AUXILIARES.h"

// EJERCICIO 3

typedef struct
{
    bool esMultiplo;
    bool escalar;
    int numEscalar;
} ResultadosMul;

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