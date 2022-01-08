#ifndef BALA_H_INCLUDED
#define BALA_H_INCLUDED

#include "Pantalla.h"


/**
\file Bala.h
\brief Módulo para tratamiento de una bala
**/

/**
\brief renombrado de tipos donde Bala es un apuntador a un tipo BalaRep
**/
typedef struct BalaRep * Bala;

/**
\brief Crea una bala a partir de una imagen i, una anchura w, una altura h, una posición (x,y) y una velocidad v
\param i imagen de tipo Imagen
\param w anchura de la bala
\param h altura de la bala
\param x coordenada x de la bala
\param y coordenada y de la bala
\param v velocidad de la bala
\return devuelve la bala
**/
Bala BalaCrea(Imagen i, int w, int h, int x, int y, int v);

/**
\brief Libera una bala b
\param b bala de tipo Bala
**/
void BalaLibera(Bala b);

/**
\brief Mueve una bala b
\param b bala de tipo Bala
\return devuelve 1 si se ha movido la bala y 0 en caso contrario
**/
int BalaMueve(Bala b);

/**
\brief Dibuja en pantalla una bala b
\param b bala de tipo Bala
**/
void BalaDibuja(Bala b);

/**
\brief Obtiene la anchura de la bala
\param b bala de tipo Bala
\return devuelve la anchura de la bala
**/
int BalaGetW(Bala b);

/**
\brief Obtiene la altura de la bala
\param b bala de tipo Bala
\return devuelve la altura de la bala
**/
int BalaGetH(Bala b);

/**
\brief Obtiene la coordenada x de la bala
\param b bala de tipo Bala
\return devuelve la coordenada x de la bala
**/
int BalaGetX(Bala b);

/**
\brief Obtiene la coordenada y de la bala
\param b bala de tipo Bala
\return devuelve la coordenada y de la bala
**/
int BalaGetY(Bala b);

#endif // BALA_H_INCLUDED
