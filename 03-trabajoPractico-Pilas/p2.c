#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tp_pilas.h"

bool p_ej2_existeclave(Pila p, int clave)
{
    if (p_es_vacia(p))
    {
        printf("PILA VACIA !!! \n");
        return false;
    }
    Pila Paux = p_crear();
    TipoElemento X = te_crear(0);
    bool result = false;

    // Recorro la pila desapilandola y pasandola al auxiliar
    while (p_es_vacia(p) != true)
    {
        X = p_desapilar(p);
        p_apilar(Paux, X);

        if (X->clave == clave)
        {
            result = true;
        }
    }
    // Recorro la pila auxiliar para pasarla a la original
    p_intercambiar(p, Paux);

    return result;
}

Pila p_ej2_colocarelemento(Pila p, int posicionordinal, TipoElemento x)
{
    if (p_es_vacia(p))
    {
        Pila res = p_crear();
        p_apilar(res, x);
        return res;
    }

    if (p_es_llena(p))
    {
        printf("LA PILA ESTA LLENA. NO SE PUEDEN COLOCAR MAS ELEMENTOS.\n");
        return p;
    }

    Pila NuevaPila = p_crear();
    Pila Paux = p_crear();
    Pila duplicadoOriginal = p_crear();

    int cantidadElementos = 0;
    while (p_es_vacia(p) != true)
    {
        TipoElemento element = p_desapilar(p);
        p_apilar(Paux, element);
        cantidadElementos++;
    }
    p_intercambiar(p, Paux);

    if (posicionordinal > cantidadElementos + 1 || posicionordinal < 1)
    {
        printf("Posicion fuera de rango\n");
        return p;
    }

    int posicion = 1;
    while (p_es_vacia(p) != true)
    {
        TipoElemento element = p_desapilar(p);
        p_apilar(duplicadoOriginal, element); // Guarda copia para restaurar la pila original
        if (posicion == posicionordinal)
        {
            p_apilar(Paux, x);       // Inserta el nuevo elemento primero
            p_apilar(Paux, element); // Luego el que ya estaba en esa posición
        }
        else
        {
            p_apilar(Paux, element); // En las demás posiciones, solo apila lo que estaba
        }
        posicion++;
    }

    p_intercambiar(p, duplicadoOriginal);
    p_intercambiar(NuevaPila, Paux);

    return NuevaPila;
}

Pila p_ej2_eliminarclave(Pila p, int clave)
{
    if (p_es_vacia(p))
    {
        return p_crear();
    }

    Pila NuevaPila = p_crear();
    Pila Paux = p_crear();
    Pila duplicadoOriginal = p_crear();
    bool ElementoUbicado = false;

    while (p_es_vacia(p) != true)
    {
        TipoElemento element = p_desapilar(p);
        p_apilar(duplicadoOriginal, element);
        if (element->clave == clave && !ElementoUbicado)
        {
            ElementoUbicado = true;
        }
        else
        {
            p_apilar(Paux, element);
        }
    }
    p_intercambiar(p, duplicadoOriginal);
    p_intercambiar(NuevaPila, Paux);

    if (!ElementoUbicado)
    {
        printf("\nNo se encontró la clave %d en la pila.\n", clave);
        return p;
    }
    else
    {
        return NuevaPila;
    }
}

Pila p_ej2_intercambiarposiciones(Pila p, int pos1, int pos2)
{
    if (p_es_vacia(p))
    {
        printf("PILA VACIA !!! \n");
        return p_crear();
    }

    if (pos1 == pos2)
    {
        return p;
    }

    Pila NuevaPila = p_crear();
    Pila Paux = p_crear();
    Pila duplicadoOriginal = p_crear();

    int cantidadElementos = 0;
    while (p_es_vacia(p) != true)
    {
        TipoElemento element = p_desapilar(p);
        p_apilar(Paux, element);
        cantidadElementos++;
    }
    p_intercambiar(p, Paux);

    if ((pos1 > cantidadElementos || pos1 < 1) || (pos2 > cantidadElementos || pos2 < 1))
    {
        printf("Posicion fuera de rango\n");
        return p;
    }

    int contador = 1;
    int valorDePo1 = -1, valorDePo2 = -1;
    while (p_es_vacia(p) != true)
    {
        TipoElemento element = p_desapilar(p);
        if (contador == pos1)
            valorDePo1 = element->clave;
        if (contador == pos2)
            valorDePo2 = element->clave;
        p_apilar(Paux, element);
        contador++;
    }
    p_intercambiar(p, Paux);

    contador = 1;
    while (p_es_vacia(p) != true)
    {
        TipoElemento element = p_desapilar(p);
        p_apilar(duplicadoOriginal, element);
        if (contador == pos1)
        {
            p_apilar(Paux, te_crear(valorDePo2));
            // element->clave = valorDePo2;
            // element = te_crear(valorDePo2);
        }
        else if (contador == pos2)
        {
            p_apilar(Paux, te_crear(valorDePo1));
            // element->clave = valorDePo1;
            // element = te_crear(valorDePo1);
        }
        else
        {
            p_apilar(Paux, element);
        }
        contador++;
    }
    p_intercambiar(p, duplicadoOriginal);
    p_intercambiar(NuevaPila, Paux);

    return NuevaPila;
}

Pila p_ej2_duplicar(Pila p)
{
    if (p_es_vacia(p))
    {
        printf("PILA VACIA !!! \n");
        return p_crear();
    }

    int tamanio = p_tamanio(p);

    if (tamanio * 2 > 10)
    {
        printf("LA PILA NO SE PUEDE DUPLICAR PORQUE EXCEDE EL TAMANIO PERMITIDO EN EL TAD(10).\n");
        return p;
    }

    Pila Paux = p_crear();
    Pila NuevaPila = p_crear();
    Pila duplicado = p_crear();
    Pila duplicadoFinal = p_crear();

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
        p_apilar(p, element);
        p_apilar(NuevaPila, copia1);
        p_apilar(duplicado, copia2);
    }

    p_intercambiar(duplicadoFinal, duplicado);
    while (p_es_vacia(duplicadoFinal) != true)
    {
        p_apilar(NuevaPila, p_desapilar(duplicadoFinal));
    }

    return NuevaPila;
}

int p_ej2_cantidadelementos(Pila p)
{
    if (p_es_vacia(p))
    {
        return 0;
    }

    Pila Paux = p_crear();
    int cantidadElementos = 0;

    while (p_es_vacia(p) != true)
    {
        TipoElemento element = p_desapilar(p);
        p_apilar(Paux, element);
        cantidadElementos++;
    }
    p_intercambiar(p, Paux);

    return cantidadElementos;
}

void ejercicio2()
{
    limpiarConsola();
    srand(time(NULL));
    printf("\n------ Ejercicio 2 ------\n");

    Pila pila = rellenarPila(-1);
    p_mostrar(pila);

    int eleccion = -1;
    while (eleccion != 0)
    {
        eleccion = pedirEntero("\n\nSeleccione el ejercicio: A[Eliga 1], B[Eliga 2], C[Eliga 3], D[Eliga 4], E[Eliga 5], F[Eliga 6], (Eliga 0 para salir): ", 0, 6);
        Pila auxiliar = p_crear();
        Pila NuevaPila = p_crear();
        int clave;
        switch (eleccion)
        {
        case 1:
            limpiarConsola();
            auxiliar = pilaClon(pila);
            printf("\nEjercicio A: Buscar una clave y determinar si existe en la Pila (sin perder la pila):\n");
            printf("\nPila origina: \n");
            p_mostrar(auxiliar);
            printf("\n");
            clave = pedirEntero("Ingrese una clave a buscar: ", -1000, 1000);
            if (p_ej2_existeclave(auxiliar, clave))
            {
                printf("\nLa clave ingresada EXISTE dentro de la pila.");
            }
            else
            {
                printf("\nLa clave ingresada NO EXISTE dentro de la pila.");
            }
            break;
        case 2:
            limpiarConsola();
            auxiliar = pilaClon(pila);
            printf("\nEjercicio B: Colocar en una posicion ordinal determinada, recibida por parámetro, un nuevo elemento (Insertar un elemento nuevo):\n");
            printf("\nPila original\n");
            p_mostrar(auxiliar);
            int posicion = pedirEntero("Ingrese la posicion en donde insertar (empezando desde 1): ", 1, p_tamanio(pila) + 1);
            clave = pedirEntero("Ingrese la nueva clave: ", -1000, 1000);
            TipoElemento x = te_crear(clave);
            NuevaPila = p_ej2_colocarelemento(auxiliar, posicion, x);
            printf("\nNueva Pila:\n");
            p_mostrar(NuevaPila);
            break;
        case 3:
            limpiarConsola();
            auxiliar = pilaClon(pila);
            printf("\nEjercicio C: Eliminar de una pila un elemento dado (primera ocurrencia encontrada por la clave):\n");
            printf("\nPila Oroginal:\n");
            p_mostrar(auxiliar);
            clave = pedirEntero("Ingrese la clave a eliminar: ", -1000, 1000);
            NuevaPila = p_ej2_eliminarclave(auxiliar, clave);
            printf("\nNueva Pila:\n");
            p_mostrar(NuevaPila);
            break;
        case 4:
            limpiarConsola();
            auxiliar = pilaClon(pila);
            printf("\nEjercicio D: Intercambiar los valores de 2 posiciones ordinales de la pila, por ejemplo la 2da con la 4ta. \n");
            printf("\nPila original: \n");
            p_mostrar(auxiliar);
            if (p_es_vacia(auxiliar)){
                printf("La pila esta vacia NO se puede realizar un intercambio\n");
                break;
            }
            int posicion1 = pedirEntero("Ingrese la primera posicion a intercambiar(empezando desde 1): ", 1, p_tamanio(pila));
            int posicion2 = pedirEntero("Ingrese la segunda posicion a intercambiar(empezando desde 1): ", 1, p_tamanio(pila));
            NuevaPila = p_ej2_intercambiarposiciones(auxiliar, posicion1, posicion2);
            p_mostrar(NuevaPila);
            break;
        case 5:
            limpiarConsola();
            auxiliar = pilaClon(pila);
            printf("\nEjercicio E: Duplicar el contenido de una pila. \n");
            printf("\nPila original:\n");
            p_mostrar(auxiliar);
            if (p_es_vacia(auxiliar)){
                printf("\nPila duplicada:\n");
                p_mostrar(auxiliar);
                break;
            }
            printf("\n");
            NuevaPila = p_ej2_duplicar(auxiliar);// que debe hacer la funcion duplicar????
            printf("\nPila duplicada:\n");
            p_mostrar(NuevaPila);
            break;
        case 6:
            limpiarConsola();
            auxiliar = pilaClon(pila);
            printf("\nEjercicio F: Contar los elementos de la pila. \n");
            printf("\nPila original\n");
            p_mostrar(auxiliar);
            printf("\n");
            int cantidadElementos = p_ej2_cantidadelementos(auxiliar);
            printf("La pila tiene un total de %d elementos", cantidadElementos);
            break;
        }
    }
}
