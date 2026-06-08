#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tp_colas.h"

typedef struct
{
    int posicionPila;
    int posicionCola;
} respuestaPosiciones;

void buscar_y_registrar(Cola c, int clave_pila, int pos_pila, Lista res)
{
    Cola aux = c_crear();
    int contador = 1;
    respuestaPosiciones Raux;

    while(!c_es_vacia(c))
    {
        TipoElemento te = c_desencolar(c);
        c_encolar(aux, te);
        if (te->clave == clave_pila)
        {
            Raux.posicionCola = contador;
            Raux.posicionPila = pos_pila;
            respuestaPosiciones *ptr = malloc(sizeof(respuestaPosiciones));
            *ptr = Raux;
            TipoElemento te_res = te_crear_con_valor(clave_pila, ptr);
            l_agregar(res, te_res);
        }
        contador++;
    }
    c_intercambiar(c, aux);
    free(aux);
}

Lista c_ej6_comunesapilaycola(Pila p, Cola c)
{
    if (p_es_vacia(p) || c_es_vacia(c)) return l_crear();

    Pila Paux = p_crear();
    Lista resultado = l_crear();
    int posPila = 1;

    while(!p_es_vacia(p))
    {
        TipoElemento te = p_desapilar(p);
        buscar_y_registrar(c, te->clave, posPila, resultado);
        p_apilar(Paux, te);
        posPila++;
    }

    while(!p_es_vacia(Paux))
    {
        TipoElemento te = p_desapilar(Paux);
        p_apilar(p, te);
    }
    free(Paux);

    return resultado;
}

int ejercicio6()
{
    limpiarConsola();
    srand(time(NULL));
    printf("\n------ Ejercicio 6 ------\n");
    
    Cola c = rellenarCola(-1);
    printf("\nCola : \n");
    c_mostrar(c);

    Pila p = rellenarPila(-1);
    printf("\nPila : \n");
    p_mostrar(p);

    Lista res = c_ej6_comunesapilaycola(p, c); 
    printf("\nElementos comunes : \n");
    l_mostrar(res);

    int eleccion = pedirEntero("\nSalir (0) | Continuar (1): ", 0, 1);
    if (eleccion == 1)
        ejercicio6();
    else if (eleccion == 0)
        return 0;
}

//COMPLEJIDAD SIN EL TAD
/*Siendo N la cantidad de elementos de la pila y M la cantidad de elementos de la cola, por cada elemento N se recorren todos los elementos M;
de modo que la complejidad seria O(N*M). En el peor caso, donde N=M, tenemos que la complejidad del algoritmo es O(N2).
    
COMPLEJIDAD SEGUN IMPLEMENTACION DEL TAD
Arreglos: como desencolar es de complejidad lineal, la funcion buscar_y_registrar() es de complejidad cuadratica. Dado que la funcion principal recorre los
N elementos de la pila y llama a buscar_y_registrar() por cada uno, tenemos que la complejidad final es O(N3).
Arreglos circulares: Al ser de complejidad constante todas las operaciones involucradas, el algoritmo continua teniendo comlplejidad cuadratica. 
Apuntadores:como encolar es de complejidad lineal, buscar_y_registrar() sera O(N2). Como el algoritmo recorre los elementos de la pila y llama 
a buscar_y_registrar() por cada uno, se obtiene una complejidad de O(N3).*/
