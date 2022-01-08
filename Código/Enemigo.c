#include <stdlib.h>
#include "Enemigo.h"

struct EnemigoRep
{
    Imagen i;
    int w, h, x, y, vx, vy;
};

Enemigo EnemigoCrea(Imagen i, int w, int h, int x, int y, int vx, int vy)
{
    Enemigo e = malloc(sizeof(struct EnemigoRep));
    e->i = i;
    e->h = h;
    e->w = w;
    e->x = x;
    e->y = y;
    e->vx = vx;
    e->vy = vy;
    return e;
}

void EnemigoLibera(Enemigo e)
{
    free(e);
}

int EnemigoMueve(Enemigo e)
{
    e->x += e->vx;
    e->y += e->vy;
    if (e->x<0)
    {
        e->x = 0;
        e->vx *=-1;
    }
    if (e->x>Pantalla_Anchura()-e->w)
    {
        e->x = Pantalla_Anchura()-e->w;
        e->vx*=-1;
    }
    return (e->y>Pantalla_Altura()-e->h);
}

void EnemigoDibuja(Enemigo e)
{
    Pantalla_DibujaImagen(e->i, e->x, e->y, e->w, e->h);
}

int EnemigoGetW(Enemigo e)
{
    return e->w;
}

int EnemigoGetH(Enemigo e)
{
    return e->h;
}

int EnemigoGetX(Enemigo e)
{
    return e->x;
}

int EnemigoGetY(Enemigo e)
{
    return e->y;
}
