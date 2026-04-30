#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../headers/AUXILIARES.h"
#include "../../listas/headers/listas.h"

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

float pedirFloat(const char* mensaje, float min, float max){
    char buffer[100];
    char* endptr;
    float numero;
    while (1) {
        printf("%s", mensaje);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Error al leer entrada.\n");
            continue;
        }
        buffer[strcspn(buffer, "\n")] = 0;  
        numero = strtof(buffer, &endptr);  
        if (endptr != buffer && *endptr == '\0') {
            if (numero >= min && numero <= max) {
                return numero;  
            } else {
                printf("Número fuera de rango [%.2f - %.2f].\n", min, max);
            }
        } else {
            printf("Entrada inválida. Ingrese un número flotante.\n");
        }
    }
}

int mostrarMenu(const char *titulo, const char *opciones[], int cantidadOpciones)
{
    //system("cls"); "cls solo sirve para winsows"
    
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

void limpiarConsola()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Listas

Lista rellenarLista(int elementos)
{
    // llena una lista. el parametro elementos representa el largo de la lista
    // si elementos es pasado con el como -1 pregunta el largo al usuario
    if (elementos == -1)
    {
        elementos = pedirEntero("Cual es el largo de esta lista: ", 1, 100);
    }
    Lista resultado = l_crear();
    int aleatorio = pedirEntero("Quiere llenar la lista aleatoriamente? -> No(0) | Si(1): ", 0, 1);
    if (aleatorio == 1)
    {
        for (int j = 0; j < elementos; j++)
        {
            TipoElemento random = te_crear(rand() % 20);
            l_agregar(resultado, random);
        }
    }
    else
    {
        for (int j = 0; j < elementos; j++)
        {   
            char mensaje[100];
            sprintf(mensaje, "Ingrese el elemento %i: ", j + 1);
            int elem = pedirEntero(mensaje, -1000, 1000);
            TipoElemento elemento = te_crear(elem);
            l_agregar(resultado, elemento);
        }
    }
    return resultado;
}