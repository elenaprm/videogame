#ifndef PERSONAJE_H_INCLUDED
#define PERSONAJE_H_INCLUDED

#include "Pantalla.h"

/**
\file Personaje.h
\brief Módulo para tratamiento de un personaje
**/

/**
\brief renombrado de tipos donde Personaje es un apuntador a un tipo PersonajeRep
**/
typedef struct PersonajeRep * Personaje;

/**
\brief Crea un personaje a partir de una imagen i, una anchura w, una altura h y una posición (x,y)
\param i imagen de tipo Imagen
\param w anchura del personaje
\param h altura del personaje
\param x coordenada x del personaje
\param y coordenada y del personaje
\return devuelve el personaje
**/
Personaje PersonajeCrea(Imagen i, int w, int h, int x, int y);

/**
\brief Libera un personaje p
\param p personaje de tipo Personaje
**/
void PersonajeLibera(Personaje p);

/**
\brief Mueve un personaje p
\param p personaje de tipo Personaje
\return devuelve 1 si se ha movido el personaje y 0 en caso contrario
**/
void PersonajeMueve(Personaje p, int vx, int vy);

/**
\brief Dibuja en pantalla un peronaje p
\param p personaje de tipo personaje
**/
void PersonajeDibuja(Personaje p);

/**
\brief Obtiene la coordenada x del personaje
\param p personaje de tipo Personaje
\return devuelve la coordenada x del personaje
**/
int PersonajeGetX(Personaje p);

/**
\brief Obtiene la coordenada y del personaje
\param p personaje de tipo Personaje
\return devuelve la coordenada y del personaje
**/
int PersonajeGetY(Personaje p);

/**
\brief Obtiene la anchura del personaje
\param p personaje de tipo Personaje
\return devuelve la anchura del personaje
**/
int PersonajeGetW(Personaje p);

/**
\brief Obtiene la altura del persoanje
\param p personaje de tipo Personaje
\return devuelve la altura del personaje
**/
int PersonajeGetH(Personaje p);



#endif // PERSONAJE_H_INCLUDED
