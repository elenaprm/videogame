#ifndef ENEMIGOS_H_INCLUDED
#define ENEMIGOS_H_INCLUDED

#include "Enemigo.h"

/**
\file Enemigos.h
\brief Módulo para tratamiento de enemigos
**/

/**
\brief renombrado de tipos donde Enemigos es un apuntador a un tipo EnemigosRep
**/
typedef struct EnemigosRep * Enemigos;

/**
\brief Crea enemigos de tipo Enemigo
\return devuelve los enemigos
**/
Enemigos EnemigosCrea();

/**
\brief Libera los enemigos e
\param e enemigo de tipo Enemigos
**/
void EnemigosLibera(Enemigos e);

/**
\brief Mueve los enemigos e
\param e enemigo de tipo Enemigos
**/
void EnemigosMueve(Enemigos e);

/**
\brief Dibuja en pantalla los enemigos e
\param e enemigo de tipo Enemigos
**/
void EnemigosDibuja(Enemigos e);

/**
\brief Inserta un nuevo enemigo
\param e enemigo de tipo Enemigos
\param enemigo de tipo Enemigo
**/
void EnemigosInsertaNuevoEnemigo(Enemigos e, Enemigo enemigo);

/**
\brief Comprueba si los enemigos han colisionado
\param e enemigo de tipo Enemigos
\param x coordenada x de un enemigo e
\param y coordenada y de un enemigo e
\param w anchura de un enemigo e
\param h altura de un enemigo e
\return devuelve 1 si ha habido colisión y 0 en caso contrario
**/
int EnemigosColision(Enemigos e, int x, int y, int w, int h);

#endif // ENEMIGOS_H_INCLUDED
