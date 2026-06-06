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

//COMPLEJIDAD
/*Siendo N la cantidad de elementos de la pila y M la cantidad de elementos de la cola, por cada elemento N se recorren todos los elementos M;
de modo que la complejidad seria O(N*M). En el peor caso, donde N=M, tenemos que la complejidad del algoritmos es O(N2)*/
