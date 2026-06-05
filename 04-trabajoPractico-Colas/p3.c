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