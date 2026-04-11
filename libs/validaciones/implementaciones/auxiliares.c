#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../headers/AUXILIARES.h"

int pedirEntero(char mensaje[], int min, int max)
{
    int valor, exito, esValido;
    do
    {
        printf("%s", mensaje);
        exito = scanf("%d", &valor);
        char siguiente = getchar();

        esValido = (exito == 1 && siguiente == '\n');

        if (!esValido)
        {
            while (getchar() != '\n');
            printf("Error, ingrese un numero entero valido.\n");
        }
        else 
        {
            if (valor < min || valor > max)
            {
                printf("Error: El valor debe estar entre %d y %d\n", min, max);
                esValido = 0; 
            }
        }
    } while (!esValido);

    return valor;
}

int mostrarMenu(const char *titulo, const char *opciones[], int cantidadOpciones)
{
    system("cls");
    
    // Imprimimos el título dinámico
    printf("-- %s --\n\n", titulo);
    
    // Recorremos el arreglo de opciones
    for (int i = 0; i < cantidadOpciones; i++)
    {
        printf("%d. %s\n", i + 1, opciones[i]);
    }
    
    printf("0. Salir\n\n");
    
    // El máximo dinámico ahora es la cantidad de opciones
    return pedirEntero("Ingrese una opcion: ", 0, cantidadOpciones);
}

void limpiarBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void pedirCadena(char mensaje[], char buffer[], int max_len) 
{
    int esValido;
    do {
        esValido = 1; 
        printf("%s", mensaje);

        if (fgets(buffer, max_len, stdin) != NULL) 
        {
            int len = strlen(buffer);

            if (len > 0 && buffer[len - 1] == '\n') {
                buffer[len - 1] = '\0';
                len--; 
            } else {
                while (getchar() != '\n'); 
            }

            if (len == 0) {
                printf("Error: No ingreso ninguna palabra.\n");
                esValido = 0;
                continue; 
            }

            for (int i = 0; i < len; i++) {
                if (!isalpha(buffer[i]) && !isspace(buffer[i])) {
                    printf("Error: Solo se permiten letras y espacios (sin numeros ni simbolos).\n");
                    esValido = 0;
                    break; 
                }
            }
        } 
        else 
        {
            esValido = 0;
        }
    } while (!esValido);
}