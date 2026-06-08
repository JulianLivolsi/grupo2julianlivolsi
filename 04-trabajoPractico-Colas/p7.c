#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tp_colas.h"

typedef struct
{
    int idCliente;
    int idCola;
} datosCliente;

void agregarDatosColas(Cola c1, int nCola)
{
    Cola Caux = c_crear();
    datosCliente datos;
    int cliente = 1;
    while (!c_es_vacia(c1))
    {
        TipoElemento te = c_desencolar(c1);
        c_encolar(Caux, te);

        datos.idCola = nCola;
        datos.idCliente = cliente;

        datosCliente *ptr = malloc(sizeof(datosCliente));
        *ptr = datos;
        te->valor = ptr;

        cliente++;
    }
    c_intercambiar(c1, Caux);
}

void insertarAlFrente(Cola c, TipoElemento te_modificado)
{
    Cola aux = c_crear();
    c_encolar(aux, te_modificado);

    while(!c_es_vacia(c))
    {
        c_encolar(aux, c_desencolar(c));
    }
    c_intercambiar(c, aux);
    free(aux);
}

Cola c_ej7_atenderclientes(Cola c1, Cola c2, Cola c3, int tiempoatencion)
{
    if (c_es_vacia(c1) && c_es_vacia(c2) && c_es_vacia(c3)) return c_crear();
    if (tiempoatencion <= 0)
    {
        printf("El tiempo de atencion debe ser mayor a 0\n");
        return c_crear();
    }

    Cola copia1 = c_ej2_copiar(c1), copia2 = c_ej2_copiar(c2), copia3 = c_ej2_copiar(c3), res = c_crear();
    agregarDatosColas(copia1, 1);
    agregarDatosColas(copia2, 2);
    agregarDatosColas(copia3, 3);

    while(!c_es_vacia(copia1) || !c_es_vacia(copia2) || !c_es_vacia(copia3))
    {
        if(!c_es_vacia(copia1))
        {
            TipoElemento te1 = c_desencolar(copia1);
            te1->clave = te1->clave - tiempoatencion;

            if (te1->clave <= 0)
            {
                datosCliente *datos = (datosCliente*) te1->valor;
                int idCliente = datos->idCliente;

                char *texto = malloc(20 * sizeof(char));

                sprintf(texto, "Cliente %d Cola %d", idCliente, 1);

                TipoElemento te_res = te_crear_con_valor(1, texto);
                c_encolar(res, te_res);

                free(te1->valor); free(te1);
            }
            else
            {
                insertarAlFrente(copia1, te1);
            }
        }
        if(!c_es_vacia(copia2))
        {
            TipoElemento te2 = c_desencolar(copia2);
            te2->clave = te2->clave - tiempoatencion;

            if (te2->clave <= 0)
            {
                datosCliente *datos = (datosCliente*) te2->valor;
                int idCliente = datos->idCliente;

                char *texto = malloc(20 * sizeof(char));

                sprintf(texto, "Cliente %d Cola %d", idCliente, 2);

                TipoElemento te_res = te_crear_con_valor(2, texto);
                c_encolar(res, te_res);

                free(te2->valor); free(te2);
            }
            else
            {
                insertarAlFrente(copia2, te2);
            }
        }
        if(!c_es_vacia(copia3))
        {
            TipoElemento te3 = c_desencolar(copia3);
            te3->clave = te3->clave - tiempoatencion;

            if (te3->clave <= 0)
            {
                datosCliente *datos = (datosCliente*) te3->valor;
                int idCliente = datos->idCliente;

                char *texto = malloc(20 * sizeof(char));

                sprintf(texto, "Cliente %d Cola %d", idCliente, 3);

                TipoElemento te_res = te_crear_con_valor(3, texto);
                c_encolar(res, te_res);

                free(te3->valor); free(te3);
            }
            else
            {
                insertarAlFrente(copia3, te3);
            }
        }
    }
    
    free(copia1);
    free(copia2);
    free(copia3);
    
    return(res);
}


int ejercicio7()
{
    limpiarConsola();
    srand(time(NULL));
    printf("\n------ Ejercicio 7 ------\n");
    
    Cola c1 = rellenarCola(-1);
    printf("\nCola 1 : \n");
    c_mostrar(c);

    Cola c2 = rellenarCola(-1);
    printf("\nCola 2 : \n");
    c_mostrar(c);

    Cola c3 = rellenarCola(-1);
    printf("\nCola 3 : \n");
    c_mostrar(c);

    int tiempoatencion = pedirEntero("Ingrese el tiempo de atencion (1 a 100): ", 1, 100);

    Cola res = c_ej7_atenderclientes(c1, c2, c3, tiempoatencion);
    printf("\nResultados : \n");
    c_mostrar(res);

    int eleccion = pedirEntero("\nSalir (0) | Continuar (1): ", 0, 1);
    if (eleccion == 1)
        ejercicio7();
    else if (eleccion == 0)
        return 0;
}
