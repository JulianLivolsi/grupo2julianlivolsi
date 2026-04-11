#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#include "TP_1_RECURSIVIDAD.h"
#include "../libs/validaciones/headers/AUXILIARES.h"

// EJERCICIO 1

bool palindromo(char * cadena)
{
    int len = strlen(cadena);

    if (len <= 1) return true; // Caso base, cadena vacia o un solo caracter
    if(cadena[0] != cadena[len - 1]) return false; // Comparamos primero con el ultimo
    
	char backup = cadena[len -1]; // Guardamos la ultima letra
	cadena[len - 1] = '\0'; // La "borramos" temporalmente

    bool resultado = palindromo(cadena + 1); // Llamada recursiva, empezamos desde el segundo caracter

	cadena[len - 1] = backup; // Restauramos la letra "borrada" para no destruir la cadena original

	return resultado;
}

// EJERCICIO 2

int producto(int m, int n)
{
    if (n < 0)
        return -producto(m, -n);
    if (n == 0)
        return 0;
    return m + producto(m, n - 1);
}

// EJERCICIO 3

int terminoSerieFibonacci(int k)
{
	if (k == 0) // Caso base
        return 0;
    if (k == 1) // Caso base
        return 1;
    return terminoSerieFibonacci(k - 1) + terminoSerieFibonacci(k - 2); // Caso recursivo
}

// EJERCICIO 4

// Función auxiliar que usa restas sucesivas
float divisionAux(int num, int divisor, int n)
{
    if (num < divisor)
    {
        if (n <= 0)
        {
            return 0;
        }
        // Multiplicamos por 10.0 para asegurar operaciones con coma flotante
        return divisionAux(num * 10, divisor, n - 1) / 10.0f; 
    }
    return divisionAux(num - divisor, divisor, n) + 1;
}

// Función principal que limpia y prepara los datos
float division(int m, int n, int d)
{
    // Validar el rango de decimales solicitado (1 a 10)
    if (d < 1) d = 1;
    if (d > 10) d = 10;

    if (n == 0)
    {
        printf("Error: Division por cero.\n");
        return 0;
    }

    bool negativo = (m < 0) != (n < 0);
    
    // Trabajamos con valores absolutos
    if (m < 0) m = -m;
    if (n < 0) n = -n;
    
    // Llamamos a la auxiliar pasando la cantidad de decimales 'd'
    float resultado = divisionAux(m, n, d); 
    
    return negativo ? -resultado : resultado;
}

// EJERCICIO 5

// Función auxiliar
static void milesAux(char num[], char res[])
{
    int largo = strlen(num);

    // Caso base: si tiene 3 o menos dígitos, simplemente lo copiamos
    if (largo <= 3)
    {
        strcpy(res, num);
        return;
    }

    // Calcular cuántos dígitos quedan excluyendo los últimos 3
    int largo_izq = largo - 3;
    
    char izquierda[100]; // Buffer para los dígitos de la izquierda
    char derecha[4];    // Buffer para los 3 dígitos de la derecha + '\0'

    // Separar la parte izquierda
    strncpy(izquierda, num, largo_izq);
    izquierda[largo_izq] = '\0'; // strncpy no cierra el string automáticamente
    
    // Separar los 3 de la derecha
    strcpy(derecha, num + largo_izq);

    // Buffer temporal para guardar lo que nos devuelva la recursividad
    char res_izq[100]; 
    
    // Llamada recursiva con la parte izquierda
    milesAux(izquierda, res_izq);

    // Armar el resultado final: Izquierda + "." + Derecha
    strcpy(res, res_izq);
    strcat(res, ".");
    strcat(res, derecha);
}

// Función principal que exige el enunciado
char * agregarSeparadorMiles(char numero[])
{
    // Usamos static para que la variable sobreviva al final de la función
    // y podamos retornar su puntero sin causar errores de memoria.
    static char buf[100]; 
    buf[0] = '\0'; // Limpiamos el búfer por si se llama más de una vez
    
    // Llamamos a la lógica real
    milesAux(numero, buf);
    
    return buf;
}

// EJERCICIO 6

char * reunionMafia(int nivel)
{
	// se calcula el tamaño del string
	int tamanio = 5 + 6*(nivel-1) + 1;
	// 5 = caracteres base "(-.-)"
	// 6*(nivel-1) = cada nivel agrega "(-." y ".-)"
	// +1 = caracter nulo '\0'

	char *resultado = malloc(tamanio * sizeof(char)); 
	// se reserva la memoria necesaria para el string, calculado a partir de su tamaño

	if (nivel == 1)
	{ // caso base, se copia solo "(-.-)"
		strcpy(resultado, "(-.-)"); 

	} 
	else 
	{ // caso recursivo, se agregan los demas miembros por nivel
		char *subresultado = reunionMafia(nivel-1); 
		strcpy(resultado, "(-.");
		strcat(resultado, subresultado);
		strcat(resultado, ".-)");
		free(subresultado); // para evitar memory leak ya que cada llamada recursiva con reunionMafia(nivel-1) vuelve a guardar espacio en memoria
	}
	return resultado; // LIBERAR MEMORIA EN EL MAIN DESPUES DE MOSTRAR EL RESULTADO!!!
}

// EJERCICIO 7

// Función auxiliar recursiva
static void ondaAux(char *onda, char *alto, char *bajo) {
    if (*onda == '\0') {
        return; // Caso base: fin de la cadena
    }

    if (*onda == 'H') {
        strcat(alto, "_ "); // Dibuja el guión arriba
        strcat(bajo, "  "); // Deja el espacio vacío abajo
        
        // Si el siguiente cambia a L, ponemos el conector vertical
        if (*(onda + 1) == 'L') {
            strcat(alto, " ");
            strcat(bajo, "|");
        }
    } 
    else if (*onda == 'L') {
        strcat(alto, "  "); // Deja el espacio vacío arriba
        strcat(bajo, "_ "); // Dibuja el guión abajo
        
        // Si el siguiente cambia a H, ponemos el conector vertical
        if (*(onda + 1) == 'H') {
            strcat(alto, " ");
            strcat(bajo, "|");
        }
    }

    // Llamada recursiva avanzando al siguiente carácter
    ondaAux(onda + 1, alto, bajo);
}

// Función principal
char *ondaDigital(char seniales[]) {
    // Usamos static para poder retornar el puntero sin perder la memoria
    static char resultado[200]; 
    char alto[100] = ""; // Búfer para la línea superior
    char bajo[100] = ""; // Búfer para la línea inferior

    // Limpiamos el resultado por si se llama varias veces en el menú
    resultado[0] = '\0'; 

    // Iniciamos la recursión armando ambas líneas
    ondaAux(seniales, alto, bajo);

    // Unimos la parte superior, un salto de línea, y la inferior
    strcpy(resultado, alto);
    strcat(resultado, "\n");
    strcat(resultado, bajo);

    return resultado;
}

// EJERCICIO 8

// Función auxiliar recursiva que hace el backtracking
void subconjuntosAux(int conjunto[], int tamano, int n, int subActual[], int subTamano, int indice, char *output)
{
    // Caso base: encontramos un subconjunto que suma N
    if (n == 0)
    {
        strcat(output, "{");
        for (int i = 0; i < subTamano; i++)
        {
            char num[20];
            sprintf(num, "%d", subActual[i]);
            strcat(output, num);
            if (i < subTamano - 1)
                strcat(output, ", ");
        }
        strcat(output, "} ");
        return;
    }

    // Caso base: no quedan elementos o la suma se pasó
    if (indice == tamano || n < 0)
        return;

    // Camino 1: incluir el elemento actual
    subActual[subTamano] = conjunto[indice];
    subconjuntosAux(conjunto, tamano, n - conjunto[indice], subActual, subTamano + 1, indice + 1, output);

    // Camino 2: no incluir el elemento actual
    subconjuntosAux(conjunto, tamano, n, subActual, subTamano, indice + 1, output);
}

// Función principal que exige el enunciado
void subconjuntosQueSumanN(int conjunto[], int tamano, int n, char **output)
{
    // Peor caso: 2^tamano subconjuntos, cada elemento ocupa ~5 chars + separadores
    int bufSize = (1 << tamano) * (tamano * 5 + 4);
    *output = malloc(bufSize * sizeof(char));
    (*output)[0] = '\0';

    int subActual[100];
    subconjuntosAux(conjunto, tamano, n, subActual, 0, 0, *output);

    if ((*output)[0] == '\0')
        strcpy(*output, "(ninguno)");
}

// EJERCICIO 9

bool divisiblePor7(int n)
{
    if (n < 0)
        n = -n;

    if (n < 70)
        return n % 7 == 0;

    int ultimoDigito = n % 10;
    int resto = n / 10;
    return divisiblePor7(resto - ultimoDigito * 2);
}

// EJERCICIO 10

int *explosion(int n, int b)
{
    // Caso base: el número no explota más
    if (n <= b)
    {
        int *resultado = malloc(2 * sizeof(int));
        resultado[0] = n;
        resultado[1] = -1; // Centinela
        return resultado;
    }

    // Caso recursivo: explotar en n1 y n2
    int n1 = n / b;
    int n2 = n - n1;

    int *fragmentos1 = explosion(n1, b);
    int *fragmentos2 = explosion(n2, b);

    // Contar tamaños de cada lista (hasta el centinela)
    int tam1 = 0, tam2 = 0;
    while (fragmentos1[tam1] != -1)
        tam1++;
    while (fragmentos2[tam2] != -1)
        tam2++;

    // Combinar ambas listas en una sola
    int *resultado = malloc((tam1 + tam2 + 1) * sizeof(int));
    for (int i = 0; i < tam1; i++)
        resultado[i] = fragmentos1[i];
    for (int i = 0; i < tam2; i++)
        resultado[tam1 + i] = fragmentos2[i];
    resultado[tam1 + tam2] = -1; // Centinela

    free(fragmentos1);
    free(fragmentos2);

    return resultado; // LIBERAR MEMORIA EN EL MAIN DESPUES DE USAR
}
