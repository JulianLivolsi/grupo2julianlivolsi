#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "tp_conjuntos.h"
#include "../libs/validaciones/headers/AUXILIARES.h"
//UNIONES

Conjunto c_ej3_uniones(Lista l_de_conjuntos) {

    Conjunto resultado = cto_crear();

    Iterador it = iterador(l_de_conjuntos);

    while (hay_siguiente(it)) {

        TipoElemento te = siguiente(it);
        Conjunto c = (Conjunto) te->valor;

        resultado = cto_union(resultado, c);
    }

    free(it);

    return resultado;
}

//INTERSECCIONES

Conjunto c_ej3_intersecciones(Lista l_de_conjuntos) {

    if (l_es_vacia(l_de_conjuntos)) {
        return cto_crear();
    }

    Iterador it = iterador(l_de_conjuntos);

    // tomar primer conjunto
    TipoElemento te = siguiente(it);
    Conjunto resultado = (Conjunto) te->valor;

    // recorrer resto
    while (hay_siguiente(it)) {

        te = siguiente(it);
        Conjunto c = (Conjunto) te->valor;

        resultado = cto_interseccion(resultado, c);
    }

    free(it);

    return resultado;
}


void ejercicio3()
{
    int continuar;
    do
    {
        limpiarConsola();
        srand(time(NULL));
        printf("\n----- Ejercicio 3: Operaciones de Union e Interseccion sobre coleccion de conjuntos -----\n");

        int largo = pedirEntero("Ingrese la cantidad de conjuntos que contendra la lista: ", 1, 10);
        Lista l_conjuntos = cargarColeccionConjuntos(largo);


        printf("\n### Union de la coleccion de conjuntos: \n");
        Conjunto Unir= c_ej3_uniones(l_conjuntos);
        cto_mostrar(Unir);

        printf("### Interseccion de la coleccion de conjuntos: \n");
        Conjunto Intersecar= c_ej3_intersecciones(l_conjuntos);
        cto_mostrar(Intersecar);


        continuar = pedirEntero("\nSalir (0) | Continuar (1): ", 0, 1);
    } while (continuar == 1);
}
