#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#include "tp_2_listas.h"

void hacerPolinomio(Lista list)
{
    int tamanio = 0;
    printf("Ingrese el tamano que tendra la lista: ");
    int valido = scanf("%d", &tamanio);
    while (valido != 1 || (tamanio< 1 || tamanio>100)) {
        printf("Tamaño inválido. Ingrese un número entre 1 y 100:\n");
        while (getchar() != '\n'); 
        valido = scanf("%d", &tamanio); 
    }

    for (int i = 0; i < tamanio;i++) {
        int elemento;
        printf("\nIngrese el elemento %d en la lista: ", i+1);
        while (scanf("%d", &elemento) != 1){
            printf("Ingresaste algo que no es un numero. Por favor, ingrese un numero.\n");
            while (getchar() != '\n');
        }
        TipoElemento elementoDefinitivo = te_crear(elemento);
        l_agregar(list, elementoDefinitivo);
    }
}

float evaluarPolinomio(Lista list, float x)
{
    Iterador it1 = iterador(list);
    int grado = l_longitud(list) - 1;
    float suma = 0, operacion = 0;
    while (hay_siguiente(it1))
    {
        TipoElemento elem1 = siguiente(it1);
        operacion = elem1->clave * (pow(x, grado));
        suma += operacion;
        grado--;
    }
    return suma;
}

Lista calcularRango(Lista list, double x, double y, double sumando)
{
    float suma, operacion;
    Lista resultado = l_crear();
    for (float i = x; i <= y; i += sumando)
    {
        int grado = l_longitud(list) - 1;
        Iterador it1 = iterador(list);
        suma = 0.0;
        while (hay_siguiente(it1))
        {
            TipoElemento elem1 = siguiente(it1);
            operacion = (elem1->clave) * (pow(i, grado));
            suma += operacion;
            grado--;
        }

        float *valor_suma = malloc(sizeof(float));
        *valor_suma = suma;
        TipoElemento nuevo = te_crear_con_valor(0, valor_suma);
        l_agregar(resultado, nuevo);
    }
    return resultado;
}

int ejercicio5()
{
    limpiarConsola();
    printf("\n------ Ejercicio 5: polinomio ------\n");
    printf("Ingrese en la lista los coeficientes del polinomio (desde el grado mas alto hasta x^0) \n-> ");
    Lista lista1 = l_crear();
    hacerPolinomio(lista1);

    Iterador indexlista = iterador(lista1);
    int grado = l_longitud(lista1)-1; 
    bool primero = true;

    while (hay_siguiente(indexlista)) {
        TipoElemento elem = siguiente(indexlista);

        if (!primero && elem->clave>=0) {
            printf("+");
        }
        
        if (grado == 0) {
            printf("%i", elem->clave);
        } else if (grado == 1) {
            printf("%i(x)", elem->clave);
        } else {
            printf("%i(x^%i)", elem->clave, grado);
        }
    
        grado--;
        primero = false;
    }

    printf("\n### Seleccione una opcion ###");
    while (1)
    {
        int tipo = pedirEntero("\nHallar un Valor del polinomio [0] | Hallar Valores en un rango [1]: ", 0, 1);
        if (tipo == 0) {
            float valorDeX = pedirFloat("\nIngrese el valor de x: ", -1000.00, 1000.00); 
            float resultado = evaluarPolinomio(lista1,valorDeX);
            printf("\nEl resultado de usar como valor 'x' a %.3f en el polinomio es de: %.3f",valorDeX,resultado);

        } else if (tipo == 1) {
            float cotaInf = pedirFloat("\nIngrese la cota inferior del rango: ", -2000.0, 1999.0);
            float cotaSup = pedirFloat("Ingrese la cota superior del rango: ", -1999.0, 2000.0);
            float pazo = pedirFloat("Ingrese el sumando de los valores: ", 0.01, 1000.0);
            printf("\nvalores desde %.2f hasta %.2f de a paso %.2f son\n-> ", cotaInf, cotaSup, pazo);
            Lista valores = calcularRango(lista1, cotaInf, cotaSup, pazo);
            
            Iterador itValores = iterador(valores);
            float xActual = cotaInf;
            while (hay_siguiente(itValores)) {
                TipoElemento elem = siguiente(itValores);
                float *valor = (float *)elem->valor;
                printf("f(%.2f) = %.3f\n", xActual, *valor);
                xActual += pazo;
            }
        }
        int cont = pedirEntero("\nContinuar con el mismo polinomio(0) | Seguir(1): ", 0, 1);
        if (cont == 1)
            break;
    }
    int continuar = pedirEntero("\nSalir (0) | Ingresar otro Polinomio (1): ",0,1);
    if (continuar == 1)
        ejercicio5();
    else
        return 0;
}