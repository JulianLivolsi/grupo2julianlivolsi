#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "utilidades.h"

void limpiarConsola()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

Pila rellenarPila(int elementos)
{   // si elementos es pasado con el como -1 pregunta el largo al usuario
    if (elementos == -1)
    {
        elementos = pedirEntero("Cual es el largo de esta Pila: ", 0, 10);
    }
    if (elementos == 0)
    {
        return p_crear();
    }
    Pila resultado = p_crear();
    int aleatorio = pedirEntero("Queire llenar la pila aleatoriamente? -> No(0) | Si(1): ", 0, 1);
    if (aleatorio == 1)
    {
        for (int j = 0; j < elementos; j++)
        {
            TipoElemento random = te_crear(rand() % 100);
            p_apilar(resultado, random);
        }
    }
    else
    {
        int numItem = elementos;
        for (int j = 0; j < elementos; j++)
        {
            char mensaje[100];
            sprintf(mensaje, "Ingrese el elemento %i: ", numItem);
            numItem--;
            int elem = pedirEntero(mensaje, -1000, 1000);
            TipoElemento elemento = te_crear(elem);
            p_apilar(resultado, elemento);
        }
    }
    return resultado;
}

void p_intercambiar(Pila P, Pila Paux)
{
    if (p_es_vacia(Paux))
    {
        return;
    }

    TipoElemento X = te_crear(0);
    while (p_es_vacia(Paux) != true)
    {
        X = p_desapilar(Paux);
        p_apilar(P, X);
    }
}

Pila pilaClon(Pila p)
{
    Pila Paux = p_crear();
    Pila clon = p_crear();

    while (p_es_vacia(p) != true)
    {
        TipoElemento element = p_desapilar(p);
        p_apilar(Paux, element);
    }

    while (p_es_vacia(Paux) != true)
    {
        TipoElemento element = p_desapilar(Paux);
        TipoElemento copia1 = te_crear(element->clave);
        TipoElemento copia2 = te_crear(element->clave);
        p_apilar(clon, copia2); // construir clon
        p_apilar(p, copia1);    // restaurar original
    }

    return clon;
}

int p_tamanio(Pila P)
{
    int tamanio = 0;
    Pila aux = p_crear();
    TipoElemento X = te_crear(0);
    while (!(p_es_vacia(P)))
    {
        X = p_desapilar(P);
        p_apilar(aux, X);
        tamanio++;
    }
    p_intercambiar(P, aux);
    return tamanio;
}