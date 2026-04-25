#include <stdio.h>
#include <stdlib.h>
#include "tp_2_listas.h"
#include "tp_2_ejercicios.h"


int main()
{
    int eleccion = -1;
    while (eleccion != 0)
    {
        limpiarConsola();
        printf("\n------ Menu TP2: Listas ------\n");
        eleccion = pedirEntero("Seleccione el ejercicio a ejecutar [2-6] | [0] para salir: ", 0, 6);
        while (eleccion == 1)
        {
            printf("Entrada inválida. Ingrese otro entero\n");
            eleccion = pedirEntero("Seleccione el ejercicio a ejecutar [2-6] | [0] para salir): ", 0, 6);
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
            }
        }
    }
    return 0;
}