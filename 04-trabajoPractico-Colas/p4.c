#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tp_colas.h"

#include "../libs/validaciones/headers/AUXILIARES.h"


int contarApariciones(Cola c, int clave) // Función auxiliar que cuenta la cantidad de apariciones de una clave en una cola
{
    Cola aux = c_crear(); // Creo una cola auxiliar
    int contador = 0; // Inicializo un contador en 0

    while(!c_es_vacia(c)) // Mientras la cola original no sea vacia la desencolo
    {
        TipoElemento te = c_desencolar(c);
        c_encolar(aux, te); // Encolo el elemento de c en aux
        if (te->clave == clave) // Si la clave del TipoElemento desencolado de la original coincide con la clave ingresada como parametro...
        {
            contador++; // Sumo 1 al contador
        }
    }
    c_intercambiar(c, aux); // Recupero la cola original

    free(aux); // Libero la cola auxiliar
    return contador; // Retorno el valor del contador
}

Cola c_ej4_colanorepetidos(Cola c)
{
    if (c_es_vacia(c)) return c_crear(); // Si la cola es vacia retorno una cola vacia

    Cola aux = c_crear(), res = c_crear(); // Creo colas auxiliares y resultado
    Cola copiaInmutable = c_ej2_copiar(c); // Creo una cola copia de la original, que no mutará a lo largo de la función para utilizarla en la llamada a contarApariciones
    bool todosRepetidos = true; // Creo una bandera para ver si todos los elementos están repetidos

    while(!c_es_vacia(c)) // Mientras la cola original no sea vacia la desencolo
    {
        TipoElemento te = c_desencolar(c);
        c_encolar(aux, te); // Encolo el elemento desencolado de la original en aux

        if (contarApariciones(copiaInmutable, te->clave) == 1) // Si al llamar a la funcion contarApariciones con la clave del TipoElemento extraido, obtengo un 1
        {
            TipoElemento te_res = te_crear_con_valor(te->clave, te->valor); // Creo una copia de este TipoElemento
            c_encolar(res, te_res); // Encolo la copia del TipoElemento en la cola resultado
            todosRepetidos = false; // Cambio el valor de todosRepetidos a false, ya que encontré una clave con 1 aparicion
        }
    }
    c_intercambiar(c, aux); // Recupero la cola original

    while(!c_es_vacia(copiaInmutable)) free(c_desencolar(copiaInmutable)); // Libero todos los nodos de la copiaInmutable de la cola original
    free(copiaInmutable); // Libero la copiaInmutable
    free(aux); // Libero la cola auxiliar

    if (todosRepetidos) // Si todos los elementos estaban repetidos, quiere decir que nunca encolé nada en la cola resultado, por lo que alcanza con liberarla sin liberar sus nodos
    {
        free(res); // Libero la cola resultado
        return c_crear(); // Retorno una cola vacia, ya que todos los elementos de la original estaban repetidos
    }
    return res; // Si llego a esta linea es porque existe algun elemento no repetido en la original, por lo que retorno la cola resultado
}

int ejercicio4()
{
    int eleccion;
    do
    {
        limpiarConsola();
        srand(time(NULL));
        printf("\n------ Ejercicio 4 ------\n");
        
        Cola c = rellenarCola(-1);
        printf("\nCola : \n");
        c_mostrar(c);
        
        Cola res = c_ej4_colanorepetidos(c);
        printf("\nElementos no repetidos : \n");
        c_mostrar(res);

        eleccion = pedirEntero("\nSalir (0) | Continuar (1): ", 0, 1);
        
        if (c != NULL)
        {
            while (!c_es_vacia(c))
            {
                free(c_desencolar(c));
            }
            free(c);
        }

        if (res != NULL)
        {
            while (!c_es_vacia(res))
            {
                free(c_desencolar(res));
            }
            free(res);
        }

    } while (eleccion == 1);
    
    return 0;
}

//COMPLEJIDAD SIN EL TAD
/*contarApariciones() recorre los N elementos de la cola, por lo que tiene complejidad lineal.
Dentro de c_ej4_colanorepetidos() se usa c_ej2_copiar() de complejidad lineal  y dentro del primer while, que se ejecuta
N veces, por cada una se llama a contarApariciones(), lo que nos da O(N2). Finalmente, el ultimo while recorre
tambien N elementos. En suma, la complejidad total es de O(N)+O(N2)+O(N), es decir O(N2).*/

//COMPLEJIDAD SEGUN OPERACIONES DEL TAD
/*Arreglos: Siendo que desencolar tiene complejidad lineal, contarApariciones() sera O(N2), de modo que al ser llamada N veces en la funcion principal, resultara
    en una complejidad de O(N3).
Arreglos circulares: como todas las operaciones involucradas son de complejidad constante, el algoritmo continuara siendo O(N2).
Apuntadores: Dado que encolar es O(N), tenemos el mismo caso que en Arreglos, de manera que la complejidad sera O(N3).*/
