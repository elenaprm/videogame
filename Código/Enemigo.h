#ifndef ENEMIGO_H_INCLUDED
#define ENEMIGO_H_INCLUDED

#include "Pantalla.h"

/**
\file Enemigo.h
\brief Módulo para tratamiento de un enemigo
**/

/**
\brief renombrado de tipos donde Enemigo es un apuntador a un tipo EnemigoRep
**/
typedef struct EnemigoRep * Enemigo;

/**
\brief Crea un enemigo a partir de una imagen i, una anchura w, una altura h, una posición (x,y) y una velocidad con coordenadas vx y vy
\param i imagen de tipo Imagen
\param w anchura del enemigo
\param h altura del enemigo
\param x coordenada x del enemigo
\param y coordenada y del enemigo
\param vx coordenada x de la velocidad del enemigo
\param vy coordenada y de la velocidad del enemigo
\return devuelve el enemigo
**/
Enemigo EnemigoCrea(Imagen i, int w, int h, int x, int y, int vx, int vy);

/**
\brief Libera un enemigo e
\param e enemigo de tipo Enemigo
**/
void EnemigoLibera(Enemigo e);

/**
\brief Mueve un enemigo e
\param e enemigo de tipo Enemigo
\return devuelve 1 si se ha movido el enemigo y 0 en caso contrario
**/
int EnemigoMueve(Enemigo e);

/**
\brief Dibuja en pantalla un enemigo e
\param e enemigo de tipo Enemigo
**/
void EnemigoDibuja(Enemigo e);

/**
\brief Obtiene la anchura del enemigo
\param e enemigo de tipo Enemigo
\return devuelve la anchura del enemigo
**/
int EnemigoGetW(Enemigo e);

/**
\brief Obtiene la altura del enemigo
\param e enemigo de tipo Enemigo
\return devuelve la altura del enemigo
**/
int EnemigoGetH(Enemigo e);

/**
\brief Obtiene la coordenada x del enemigo
\param e enemigo de tipo Enemigo
\return devuelve la coordenada x del enemigo
**/
int EnemigoGetX(Enemigo e);

/**
\brief Obtiene la coordenada y del enemigo
\param e enemigo de tipo Enemigo
\return devuelve la coordenada y del enemigo
**/
int EnemigoGetY(Enemigo e);

#endif // ENEMIGO_H_INCLUDED
