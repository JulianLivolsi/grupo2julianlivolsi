#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tp_pilas.h"
#include "utilidades.h"

Pila p_ej8_sacarrepetidos(Pila p){
    if (p_es_vacia(p)){
        printf("PILA VACIA !!! \n");
        return p_crear();
    }

    Pila clon = pilaClon(p);
    Pila sinDuplicados = p_crear();
    Pila aux1 = p_crear(); 
    Pila aux2 = p_crear();
    Pila pilaConRepetidas = p_crear();
    int contadorRepeticiones = 0;
    TipoElemento element1, element2, element3, element4;
    bool encontrado;

    while (!p_es_vacia(p)){
        element1 = p_desapilar(p);
        p_apilar(aux1,element1);
        encontrado = false;
        
        while (!p_es_vacia(sinDuplicados)) {
         element2 = p_desapilar(sinDuplicados);
            p_apilar(aux2, element2);
            if (element2->clave == element1->clave) {
                encontrado = true;
            }
        }

        p_intercambiar(sinDuplicados, aux2);

        if (!encontrado){
            p_apilar(sinDuplicados, te_crear(element1->clave));
        }
    }
    p_intercambiar(p, aux1);

    while (!p_es_vacia(sinDuplicados)){
        element3 = p_desapilar(sinDuplicados);
        while (!p_es_vacia(clon)){
            element4 = p_desapilar(clon);
            if (element3->clave == element4->clave){
                contadorRepeticiones++;
            }
            p_apilar(aux2,element4);
        }

        p_intercambiar(clon,aux2);
        int *repeticion = malloc(sizeof(int));
        *repeticion = contadorRepeticiones;
        contadorRepeticiones = 0;
        TipoElemento nuevo = te_crear_con_valor(element3->clave, repeticion);
        p_apilar(pilaConRepetidas, nuevo);
    }

    return pilaConRepetidas;
}

void ejercicio8(){
    limpiarConsola();
    srand(time(NULL));
    printf("\n------ Ejercicio 8 - Pila sin duplicados y cant de ocurrencias ------\n");
    Pila pila = rellenarPila(-1);
    Pila Resultado = p_ej8_sacarrepetidos(pila);
    printf("\nPila original: \n-> ");
    p_mostrar(pila);


    printf("----------------\n");
    printf("\nPila sin repetidos: \n-> ");
    while (!p_es_vacia(Resultado)){
        TipoElemento elemet = p_desapilar(Resultado);
        int *valor = (int *)elemet->valor;
        printf("%d:%i,",elemet->clave,*valor);
    }
    printf("\n");
    printf(
        "\nLa complejidad algoritmica de esta funcion es de O(n^2). Es decir, complejidad cuadratica."
        "\nEn esta funcion hay dos bucles 'while' diferentes pero en ambos casos estan anidados:"
        "\n\nEn el primer bucle 'while' anidado se crea una pila igual a la pila original sin duplicados, "
        "para eso se recorre una vez los elementos de la pila original. Y dentro de este bucle, hay otro bucle "
        "'while' que recorre la pila 'sinDuplicados', la cual en el peor de los casos tiene la misma cantidad de "
        "elementos que la pila original. Este segundo bucle hace n comparaciones por cada elemento de la pila original."
        " Por lo tanto, el costo de este bloque es O(n^2), ya que dentro del primer bucle se hace una operacion de "
        "comparacion dentro de un bucle anidado que recorre hasta n elementos.\n"
        
        "\nEn el segundo bucle 'while' anidado se crea una pila con los elementos de la pila original sin repeticiones "
        "y la cantidad de veces que aparecen. Para hacer eso, se recorre la pila 'sinDuplicados', que tiene hasta n "
        "elementos (en el peor caso). Dentro de este bucle, hay un segundo bucle que recorre la pila 'clon', que es una "
        "copia de la pila original, que tambien puede tener hasta n elementos. Esto significa que, para cada elemento de "
        "'sinDuplicados', se recorren todos los elementos de 'clon', lo que lleva a una complejidad de O(n^2) en este "
        "bloque tambien.\n"
        
        "\nDado que ambos bloques principales tienen una complejidad de O(n^2), la complejidad total de la funcion es O(n^2).\n"
    );
    
    
    int eleccion = pedirEntero("\nSalir (0) | Continuar (1): ", 0, 1);
    if (eleccion == 1)
        ejercicio8();
    else if (eleccion == 0)
        printf("Saliendo del ejercicio8.");
}
