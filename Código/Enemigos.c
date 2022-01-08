#include <stdlib.h>
#include "Enemigos.h"
#include "Colision.h"

struct EnemigosRep
{
    Enemigo e;
    Enemigos sig;
};

Enemigos EnemigosCrea()
{
    Enemigos e = malloc(sizeof(struct EnemigosRep));
    e->sig = NULL;
    return e;
}

void EnemigosLibera(Enemigos e)
{
    while(e->sig!=NULL)
    {
        Enemigos aux = e->sig;
        e->sig = e->sig->sig;
        EnemigoLibera(aux->e);
        free(aux);
    }
    free(e);
}

void EnemigosMueve(Enemigos e)
{
    while(e->sig!=NULL)
    {
        if(EnemigoMueve(e->sig->e))
        {
            Enemigos aux = e->sig;
            e->sig = e->sig->sig;
            EnemigoLibera(aux->e);
            free(aux);
        }
        else e = e->sig;
    }
}

void EnemigosDibuja(Enemigos e)
{
    for(; e->sig!=NULL; e=e->sig) EnemigoDibuja(e->sig->e);
}

void EnemigosInsertaNuevoEnemigo(Enemigos e, Enemigo enemigo)
{
    Enemigos aux = malloc(sizeof(struct EnemigosRep));
    aux->e = enemigo;
    aux->sig = e->sig;
    e->sig = aux;
}

int EnemigosColision(Enemigos e, int x, int y, int w, int h)
{
    while((e->sig!=NULL)&&(!Colision(EnemigoGetX(e->sig->e), EnemigoGetY(e->sig->e), EnemigoGetW(e->sig->e), EnemigoGetH(e->sig->e), x, y, w, h))) e=e->sig;
    int choque = e->sig!=NULL;
    if (choque)
    {
        Enemigos aux = e->sig;
        e->sig = e->sig->sig;
        EnemigoLibera(aux->e);
        free(aux);
    }
    return choque;
}
