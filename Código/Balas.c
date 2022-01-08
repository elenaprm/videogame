#include <stdlib.h>
#include "Balas.h"
#include "Colision.h"
#include "Enemigos.h"

struct BalasRep
{
    Bala b;
    Balas sig;
};

Balas BalasCrea()
{
    Balas b = malloc(sizeof(struct BalasRep));
    b->sig = NULL;
    return b;
}

void BalasLibera(Balas b)
{
    while(b->sig!=NULL)
    {
        Balas aux = b->sig;
        b->sig = b->sig->sig;
        BalaLibera(aux->b);
        free(aux);
    }
    free(b);
}

void BalasMueve(Balas b)
{
    while(b->sig!=NULL)
    {
        if(BalaMueve(b->sig->b))
        {
            Balas aux = b->sig;
            b->sig = b->sig->sig;
            BalaLibera(aux->b);
            free(aux);
        }
        else b = b->sig;
    }
}

void BalasDibuja(Balas b)
{
    for(; b->sig!=NULL; b=b->sig) BalaDibuja(b->sig->b);
}

void BalasInsertaNuevoBala(Balas b, Bala bala)
{
    Balas aux = malloc(sizeof(struct BalasRep));
    aux->b = bala;
    aux->sig = b->sig;
    b->sig = aux;
}

int BalasColision(Balas b, int x, int y, int w, int h)
{
    while((b->sig!=NULL)&&(!Colision(BalaGetX(b->sig->b), BalaGetY(b->sig->b), BalaGetW(b->sig->b), BalaGetH(b->sig->b), x, y, w, h))) b=b->sig;
    return (b->sig!=NULL);
}

void BalasColisionEnemigo(Balas b, Enemigos e)
{
    while((b->sig!=NULL)&&(!EnemigosColision(e, BalaGetX(b->sig->b), BalaGetY(b->sig->b), BalaGetW(b->sig->b), BalaGetH(b->sig->b)))) b=b->sig;
    int choque= b->sig!=NULL;
    if (choque)
    {
        Balas aux = b->sig;
        b->sig = b->sig->sig;
        BalaLibera(aux->b);
        free(aux);
    }
}
