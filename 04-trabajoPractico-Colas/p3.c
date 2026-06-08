#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tp_colas.h"

bool c_ej3_iguales(Cola c1, Cola c2) 
{
    if (c_es_vacia(c1) && c_es_vacia(c2)) return true; // Si ambas colas son vacias retorna true
    if (c_es_vacia(c1) && !c_es_vacia(c2) || !c_es_vacia(c1) && c_es_vacia(c2)) return false; // Si una sola de las colas es vacia retorna false

    Cola aux = c_crear(); // Creo una cola auxiliar
    bool iguales = true; // Creo una bandera para saber si son iguales

    int cantidadC1 = c_contarElementos(c1), cantidadC2 = c_contarElementos(c2); // Cuento los elementos de cada cola

    if (cantidadC1 == cantidadC2) // Si ambas colas tienen igual cantidad
    {
        while(!c_es_vacia(c1)) // Mientras c1 no sea vacia (podria usar cualquiera de las dos) desencolo ambas colas
        {
            TipoElemento te1 = c_desencolar(c1);
            TipoElemento te2 = c_desencolar(c2);
            if (te1->clave != te2->clave) // Si las claves de los elementos desencolados son distintas
            {
                iguales = false; // Actualizo la bandera a false
            }
            c_encolar(aux, te1); // PRIMERO encolo el elemento de la cola c1 en la cola auxiliar
            c_encolar(aux, te2); // SEGUNDO encolo el elemento de la cola c2 en la cola auxiliar
        }

        while(!c_es_vacia(aux)) // Mientras la cola auxiliar no sea vacia
        {
            TipoElemento te1 = c_desencolar(aux); // Creo un primer TipoElemento desencolando la auxiliar
            c_encolar(c1, te1); // Encolo ese elemento en la cola original c1, ya que entró primero, sale primero
            TipoElemento te2 = c_desencolar(aux); // Luego desencolo otro elemento de la cola auxiliar
            c_encolar(c2, te2); // Encolo el nuevo elemento en la cola original c2, entró segundo, sale segundo
        }

        free(aux); // Libero la cola auxiliar
        return iguales; // Retorno el valor de iguales
    }

    free(aux); // Si se llega a esta linea, ambas colas no tenian igual longitud por lo que primero libero la cola auxiliar
    return false; // Y retorno false
}

int ejercicio3()
{
    int eleccion;
    do
    {
        limpiarConsola();
        srand(time(NULL));
        printf("\n------ Ejercicio 3 - Son Iguales? ------\n");
        
        Cola c1 = rellenarCola(-1);
        Cola c2 = rellenarCola(-1);
        
        printf("\nCola 1: \n");
        c_mostrar(c1);
        printf("\nCola 2: \n");
        c_mostrar(c2);
        
        printf("\n--> Las Colas son %s\n", c_ej3_iguales(c1, c2) ? "IGUALES" : "DIFERENTES");

        eleccion = pedirEntero("\nSalir (0) | Continuar (1): ", 0, 1);
        
        if (c1 != NULL)
        {
            while (!c_es_vacia(c1))
            {
                free(c_desencolar(c1));
            }
            free(c1);
        }
        
        if (c2 != NULL)
        {
            while (!c_es_vacia(c2))
            {
                free(c_desencolar(c2));
            }
            free(c2);
        }

    } while (eleccion == 1);
    
    return 0;
}

//COMPLEJIDAD SIN TENER EN CUENTA EL TAD
/*El algoritmo usa 2 bucles while; el primero desencola los N elementos de la cola, siendo O(N); y el segundo
devuelve los elemetos a sus respectivas colas, siendo tambien O(N). Tenemos entonces un algoritmo con complejidad 
O(2N), es decir O(N) (Lineal).*/

//COMPLEJIDAD SEGUN IMPLEMENTACION DEL TAD

/*Arreglos: como desencolar() tiene complejidad O(N) y se lo usa en ambos while, cada uno tendra complejidad
cuadratica. Como resultado, el algoritmo tendria complejidad O(N2).
Arreglos Circulares: todas las operaciones involucradas son de complejidad constante, por lo que el algoritmo
continua teniendo complejidad lineal O(N).
Apuntadores: aqui, encolar tiene complejidad lineal y dado que se utiliza en cada bucle while, obtenemos una
complejidad del algoritmo O(N2).*/
