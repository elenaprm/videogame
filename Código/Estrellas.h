#ifndef ESTRELLAS_H_INCLUDED
#define ESTRELLAS_H_INCLUDED

#include "Estrella.h"

/**
\file Estrellas.h
\brief Módulo para tratamiento de estrellas
**/

/**
\brief renombrado de tipos donde Estrellas es un apuntador a un tipo EstrellasRep
**/
typedef struct EstrellasRep * Estrellas;

/**
\brief Crea estrellas de tipo Enemigo
\param max maximo de estrellas que pueden aparecer en pantalla
\return devuelve las estrellas
**/
Estrellas EstrellasCrea (int max);

/**
\brief Libera las estrellas e
\param e estrella de tipo Estrellas
**/
void EstrellasLibera (Estrellas e);

/**
\brief Inserta una nueva estrella
\param e estrella de tipo Estrellas
\param estrella de tipo Estrella
**/
void EstrellasInsertaNuevaEstrella(Estrellas e, Estrella estrella);

/**
\brief Dibuja en pantalla las estrellas e
\param e estrella de tipo Estrellas
**/
void EstrellasDibuja (Estrellas e);

/**
\brief Comprueba si las estrellas han colisionado
\param e estrella de tipo Estrellas
\param x coordenada x de una estrella e
\param y coordenada y de una estrella e
\param w anchura de una estrella e
\param h altura de una estrella e
\return devuelve 1 si ha habido colisión y 0 en caso contrario
**/
int EstrellasColision (Estrellas e, int x, int y, int w, int h);

#endif // ESTRELLAS_H_INCLUDED
