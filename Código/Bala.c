#include <stdlib.h>
#include "Bala.h"


struct BalaRep
{
    Imagen i;
    int w, h, x, y, v;
};

Bala BalaCrea(Imagen i, int w, int h, int x, int y, int v)
{
    Bala b = malloc(sizeof(struct BalaRep));
    b->i = i;
    b->h = h;
    b->w = w;
    b->x = x;
    b->y = y;
    b->v = v;
    return b;
}

void BalaLibera(Bala b)
{
    free(b);
}

int BalaMueve(Bala b)
{
    b->y -= b->v;
    return (b->y>Pantalla_Altura()-b->h);
}

void BalaDibuja(Bala b)
{
    Pantalla_DibujaImagen(b->i, b->x, b->y, b->w, b->h);
}

int BalaGetW(Bala b)
{
    return b->w;
}

int BalaGetH(Bala b)
{
    return b->h;
}

int BalaGetX(Bala b)
{
    return b->x;
}

int BalaGetY(Bala b)
{
    return b->y;
}
