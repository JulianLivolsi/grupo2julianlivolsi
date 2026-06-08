#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tp_colas.h"

// A
bool c_ej2_existeclave(Cola c, int clave)
{
    if (c_es_vacia(c)) return false; // Si la cola es vacia, no tiene claves por lo tanto no existe ninguna clave dentro

    Cola aux = c_crear(); // Creamos una cola auxiliar
    bool resultado = false; // Creamos una bandera para ver si encontramos la clave

    while(!c_es_vacia(c)) // Mientras la cola no sea vacia la vamos desencolando
    {
        TipoElemento te = c_desencolar(c);
        c_encolar(aux, te); // Vamos guardando los elementos en la cola auxiliar

        if (te->clave == clave) // Si la clave del TipoElemento desencolado coincide con la que buscamos
        {
            resultado = true; // Actualizamos la bandera a true
        }
    }
    c_intercambiar(c, aux); // Recuperamos la cola original desde la auxiliar

    free(aux); // Liberamos la cola auxiliar
    return resultado; // Retornamos el valor de resultado (false por defecto, true si se actualizó la bandera por coincidencia de clave)
}

// B
Cola c_ej2_colarelemento(Cola c, int posicionordinal, TipoElemento X)
{
    if (c_es_vacia(c)) // Si la cola es vacia
    {
        if (posicionordinal == 1) // Si se desea insertar en la primera posicion
        {
            Cola res = c_crear(); // Se crea la cola res
            c_encolar(res, X); // Se encola el elemento X
            return res; // Se retorna res
        }
        return c; // Para cualquier otra posicion se retorna la cola original
    }

    Cola aux = c_crear(), res = c_crear(); // Creamos colas auxiliares y res
    int posicion = 1; // Inicializamos un contador de posicion en 1
    bool insertado = false; // Creamos una bandera para identificar si se realizó la insercion de un elemento o no

    while(!c_es_vacia(c)) // Mientras c no este vacia la vamos desencolando
    {
        TipoElemento te = c_desencolar(c);
        
        if (posicion == posicionordinal && !insertado) // Si el contador posicion coincide con la posicion donde se desea insertar, y no se inserto nada aun
        {
            c_encolar(res, te_crear_con_valor(X->clave, X->valor)); // Se encola en res un TipoElemento copia de X
            insertado = true; // Se modifica la bandera
            posicion++; // Se avanza una posicion
        }
        c_encolar(aux, te); // Luego se encola el TipoElemento de c en aux
        c_encolar(res, te_crear_con_valor(te->clave, te->valor)); // Se encola una copia del TipoElemento de c en res
        posicion++; // Se avanza una posicion
    }
    if (posicion == posicionordinal && !insertado) // Si las posiciones coinciden al finalizar el while, es porque se desea insertar al final de la cola
    {
        c_encolar(res, te_crear_con_valor(X->clave, X->valor)); // Se encola en res un TipoElemento copia de X
        insertado = true; // Se modifica la bandera
    }

    c_intercambiar(c, aux); // Luego se recupera la cola original 

    free(aux); // Se libera la memoria de la cola auxiliar

    if (!insertado) // Si no se inserto ningun valor en la cola original
    {
        while(!c_es_vacia(res)) free(c_desencolar(res)); // Se liberan todos los nodos de la cola res
        free(res); // Luego se libera la cola res
        return c; // Se retorna la cola original
    }

    return res; // Si se llega a esta linea, es porque se insertó un elemento por lo tanto retorno la cola res
}

// C

Cola c_ej2_sacarelemento(Cola c, int clave)
{
    if (c_es_vacia(c)) return c; // Si la cola es vacia retorno la original

    Cola aux = c_crear(), res = c_crear(); // Creo colas auxiliar y resultado
    bool eliminado = false; // Creo bandera para detectar si se elimina un elemento

    while(!c_es_vacia(c)) // Mientras c no es vacia la desencolo
    {
        TipoElemento te = c_desencolar(c);

        c_encolar(aux, te); // Encolo el elemento de c en aux
        if (te->clave == clave) eliminado = true; // Si la clave del TipoElemento desencolado coincide con la que quiero eliminar, actualizo la bandera
        else // Si no coincide
        {
            TipoElemento te_res = te_crear_con_valor(te->clave, te->valor); // Creo un TipoElemento copia del desencolado
            c_encolar(res, te_res); // Encolo la copia en la cola resultado
        }
    }
    c_intercambiar(c, aux); // Recupero la cola original

    free(aux); // Libero la memoria de la cola auxiliar
    if (!eliminado) // Si no se elimino ningun elemento
    {
        while(!c_es_vacia(res)) free(c_desencolar(res)); //Libero la memoria de los nodos de la cola resultado
        free(res); // Libero la memoria de la cola resultado
        return c; // Retorno la cola original
    }
    return res; // Si se llega a esta linea es porque elimine algun elemento, por lo que retorno la cola resultado
}

// D

int c_ej2_contarelementos(Cola c)
{
    if (c_es_vacia(c)) return 0; // Si la cola es vacia no contiene elementos por lo que retorno 0

    Cola aux = c_crear(); // Creo una cola auxiliar
    int resultado = 0; // Inicializo un contador en 0

    while(!c_es_vacia(c)) // Mientras c no sea vacia la desencolo
    {
        TipoElemento te = c_desencolar(c);
        c_encolar(aux, te); // Encolo el elemento de c en aux
        resultado++; // Sumo 1 al resultado
    }
    c_intercambiar(c, aux); // Recupero la cola original

    free(aux); // Libero la memoria de la cola auxiliar
    return resultado; // Retorno el contador
}

// E

Cola c_ej2_copiar(Cola c) 
{
    if (c_es_vacia(c)) return c_crear(); // Si la cola es vacia retornamos una cola vacia | O(1)

    Cola aux = c_crear(), copia = c_crear(); // Creamos las colas auxiliar y copia | O(1)

    while(!c_es_vacia(c)) // Mientras la cola original no sea vacia la desencolamos | O(N)
    {
        TipoElemento te = c_desencolar(c); // | O(1)
        c_encolar(aux, te); // Encolamos el elemento de c en aux | O(1)
        TipoElemento te_copia = te_crear_con_valor(te->clave, te->valor); // Creamos una copia del TipoElemento de c | O(1)
        c_encolar(copia, te_copia); // Encolamos la copia del TipoElemento en la cola copia | O(1)
    }
    c_intercambiar(c, aux); // Recuperamos la cola original | O(N)

    free(aux); // Liberamos la cola auxiliar | O(1)
    return copia; // Retornamos la copia | O(1)

    // Se determina la complejidad ya que se llama a la funcion en ejercicios posteriores donde se debe determinar la complejidad.
    // Complejidad algoritmica O(N)
}

// F

Cola c_ej2_invertir(Cola c)
{
    if (c_es_vacia(c)) return c_crear(); // Si la cola es vacia retornamos una cola vacia
    Cola Caux = c_crear(), Cres = c_crear(); // Creamos una cola auxiliar y una respuesta
    Pila Paux = p_crear(); // Creamos una pila auxiliar

    while(!c_es_vacia(c)) // Mientras la cola no sea vacia la desencolamos
    {
        TipoElemento te = c_desencolar(c);
        c_encolar(Caux, te); // Encolamos el elemento de c en aux

        TipoElemento te_pila = te_crear_con_valor(te->clave, te->valor); // Creamos una copia del TipoElemento desencolado
        p_apilar(Paux, te_pila); // Apilamos la copia en una pila auxiliar
    }
    c_intercambiar(c, Caux); // Recuperamos la cola original

    while(!p_es_vacia(Paux)) // Mientras la pila auxiliar no sea vacia la desapilamos
    {
        TipoElemento te = p_desapilar(Paux);
        c_encolar(Cres, te); // Encolamos el elemento desapilado en la cola respuesta
    }

    free(Paux); free(Caux); // Liberamos la pila y cola auxiliar

    return Cres; // Retornamos la cola respuesta
}

void ejercicio2()
{
    limpiarConsola();
    srand(time(NULL));
    printf("\n------ Ejercicio 2 ------\n");

    Cola cola = rellenarCola(-1);
    c_mostrar(cola);

    int eleccion = -1;
    while (eleccion != 0)
    {
        eleccion = pedirEntero("\n\nSeleccione el ejercicio: A[Ingrese 1], B[Ingrese 2], C[Ingrese 3], D[Ingrese 4], E[Ingrese 5], F[Ingrese 6], (Ingrese 0 para salir): ", 0, 6);
        Cola auxiliar = NULL;
        Cola NuevaCola = NULL;
        int clave;

        if (eleccion != 0) auxiliar = colaClon(cola);

        switch (eleccion)
        {
        case 1:
            limpiarConsola();
            printf("\nEjercicio A: Informar si un elemento dado se encuentra en la cola:\n");
            printf("\nCola original: \n");
            c_mostrar(auxiliar);
            printf("\n");
            clave = pedirEntero("Ingrese una clave a buscar: ", -1000, 1000);
            if (c_ej2_existeclave(auxiliar, clave))
            {
                printf("\nLa clave ingresada EXISTE dentro de la cola.");
            }
            else
            {
                printf("\nLa clave ingresada NO EXISTE dentro de la cola.");
            }
            break;
        case 2:
            limpiarConsola();
            printf("\nEjercicio B: Agregar un nuevo elemento en una posición dada (colarse):\n");
            printf("\nCola original: \n");
            c_mostrar(auxiliar);
            int posicion = pedirEntero("Ingrese la posicion en donde insertar (empezando desde 1): ", 1, c_contarElementos(cola) + 1);
            clave = pedirEntero("Ingrese la nueva clave: ", -1000, 1000);
            TipoElemento x = te_crear(clave);
            NuevaCola = c_ej2_colarelemento(auxiliar, posicion, x);
            printf("\nNueva Cola: \n");
            c_mostrar(NuevaCola);
            break;
        case 3:
            limpiarConsola();
            printf("\nEjercicio C: Dado un elemento sacarlo de la cola todas las veces que aparezca:\n");
            printf("\nCola original:\n");
            c_mostrar(auxiliar);
            clave = pedirEntero("Ingrese la clave a eliminar: ", -1000, 1000);
            NuevaCola = c_ej2_sacarelemento(auxiliar, clave);
            printf("\nNueva Cola:\n");
            c_mostrar(NuevaCola);
            break;
        case 4:
            limpiarConsola();
            printf("\nEjercicio D: Contar los elementos de la cola \n");
            printf("\nCola original: \n");
            c_mostrar(auxiliar);
            int cantidad = c_ej2_contarelementos(auxiliar);
            printf("\nLa Cola tiene %d elementos:\n",cantidad);
            break;
        case 5:
            limpiarConsola();
            printf("\nEjercicio E: Realizar una copia de una cola \n");
            printf("\nCola original: \n");
            c_mostrar(auxiliar);
            printf("\n");
            NuevaCola = c_ej2_copiar(auxiliar);
            printf("\nCola copiada: \n");
            c_mostrar(NuevaCola);
            break;
        case 6:
            limpiarConsola();
            printf("\nEjercicio F: Invertir el contenido de una cola \n");
            printf("\nCola original\n");
            c_mostrar(auxiliar);
            printf("\n");
            NuevaCola = c_ej2_invertir(auxiliar);
            printf("\nCola invertida:\n");
            c_mostrar(NuevaCola);
            break;
        }
        if (auxiliar != NULL)
        {
            while(!c_es_vacia(auxiliar)) free(c_desencolar(NuevaCola));
            free(NuevaCola);
        }
    }
    if (cola != NULL)
    {
        while (!c_es_vacia(cola)) free(c_desencolar(cola));
        free(cola);
    }

    
}