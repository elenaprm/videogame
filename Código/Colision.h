#ifndef COLISION_H_INCLUDED
#define COLISION_H_INCLUDED

/**
\file Colision.h
\brief Módulo para tratamiento de colisiones
**/

/**
\brief comprueba si ha habido colision entre dos objetos (x1,y1,w1,h1) y (x2,y2,w2,h2)
\param x1 coordenada x del primer objeto
\param y1 coordenada y del primer objeto
\param w1 anchura del primer objeto
\param h1 altura del primer objeto
\param x2 coordenada x del segundo objeto
\param y2 coordenada y del segundo objeto
\param w2 anchura del segundo objeto
\param h2 altura del segundo objeto
\return devuelve 1 si ha habido colision y 0 en caso contrario
**/

int Colision(int x1, int y1, int h1, int w1, int x2, int y2, int h2, int w2);


#endif // COLISION_H_INCLUDED
