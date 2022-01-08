#ifndef ESTRELLA_H_INCLUDED
#define ESTRELLA_H_INCLUDED

#include "Pantalla.h"

/**
\file Estrella.h
\brief Módulo para tratamiento de una estrella
**/

/**
\brief renombrado de tipos donde Estrella es un apuntador a un tipo EstrellaRep
**/
typedef struct EstrellaRep * Estrella;

/**
\brief Crea una estrella a partir de una imagen i, una anchura w, una altura h y una posición (x,y)
\param i imagen de tipo Imagen
\param w anchura de la estrella
\param h altura de la estrella
\param x coordenada x de la estrella
\param y coordenada y de la estrella
\return devuelve la estrella
**/
Estrella EstrellaCrea (Imagen i, int w, int h, int x, int y);

/**
\brief Libera una estrella e
\param e estrella de tipo Estrella
**/
void EstrellaLibera (Estrella e);

/**
\brief Dibuja en pantalla una estrella e
\param e estrella de tipo Estrella
**/
void EstrellaDibuja (Estrella e);

/**
\brief Obtiene la anchura de la estrella
\param e estrella de tipo Estrella
\return devuelve la anchura de la estrella
**/
int EstrellaGetW (Estrella e);

/**
\brief Obtiene la altura de la estrella
\param e estrella de tipo Estrella
\return devuelve la altura de la estrella
**/
int EstrellaGetH (Estrella e);

/**
\brief Obtiene la coordenada x de la estrella
\param e estrella de tipo Estrella
\return devuelve la coordenada x de la estrella
**/
int EstrellaGetX (Estrella e);

/**
\brief Obtiene la coordenada y de la estrella
\param e estrella de tipo Estrella
\return devuelve la coordenada y de la estrella
**/
int EstrellaGetY (Estrella e);


#endif // ESTRELLA_H_INCLUDED
