#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "tp_3_pilas.h"
#include "utilidades.h"

/*
4)  Construir un algoritmo que, utilizando el TAD Pila, permita convertir un número decimal pasado como 
    parámetro,a su correspondiente valor expresado en una base de 2 a 16 (hexadecimal).
    Determinar la complejidad algorítmica de la solución. 
    retorna el valor cambiado de base como un string (char*).  
    Si la base no esta entre 2 y 16 retorno el mismo numero recibido como string (char*).
*/
char *p_ej4_cambiarbase(int nrobasedecimal, int nrootrabase)
{
    char *resultado = (char *)malloc(50 * sizeof(char));
    resultado[0] = '\0';
    if (nrootrabase < 2 || nrootrabase > 16)
    {
        sprintf(resultado, "%d", nrobasedecimal);
        return resultado;
    }

    Pila numeroCambiado = p_crear();
    int resto;
    TipoElemento digito;

    while (nrobasedecimal >= nrootrabase)
    {
        resto = nrobasedecimal % nrootrabase;
        digito = te_crear(resto);
        p_apilar(numeroCambiado, digito);
        nrobasedecimal = nrobasedecimal / nrootrabase;
    }
    digito = te_crear(nrobasedecimal);
    p_apilar(numeroCambiado, digito);

    char temp[2];
    while (!p_es_vacia(numeroCambiado))
    {
        TipoElemento valor = p_desapilar(numeroCambiado);
        if (valor->clave >= 10)
        {
            temp[0] = 'A' + (valor->clave - 10);
        }
        else
        {
            temp[0] = '0' + valor->clave;
        }
        temp[1] = '\0';
        strcat(resultado, temp);
    }

    return resultado;
}

int ejercicio4()
{
    limpiarConsola();
    srand(time(NULL));
    printf("\n------ Ejercicio 4 ------\n");
    int numero = leer_entero("ingrese el numero a transformar[0-1023]: ", 0, 1023);
    int base = leer_entero("ingrese la base a la que desea transformar el numero (2-16): ", 0, 100);
    char *res = p_ej4_cambiarbase(numero, base);
    if (base < 2 || base > 16)
        printf("La base no es valida, se devolvio el mismo numero: %d\n", numero);
    else
        printf("El resultado es: %s\n", res);
    free(res);

    printf(
        "Cada comparacion y operacion individual es de complejidad O(1).\n"
        "La funcion tiene dos bucles while, cada uno de ellos de complejidad O(log n).\n"
        "\nEn el while (nrobasedecimal >= nrootrabase), el numero de iteraciones depende de cuantas veces se puede dividir el numero decimal entre la base.\n"
        "La cantidad de iteraciones es proporcional a log en base b de n, donde b es la base a la que se convierte, y n es el valor inicial del numero decimal.\n"
        "\nEn el while (p_es_vacia(numeroCambiado)), el numero de iteraciones es proporcional a la cantidad de restos apilados, que tambien es aproximadamente log n.\n"
        "\nEn conclusion, la complejidad algorítmica total es O(log n), es decir, tiene una complejidad logarítmica, siendo n el valor inicial del numero decimal que se convierte."
    );

    int eleccion = leer_entero("\nSalir (0) | Continuar (1): ", 0, 1);
    if (eleccion == 1)
        ejercicio4();
    else if (eleccion == 0)
        return 0;
}