#include "colas.h"
#include <stdlib.h>
#include <stdio.h>

void c_intercambiar(Cola c, Cola aux)
{
    while (!c_es_vacia(c))
    {
        c_desencolar(c);
    }

    while (!c_es_vacia(aux))
    {
        c_encolar(c, c_desencolar(aux));
    }
}
