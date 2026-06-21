#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "tp_conjuntos.h"
#include "../libs/validaciones/headers/AUXILIARES.h"

Conjunto c_ej2_union(Conjunto A, Conjunto B) {
    return cto_union(A, B);
}

Conjunto c_ej2_interseccion(Conjunto A, Conjunto B) {
    return cto_interseccion(A, B);
}

Conjunto c_ej2_diferencia(Conjunto A, Conjunto B) {
    return cto_diferencia(A, B);
}


void ejercicio2()
{
    int continuar;
    do
    {
        limpiarConsola();
        srand(time(NULL));
        printf("\n----- Ejercicio 2: Operaciones sobre dos conjuntos -----\n");

        int largo1 = pedirEntero("Ingrese el largo del conjunto A: ", 1, 10);
        Conjunto c1 = rellenarConjunto(largo1);

        int largo2 = pedirEntero("Ingrese el largo del conjunto B: ", 1, 10);
        Conjunto c2 = rellenarConjunto(largo2);

        printf("\n### Conjunto A: \n");
        cto_mostrar(c1);
        printf("### Conjunto B: \n");
        cto_mostrar(c2);

        Conjunto Union = c_ej2_union(c1, c2);
        printf("\n Elementos que resultan de la union de los conjuntos A y B: \n");
        cto_mostrar(Union);

        
        Conjunto Interseccion = c_ej2_interseccion(c1,c2);
        printf("\nElementos que resultan de la interseccion de los conjuntos A y B: \n");
        cto_mostrar(Interseccion);

        
        Conjunto Diferencia = c_ej2_diferencia(c1, c2);
        printf("\n Elementos que son diferentes entre los conjuntos A y B: \n");
        cto_mostrar(Diferencia);


        continuar = pedirEntero("\nSalir (0) | Continuar (1): ", 0, 1);
    } while (continuar == 1);
}
