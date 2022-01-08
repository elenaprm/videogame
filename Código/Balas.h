#ifndef BALAS_H_INCLUDED
#define BALAS_H_INCLUDED

#include "Bala.h"
#include "Enemigos.h"

/**
\file Balas.h
\brief Módulo para tratamiento de balas
**/

/**
\brief renombrado de tipos donde Balas es un apuntador a un tipo BalasRep
**/
typedef struct BalasRep * Balas;

/**
\brief Crea balas de tipo Bala
\return devuelve las balas
**/
Balas BalasCrea();

/**
\brief Libera las balas b
\param b bala de tipo Balas
**/
void BalasLibera(Balas b);

/**
\brief Mueve las balas b
\param b bala de tipo Balas
**/
void BalasMueve(Balas b);

/**
\brief Dibuja en pantalla las balas b
\param b bala de tipo Balas
**/
void BalasDibuja(Balas b);

/**
\brief Inserta una nueva bala
\param b bala de tipo Balas
\param bala de tipo Bala
**/
void BalasInsertaNuevoBala(Balas b, Bala bala);

/**
\brief Comprueba si las balas han colisionado
\param b bala de tipo Balas
\param x coordenada x de una bala b
\param y coordenada y de una bala b
\param w anchura de una bala b
\param h altura de una bala b
\return devuelve 1 si ha habido colisión y 0 en caso contrario
**/
int BalasColision(Balas b, int x, int y, int w, int h);

/**
\brief Libera una bala si colisiona con un enemigo
\param b bala de tipo Balas
\param e enemigo de tipo Enemigos
**/
void BalasColisionEnemigo(Balas b, Enemigos e);


#endif // BALAS_H_INCLUDED
