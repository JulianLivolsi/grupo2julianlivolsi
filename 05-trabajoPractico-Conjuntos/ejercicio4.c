#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "tp_conjuntos.h"
#include "../libs/validaciones/headers/AUXILIARES.h"

bool es_subconjunto(Conjunto X, Conjunto Y) {

    for (int i = 1; i <= cto_cantidad_elementos(X); i++) {

        TipoElemento e = cto_recuperar(X, i);

        if (!cto_pertenece(Y, e->clave)) {
            return false;
        }
    }

    return true;
}


bool c_ej4_transitividad(Conjunto A, Conjunto B, Conjunto C) {

// Verifico A es subconjunto de B
    if (!es_subconjunto(A, B)) {
        return false;
    }

    // Verifico B es subconjunto de C
    if (!es_subconjunto(B, C)) {
        return false;
    }

    // Si ambas se cumplen, entonces A es subconjunto de C
    return es_subconjunto(A, C);
}

void ejercicio4()
{
    int continuar;
    do
    {
        limpiarConsola();
        srand(time(NULL));
        printf("\n----- Ejercicio 4: Verificar transitividad -----\n");

        int largo1 = pedirEntero("Ingrese el largo del conjunto A: ", 1, 10);
        Conjunto c1 = rellenarConjunto(largo1);

        int largo2 = pedirEntero("Ingrese el largo del conjunto B: ", 1, 10);
        Conjunto c2 = rellenarConjunto(largo2);

        int largo3 = pedirEntero("Ingrese el largo del conjunto C: ", 1, 10);
        Conjunto c3 = rellenarConjunto(largo3);

        printf("\n### Conjunto A: \n");
        cto_mostrar(c1);
        printf("### Conjunto B: \n");
        cto_mostrar(c2);
        printf("### Conjunto C: \n");
        cto_mostrar(c3);


        if (c_ej4_transitividad(c1, c2, c3)){
            printf("\n La propiedad de la transitividad se cumple en estos conjuntos: \n");
        }else{
            printf("\n La propiedad de la transitividad no es valida en estos conjuntos: \n");
        }

        continuar = pedirEntero("\nSalir (0) | Continuar (1): ", 0, 1);
    } while (continuar == 1);
}
