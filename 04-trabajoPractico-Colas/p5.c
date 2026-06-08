#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tp_colas.h"

int contadorDivisionesExactas(Cola c, int clave) // Funcion auxiliar que cuenta la cantidad de divisiones exactas de una clave en una cola
{
    if (clave == 0) return 0;

    Cola aux = c_crear(); // Creo una cola auxiliar 
    int contador = 0; // Inicializo un contador en 0 | O(1)

    while(!c_es_vacia(c)) // Mientras la cola no sea vacia la desencolo | O(N)
    {
        TipoElemento te = c_desencolar(c); // | O(1)
        c_encolar(aux, te); // Encolo el elemento de la cola original en aux 

        if (te->clave % clave == 0) // Si la division es exacta | O(1)
        {
            contador++; // Sumo 1 al contador | O(1)
        }
    }
    c_intercambiar(c, aux); // Recupero la cola original 

    free(aux); // Libero la memoria de la cola auxiliar | O(1)
    return contador; // Devuelvo el contador | O(1)

}

Cola c_ej5_divisortotal(Cola c)
{
    if (c_es_vacia(c)) return c_crear(); // Si la cola es vacia retorno una cola vacia | O(1)

    Cola aux = c_crear(), res = c_crear(); // Creo colas auxiliar y resultado 
    Cola copiaInmutable = c_ej2_copiar(c); // Creo una copia de la cola original para realizar el llamado a la funcion auxiliar 

    int N = c_contarElementos(c); // Declaro un entero N que representa la cantidad de elementos de la cola 

    while(!c_es_vacia(c)) // Mientras la cola no sea vacia la desencolo | O(N)
    {
        TipoElemento te = c_desencolar(c); // | O(1)
        c_encolar(aux, te); // Encolo el elemento desencolado en aux 

        if (te->clave == 0) continue;

        // Declaro un entero que representa la cantidad de divisiones exactas, calculandolo con la funcion auxiliar
        int cantidadDivisiones = contadorDivisionesExactas(copiaInmutable, te->clave); // | O(N)

        if (cantidadDivisiones == N) // Si la cantidad de divisiones exactas es igual a la cantidad de elementos de la cola, tenemos un divisor total | O(1)
        {
            TipoElemento te_res = te_crear_con_valor(te->clave, (void*)1); // Creo un tipo elemento con la clave evaluada y como valor un true (entero casteado a puntero) | O(1)
            c_encolar(res, te_res); // Encolo el TipoElemento creado en la cola resultado 
        }
        else if (cantidadDivisiones >= (N/2.0)) // Si la cantidad de divisiones exactas es mayor o igual a la mitad de N, tenemos un divisor parcial | O(1)
        {
            TipoElemento te_res = te_crear_con_valor(te->clave, (void*)0); // Creo un tipo elemento igual que antes, pero con un false (entero casteado a puntero) | O(1)
            c_encolar(res, te_res); // Encolo el TipoElemento creado en la cola resultado 
        }
    }
    c_intercambiar(c, aux); // Recupero la cola original 

    while(!c_es_vacia(copiaInmutable)) free(c_desencolar(copiaInmutable)); // Libero los nodos de la copiaInmutable | O(N)
    free(copiaInmutable); // Libero la colaInmutable | O(1)
    free(aux); // Libero la cola auxiliar | O(1)

    if (c_es_vacia(res)) // Si resultados es vacia, quiere decir que no existen divisores totales ni parciales | O(1)
    {
        free(res); // Libero res (que no contiene ningun nodo) | O(1)
        return c_crear(); // Retorno una cola vacia | O(1)
    }

    return res; // Si se llega a esta linea es porque existe al menos un divisor total o parcial, por lo que retorno la cola resultado | O(1)

}

int ejercicio5()
{
    int eleccion;
    do
    {
        limpiarConsola();
        srand(time(NULL));
        printf("\n------ Ejercicio 5 ------\n");
        
        Cola c = rellenarCola(-1);
        printf("\nCola : \n");
        c_mostrar(c);
        
        Cola res = c_ej5_divisortotal(c); 
        printf("\nDivisores totales o parciales : \n");
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

/*COMPLEJIDAD SIN EL TAD
contadorDivisionesExactas() recorre N elementos, por lo que es O(N). c_ej5_divisortotal recorre N elementos y por cada uno llama a contadorDivisionesExactas()
de modo que el algoritmo tiene complejidad cuadratica O(N2).

COMPLEJIDAD SEGUN IMPLEMENTACION DEL TAD
Arreglos: como desencolar es O(N), contadorDivisionesExactas() sera O(N2); por lo cual c_ej5_divisortotal sera O(N3).
Arreglos circulares: dado que las operaciones son de complejidad constante, el algoritmo continua siendo O(N2).
Apuntadores: encolar es de complejidad lineal, asi, de la misma manera que en arreglos, c_ej5_divisortotal sera O(N3).*/
