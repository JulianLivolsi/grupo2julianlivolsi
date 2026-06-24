#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "tp_conjuntos.h"
#include "../libs/validaciones/headers/AUXILIARES.h"

int contar_en_comun(Conjunto X, Conjunto Y) {

    int contador = 0;

    for (int i = 1; i <= cto_cantidad_elementos(X); i++) {

        TipoElemento e = cto_recuperar(X, i);

        if (cto_pertenece(Y, e->clave)) {
            contador++;
        }
    }

    return contador;
}

void c_ej7_subconjtotalparcial(Conjunto A, Conjunto B, Conjunto C) {

    int a_en_b = contar_en_comun(A, B);
    int a_en_c = contar_en_comun(A, C);

    int b_en_a = contar_en_comun(B, A);
    int b_en_c = contar_en_comun(B, C);

    int c_en_a = contar_en_comun(C, A);
    int c_en_b = contar_en_comun(C, B);

    int tamA = cto_cantidad_elementos(A);
    int tamB = cto_cantidad_elementos(B);
    int tamC = cto_cantidad_elementos(C);

    // A en B
    if (a_en_b == tamA) {
        printf("A es subconjunto TOTAL de B\n");
    } else if (a_en_b >= tamA / 2.0) {
        printf("A es subconjunto PARCIAL de B\n");
    }

    // A en C
    if (a_en_c == tamA) {
        printf("A es subconjunto TOTAL de C\n");
    } else if (a_en_c >= tamA / 2.0) {
        printf("A es subconjunto PARCIAL de C\n");
    }

    // B en A
    if (b_en_a == tamB) {
        printf("B es subconjunto TOTAL de A\n");
    } else if (b_en_a >= tamB / 2.0) {
        printf("B es subconjunto PARCIAL de A\n");
    }

    // B en C
    if (b_en_c == tamB) {
        printf("B es subconjunto TOTAL de C\n");
    } else if (b_en_c >= tamB / 2.0) {
        printf("B es subconjunto PARCIAL de C\n");
    }

    // C en A
    if (c_en_a == tamC) {
        printf("C es subconjunto TOTAL de A\n");
    } else if (c_en_a >= tamC / 2.0) {
        printf("C es subconjunto PARCIAL de A\n");
    }

    // C en B
    if (c_en_b == tamC) {
        printf("C es subconjunto TOTAL de B\n");
    } else if (c_en_b >= tamC / 2.0) {
        printf("C es subconjunto PARCIAL de B\n");
    }
}

/*COMPLEJIDAD:
la funcion auxiliar contar_en_comun() recorre N elementos, y por cada uno llama a una operacion de complejidad lineal, resultando en una complejidad cuadratica
para cualquiera de las implementaciones de listas. Esta funcion se llama 6 veces en el algoritmo principal, ademas de llamar a cto_cantidad_elementos() que es
de complejidad constante. Asi, la complejidad final sera 6*O(N2)=O(N2), complejidad cuadratica.*/

void ejercicio7()
{
    int continuar;
    do
    {
        limpiarConsola();
        srand(time(NULL));
        printf("\n----- Ejercicio 7: Subconjuntos Totales y Parciales -----\n");

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

        c_ej7_subconjtotalparcial(c1, c2, c3);


        continuar = pedirEntero("\nSalir (0) | Continuar (1): ", 0, 1);
    } while (continuar == 1);
}
