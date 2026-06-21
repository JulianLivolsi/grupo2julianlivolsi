#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "tp_conjuntos.h"
#include "../libs/validaciones/headers/AUXILIARES.h"

Conjunto c_ej5_dif_simetrica(Conjunto A, Conjunto B) {

    // A - B
    Conjunto solo_A = cto_diferencia(A, B);

    // B - A
    Conjunto solo_B = cto_diferencia(B, A);

    // (A - B) U (B - A)
    Conjunto resultado = cto_union(solo_A, solo_B);

    return resultado;
}


void ejercicio5()
{
    int continuar;
    do
    {
        limpiarConsola();
        srand(time(NULL));
        printf("\n----- Ejercicio 5: Diferencia simetrica entre conjuntos -----\n");

        int largo1 = pedirEntero("Ingrese el largo del conjunto A: ", 1, 10);
        Conjunto c1 = rellenarConjunto(largo1);

        int largo2 = pedirEntero("Ingrese el largo del conjunto B: ", 1, 10);
        Conjunto c2 = rellenarConjunto(largo2);

        printf("\n### Conjunto A: \n");
        cto_mostrar(c1);
        printf("### Conjunto B: \n");
        cto_mostrar(c2);


        Conjunto dif_sim= c_ej5_dif_simetrica(c1, c2);
        printf("la diferencia simetrica entre el conjunto A y B es: \n");
        cto_mostrar(dif_sim);

        continuar = pedirEntero("\nSalir (0) | Continuar (1): ", 0, 1);
    } while (continuar == 1);
}
