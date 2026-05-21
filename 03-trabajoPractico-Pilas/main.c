#include <stdio.h>
#include <stdlib.h>
#include "tp_pilas.h"
#include "tp_3_ejercicios.h"

int main()
{
    int eleccion = -1;
    while (eleccion != 0)
    {
        limpiarConsola();
        printf("\n------ Menu TP3: Pilas ------\n");
        eleccion = pedirEntero("Seleccione el ejercicio a ejecutar [2-8] | [0] para salir: ", 0, 8);
        while (eleccion == 1)
        {
            printf("Entrada inválida. Ingrese otro entero\n");
            eleccion = pedirEntero("Seleccione el ejercicio a ejecutar [2-8] | [0] para salir): ", 0, 8);
        }
        if (eleccion == 0)
        {
            printf("\nSaliendo del programa...\n");
        }
        else
        {
            switch (eleccion)
            {
            case 2:
                ejercicio2();
                break;
            case 3:
                ejercicio3();
                break;
            case 4:
                ejercicio4();
                break;
            case 5:
                ejercicio5();
                break;
            case 6:
                ejercicio6();
                break;
            case 7:
                ejercicio7();
                break;
            case 8:
                ejercicio8();
                break;
            }
        }
    }
    return 0;
}