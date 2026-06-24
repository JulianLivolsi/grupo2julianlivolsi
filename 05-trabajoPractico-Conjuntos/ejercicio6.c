#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "tp_conjuntos.h"
#include "../libs/validaciones/headers/AUXILIARES.h"



bool c_ej6_subconjuntopropio(Conjunto A, Conjunto B) {

    if (!es_subconjunto(A, B)) {
        return false;
    }

    if (cto_cantidad_elementos(A) == cto_cantidad_elementos(B)) {
        return false;
    }

    return true;
}

/*COMPLEJIDAD: 
el algoritmo tiene 2 bloques; el primero llama a es_subconjunto() cuya complejidad es O(N2) para cualquier implementacion de listas, y en el segundo llama a 
cto_cantidad_elementos() de complejidad O(1) para cualquier implementacion de listas. Por lo tanto, la complejidad final sera Cuadratica O(N2)*/

void ejercicio6()
{
    int continuar;
    do
    {
        limpiarConsola();
        srand(time(NULL));
        printf("\n----- Ejercicio 6: Subconjunto Propio -----\n");

        int largo1 = pedirEntero("Ingrese el largo del conjunto A: ", 1, 10);
        Conjunto c1 = rellenarConjunto(largo1);

        int largo2 = pedirEntero("Ingrese el largo del conjunto B: ", 1, 10);
        Conjunto c2 = rellenarConjunto(largo2);

        printf("\n### Conjunto A: \n");
        cto_mostrar(c1);
        printf("### Conjunto B: \n");
        cto_mostrar(c2);

        if (c_ej6_subconjuntopropio(c1, c2)){
            printf("\ El Conjunto A es subconjunto propio del Conjunto B: \n");
        }else{
            printf("\ El Conjunto A no es subconjunto propio del Conjunto B: \n");
        }


        continuar = pedirEntero("\nSalir (0) | Continuar (1): ", 0, 1);
    } while (continuar == 1);
}
