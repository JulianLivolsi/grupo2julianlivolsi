#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef TP1_Recursividad
#define TP1_Recursividad

// Ejercicio 1
/*1.	Construir una función recursiva que retorne verdadero si una cadena de caracteres pasada
como parámetro es un palíndromo.  Ej. “neuquen” ya que se lee igual de atrás hacia adelante.*/
bool palindromo(char *cadena)
{
    int len = strlen(cadena);
    if (len <= 1)
        return true;
    if (cadena[0] != cadena[len - 1])
        return false;
    cadena[len - 1] = '\0';
    return palindromo(cadena + 1);
}

// Ejercicio 2
/*2.	Dados dos números enteros m y n, construir una función recursiva que devuelva
el producto de ambos, calculando el mismo como sumas sucesivas. Esto es: m*n=m+m+...+m, n veces. */

int producto(int m, int n)
{
    if (n < 0)
        return -producto(m, -n);
    if (n == 0)
        return 0;
    return m + producto(m, n - 1);
}

// Ejercicio 3
/*3.	Generar un algoritmo recursivo que calcule el k-ésimo número de la serie de Fibonacci.*/

int terminoSerieFibonacci(int k)
{
    if (k == 0)
        return 0;
    if (k == 1)
        return 1;
    return terminoSerieFibonacci(k - 1) + terminoSerieFibonacci(k - 2);
}

// Ejercicio 4
/*4.	Dados los números enteros m y n, construir una función recursiva que devuelva el
cociente de ambos, calculando el mismo mediante restas sucesivas. Se deberá tener en cuenta que en el caso
de que la división no sea exacta, se devolverán hasta 4 cifras decimales (si es necesario). */

static float divisionAux(int m, int n, float escala, int decimalesRestantes)
{
    if (m == 0)
        return 0;
    if (m < n)
    {
        if (decimalesRestantes == 0)
            return 0;
        return divisionAux(m * 10, n, escala * 10, decimalesRestantes - 1);
    }
    return (float)(m / n) / escala + divisionAux(m % n, n, escala * 10, decimalesRestantes - 1);
}

float division(int m, int n)
{
    bool negativo = (m < 0) != (n < 0);
    if (m < 0)
        m = -m;
    if (n < 0)
        n = -n;
    float resultado = divisionAux(m, n, 1.0f, 4);
    return negativo ? -resultado : resultado;
}

// Ejercicio 5
/*5.	Generar un algoritmo recursivo que le ponga los “.” de los miles a un String de números.*/

static void milesAux(char *num, int pos, int len, char *resultado)
{
    if (pos == len)
        return; // caso base: llegamos al final

    milesAux(num, pos + 1, len, resultado); // nos hundimos hasta el fondo

    // vuelta atrás: escribimos el dígito actual
    int idx = strlen(resultado);
    resultado[idx] = num[pos];
    resultado[idx + 1] = '\0';

    // cuántos dígitos quedan a la derecha de esta posición
    int desde_derecha = len - pos;
    // si es múltiplo de 3 Y no es el último dígito escrito → punto
    if (desde_derecha % 3 == 0 && pos != 0)
    {
        int idx2 = strlen(resultado);
        resultado[idx2] = '.';
        resultado[idx2 + 1] = '\0';
    }
}

char *agregarSeparadorMiles(char numero[])
{
    static char buf[64];
    buf[0] = '\0';
    milesAux(numero, 0, strlen(numero), buf);
    return buf;
}

// Ejercicio 6
/*6.	Se conoce que la mafia china es muy organizada y protege mucho a sus miembros, cuando deciden asistir
a una reunión se dispone de una cantidad de chinos que asisten, y ellos se ubican de forma que al mirarlos
frontalmente generan cierto respeto y temor. A continuación, se tiene una serie de posibles reuniones y su
nivel y la apariencia que se tiene del grupo que va a la reunión vistos frontalmente:

Nivel reunión	Vista frontal de la delegación
        1 	        (-.-)
        2 		 (-.(-.-).-)
        3 	  (-.(-.(-.-).-).-)
        4  (-.(-.(-.(-.-).-).-).-)

*/

char *reunionMafia(int nivel);

// ejercicio 7
/*8.	Se tiene una cadena que representa una onda digital de señales L (Low) y H (High). Se pide mostrar
la onda que representa utilizando “_” y “|”.

Ejemplo: Si se tiene la cadena HHHHLLLLHHHHHLLHHLL, su onda digital se puede ver algo así:
_ _ _ _            _ _ _ _ _      _ _
        | _ _ _ _ |         |_ _ |   | _ _

*/

char *ondaDigital(char seniales[]);

// Ejercicio 8
/*8.	Definir una función recursiva que dado un conjunto devuelva una lista con los subconjuntos del mismo
tales que la suma de los elementos de cada subconjunto sumen una cantidad dada.
Por ejemplo:   Dado el conjunto A = {10, 3, 1, 7, 4, 2}. La lista de los conjuntos que sumen 7 sería:
R = [{3, 4}, {1, 4, 2}, {7}]*/

// int ** subconjuntosQueSumanN(int conjunto[], int n);
void subconjuntosQueSumanN(int conjunto[], int tamano, int n, char **output);

/*NOTA: Para facilitar la resolución pueden optar por el primer prototipo según el cual la función devuelve un
arreglo de apuntadores a arreglos de enteros (los subconjuntos), o por el segundo que establece que el tipo
devuelto es una cadena con el conjunto de subconjuntos, con el formato que consta en la consigna.
Comentar la firma que no se utilice.*/

// Ejercicio 9
/*9. Escribir una función recursiva que implemente el método que se describe para saber si
un número es divisible por 7. Se separa la primera cifra de la derecha, se la multiplica
por 2, y se resta este producto de lo que queda a la izquierda y así sucesivamente,
hasta que el resultado obtenido sea un número menor a 70. El número original será
múltiplo de 7 si el resultado da cero o múltiplo de 7.
Ejemplos:
32291 -> 1x2=2.
3229 - 2 =
3227 -> 7x2=14.
322 - 14 =
308 -> 8x2=16
30 - 16 =
14 -> Múltiplo de 7
divisiblePor7 (32291) => verdadero

110 -> 0 x 2 = 0
11 – 0 =
11 -> No múltiplo de 7
divisiblePor7 (110) => falso
*/

bool divisiblePor7(int n);

// Ejercicio 10
/*
10.  Se dice que N es un número explosivo cuando éste explota en varios fragmentos más
chicos que él, dada una bomba B. Si se tiene que N es el número y B la bomba, tales
que N es mayor que B, se puede hacer que N explote en dos números N1 = N / B
(división entera) y N2 = N - (N / B).
Pero B es una bomba que produce una reacción en cadena, si N1 o N2 son mayores que
B, estos también explotan con la regla anterior, hasta que se encuentre que el número
no es mayor que B; entonces se dice que ya no se puede explotar el número.
Escribe una función recursiva que retorne una lista con los pedazos del número N,
dado que se tiene la bomba B.

Ejemplos:
Número: 10
Bomba: 3
explosion(10, 3) => [3 2 1 1 3]
Número: 20
Bomba: 5
explosion(20, 5) => [4 3 2 2 1 1 1 1 5]

NOTA: Se utilizará el valor -1 como entero que indica el final del arreglo devuelto por la función.
*/

int *explosion(int n, int b);

#endif