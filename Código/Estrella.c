#include <stdlib.h>
#include "Pantalla.h"
#include "Estrella.h"

struct EstrellaRep
{
    Imagen i;
    int w, h, x, y;
};

Estrella EstrellaCrea (Imagen i, int w, int h, int x, int y)
{
    Estrella e = malloc (sizeof(struct EstrellaRep));
    e->i = i;
    e->w = w;
    e->h = h;
    e->x = x;
    e->y = y;
    return e;
}

void EstrellaLibera (Estrella e)
{
    free(e);
}

void EstrellaDibuja(Estrella e)
{
    Pantalla_DibujaImagen(e->i, e->x, e->y, e->w, e->h);
}

int EstrellaGetW(Estrella e)
{
    return e->w;
}

int EstrellaGetH(Estrella e)
{
    return e->h;
}

int EstrellaGetX(Estrella e)
{
    return e->x;
}

int EstrellaGetY(Estrella e)
{
    return e->y;
}
