#include <stdio.h>
#include <stdlib.h>
#include "tp_conjuntos.h"
#include "tp_5_ejercicios.h"
#include "../libs/validaciones/headers/AUXILIARES.h"

int main()
{
    int eleccion = -1;
    while (eleccion != 0)
    {
        limpiarConsola();
        printf("\n------ Menu TP5: Conjuntos ------\n");
        printf("  2. Ejercicio 2: Operaciones sobre dos conjuntos\n");
        printf("  3. Ejercicio 3: Union e Interseccion\n");
        printf("  4. Ejercicio 4: Transitividad\n");
        printf("  5. Ejercicio 5: Diferencia simetrica\n");
        printf("  6. Ejercicio 6: Subconjunto propio\n");
        printf("  7. Ejercicio 7: Subconjuntos\n");
        printf("  8. Ejercicio 8: Igualdad de conjuntos\n");
        printf("  0. Salir\n");
        eleccion = pedirEntero("Seleccione el ejercicio a ejecutar [2-8] | [0] para salir: ", 0, 8);

        while (eleccion == 1)
        {
            printf("Entrada invalida. Ingrese otro entero\n");
            eleccion = pedirEntero("Seleccione el ejercicio a ejecutar [2-8] | [0] para salir: ", 0, 8);
        }

        switch (eleccion)
        {
        case 0:
            printf("\nSaliendo del programa...\n");
            break;
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
    return 0;
}
