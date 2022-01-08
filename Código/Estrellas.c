#include <stdlib.h>
#include "Estrellas.h"
#include "Colision.h"

struct EstrellasRep
{
    Estrella * e;
    int max,n;
};

Estrellas EstrellasCrea (int max)
{
    Estrellas e = malloc(sizeof(struct EstrellasRep));
    e->e = malloc(sizeof(Estrella)*max);
    e->max = max;
    e->n = 0;
    return e;
}

void EstrellasLibera(Estrellas e)
{
    for(int i=0; i<e->n; i++) EstrellaLibera(e->e[i]);
    free(e->e);
    free(e);
}

void EstrellasInsertaNuevaEstrella(Estrellas e, Estrella estrella)
{
    if (e->n<e->max)
    {
        e->e[e->n] = estrella;
        e->n++;
    }
}

void EstrellasDibuja (Estrellas e)
{
    for(int i=0; i<e->n; i++) EstrellaDibuja(e->e[i]);
}

int EstrellasColision(Estrellas e, int x, int y, int w, int h)
{
    int i=0;
    while ((i<e->n)&&(!Colision(EstrellaGetX(e->e[i]), EstrellaGetY(e->e[i]), EstrellaGetW(e->e[i]), EstrellaGetH(e->e[i]), x, y, w, h))) i++;
    int colision = (i<e->n);
    if (colision)
    {
        EstrellaLibera(e->e[i]);
        e->e[i] = e->e[e->n-1];
        e->n--;
    }
    return colision;
}
