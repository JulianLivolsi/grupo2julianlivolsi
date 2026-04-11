#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#include "TP_1_RECURSIVIDAD.h"
#include "../libs/validaciones/headers/AUXILIARES.h"

#define MAXSTRINGLENGTH 100
int main()
{
    int opcion;

    const char *tituloTP = "MENU TP 1 | RECURSIVIDAD";
    const char *ejercicios[] =
    {
        "Ejercicio 1: Palindromo",
        "Ejercicio 2: Producto de dos enteros",
        "Ejercicio 3: Serie Fibonacci",
        "Ejercicio 4: Cociente de dos enteros",
        "Ejercicio 5: Separador de miles",
        "Ejercicio 6: Delegacion de la mafia china",
        "Ejercicio 7: Senial digital",
        "Ejercicio 8: Subconjuntos que suman n",
        "Ejercicio 9: Divisible por 7",
        "Ejercicio 10: Explosion de numeros"
    };

    int cantidadEjercicios = sizeof(ejercicios) / sizeof(ejercicios[0]);
    do
    {
        opcion = mostrarMenu(tituloTP, ejercicios, cantidadEjercicios);
        switch (opcion)
        {
        case 0:
        {
            printf("Saliendo del programa...\n");
            break;
        }
        case 1:
        {
            system("cls");
            printf("\n>> EJERCICIO 1: VERIFICAR PALINDROMO <<\n");

            char cadena[MAXSTRINGLENGTH];
            pedirCadena("Ingrese una palabra o frase: ", cadena, MAXSTRINGLENGTH);

            if (palindromo(cadena))
            {
                printf("\n Resultado: %s ES palindromo.\n", cadena);
            }
            else
            {
                printf("\n Resultado: %s NO es palindromo.\n", cadena);
            }
            printf("\nPresione Enter para volver al menu...");
            getchar();
            break;
        }
        case 2:
        {
            system("cls");
            printf("\n>> EJERCICIO 2: PRODUCTO RECURSIVO DE DOS ENTEROS <<\n");

            int n, m;
            n = pedirEntero("Ingrese un primer entero (entre -5000 y 5000): ", -5000, 5000);
            m = pedirEntero("Ingrese un segundo entero (entre -5000 y 5000): ", -5000, 5000);

            printf("\nCalculando producto de manera recursiva...\n");
            int resultado = producto(m, n);
            printf("El resultado es = %d\n", resultado);

            printf("\nPresione Enter para volver al menu...");
            getchar();
            break;
        }
        case 3:
        {
            system("cls");
            printf("\n>> EJERCICIO 3: SERIE FIBONACCI <<\n");

            int fib = pedirEntero("Ingrese el numero del cual desea buscar su valor en la serie Fibonacci (minimo 0, maximo 46): ", 0, 46);
            int resultado = terminoSerieFibonacci(fib);
            printf("\nCalculando valor de Fibonacci...\n");
            printf("El numero correspondiente al puesto %d en la serie de fibonacci es: %d", fib, resultado);

            printf("\nPresione Enter para volver al menu...");
            getchar();
            break;
        }
        case 4:
        {
            system("cls");
            printf("\n>> EJERCICIO 4: COCIENTE RECURSIVO DE DOS ENTEROS <<\n");

            int n, m = pedirEntero("Ingrese el dividendo (Entre -10000 y 10000): ", -10000, 10000);

            do
            {
                n = pedirEntero("Ingrese el divisor (Entre -10000 y 10000): ", -10000, 10000);
                if (n == 0)
                {
                    printf("Error: El divisor no puede ser cero. Intentelo de nuevo.\n");
                }
            } while (n == 0);

            int d = pedirEntero("Ingrese la cantidad de decimales (entre 1 y 10): ", 1, 10);

            printf("\nCalculando division por restas sucesivas...\n");
            float resultado = division(m, n, d);
            printf("El resultado de %d / %d es: %.4f\n", m, n, resultado);

            printf("\nPresione Enter para volver al menu...");
            getchar();
            break;
        }
        case 5:
        {
            system("cls");
            printf("\n>> EJERCICIO 5: SEPARADOR DE MILES RECURSIVO <<\n");

            char numeroStr[100];
            int esValido;

            do
            {
                esValido = 1;
                printf("Ingrese un numero entero (sin puntos, comas ni espacios): ");

                scanf("%99s", numeroStr);
                limpiarBuffer();

                for (int i = 0; numeroStr[i] != '\0'; i++)
                {
                    if (!isdigit(numeroStr[i]))
                    {
                        printf("Error: Debe ingresar solamente numeros. Vuelva a intentarlo.\n");
                        esValido = 0;
                        break;
                    }
                }
            } while (!esValido);

            printf("\nAgregando separadores de miles...\n");
            char *resultado = agregarSeparadorMiles(numeroStr);

            printf("El numero formateado es: %s\n", resultado);
            printf("\nPresione Enter para volver al menu...");
            getchar();
            break;
        }
        case 6:
        {
            system("cls");
            printf("\n>> EJERCICIO 6: MAFIA CHINA POR NIVELES <<\n");
            int nivel = pedirEntero("Ingrese el nivel de la Mafia (entre 1 y 20): ", 1, 20);

            printf("\nGenerando vista frontal de la delegacion...\n\n");

            char *mafia = reunionMafia(nivel);

            printf("%s\n", mafia);
            free(mafia);

            printf("\nPresione Enter para volver al menu...");
            getchar();
            break;
        }
        case 7:
        {
            system("cls");
            printf("\n>> EJERCICIO 7: ONDA DIGITAL DE SENIALES <<\n");

            char seniales[100];
            int esValido;

            do
            {
                esValido = 1;
                printf("Ingrese la cadena de seniales (solo letras 'H' y 'L'): ");

                scanf("%99s", seniales);
                limpiarBuffer();

                for (int i = 0; seniales[i] != '\0'; i++)
                {
                    seniales[i] = toupper(seniales[i]);
                    if (seniales[i] != 'H' && seniales[i] != 'L')
                    {
                        printf("Error: La cadena solo puede contener las letras 'H' o 'L'. Vuelva a intentarlo.\n");
                        esValido = 0;
                        break;
                    }
                }
            } while (!esValido);

            printf("\nGenerando la onda digital para %s...\n\n", seniales);
            char *resultadoOnda = ondaDigital(seniales);
            printf("%s\n", resultadoOnda);
            printf("\nPresione Enter para volver al menu...");
            getchar();
            break;
        }
        case 8:
        {
            system("cls");
            printf("\n>> EJERCICIO 8: SUBCONJUNTOS QUE SUMAN N <<\n");

            // Limitamos a 15 elementos para evitar sobrecargar la memoria con la fórmula (1 << tamano)
            int tamano = pedirEntero("Ingrese la cantidad de elementos del conjunto (1 a 15): ", 1, 15);
            int conjunto[15];

            printf("\n--- Ingrese los elementos del conjunto ---\n");
            for (int i = 0; i < tamano; i++)
            {
                char msj[50];
                sprintf(msj, "Elemento %d: ", i + 1);
                conjunto[i] = pedirEntero(msj, -1000, 1000);
            }

            int n = pedirEntero("\nIngrese la suma objetivo (N): ", -10000, 10000);

            char *resultado = NULL;
            printf("\nBuscando subconjuntos...\n");
            subconjuntosQueSumanN(conjunto, tamano, n, &resultado);

            // Pequeño ajuste visual para la salida
            if (strcmp(resultado, "(ninguno)") != 0)
            {
                printf("R = [%s]\n", resultado);
            }
            else
            {
                printf("R = %s\n", resultado);
            }

            free(resultado); // Liberar memoria dinámica del output

            printf("\nPresione Enter para volver al menu...");
            getchar();
            break;
        }
        case 9:
        {
            system("cls");
            printf("\n>> EJERCICIO 9: DIVISIBLE POR 7 <<\n");

            int n = pedirEntero("Ingrese un numero entero para verificar si es divisible por 7: ", -1000000, 1000000);

            printf("\nAnalizando de forma recursiva...\n");
            if (divisiblePor7(n))
            {
                printf("Resultado: El numero %d ES divisible por 7.\n", n);
            }
            else
            {
                printf("Resultado: El numero %d NO es divisible por 7.\n", n);
            }

            printf("\nPresione Enter para volver al menu...");
            getchar();
            break;
        }
        case 10:
        {
            system("cls");
            printf("\n>> EJERCICIO 10: EXPLOSION DE NUMEROS <<\n");

            int n = pedirEntero("Ingrese el numero a explotar (N): ", 1, 100000);
            int b = pedirEntero("Ingrese la bomba (B) [Mayor a 1]: ", 2, 100000);

            printf("\nGenerando fragmentos...\n");
            int *fragmentos = explosion(n, b);

            printf("Resultado: ");
            // Recorrer hasta encontrar el centinela -1
            for (int i = 0; fragmentos[i] != -1; i++)
            {
                printf("%d ", fragmentos[i]);
            }
            printf("\n");

            free(fragmentos); // Liberar arreglo dinámico

            printf("\nPresione Enter para volver al menu...");
            getchar();
            break;
        }
        }
    } while (opcion != 0);

    return 0;
}