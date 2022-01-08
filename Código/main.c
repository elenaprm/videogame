
#include "Pantalla.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "Personaje.h"
#include "Enemigo.h"
#include "Colision.h"
#include "Estrella.h"
#include "Estrellas.h"
#include "Enemigos.h"
#include "Bala.h"
#include "Balas.h"

#define WPANTALLA 500
#define HPANTALLA 500
#define WPERSONAJE 50
#define HPERSONAJE 50
#define VXPERSONAJE 40
#define VYPERSONAJE 40

#define WENEMIGO 50
#define HENEMIGO 50
#define VXENEMIGO 15
#define VYENEMIGO 15

#define WBALA 50
#define HBALA 50
#define VBALA 15

#define WESTRELLA 50
#define HESTRELLA 50

#define MAXESTRELLAS 5
#define FRECESTRELLAS 15

#define PUNTOSEXTRA 10

#define FRECENEMIGOS 20


/**
\mainpage Videojuego donde eres un panda y tienes que comerte los bamb�s y huir de los chacales.
\file main.c
\brief C�digo principal del juego
**/

int main (int argc, char * argv[])
{
    Pantalla_Crea("Hola Mundo",WPANTALLA,HPANTALLA);
    int wPantalla = Pantalla_Anchura();
    int hPantalla = Pantalla_Altura();
    Imagen fondo = Pantalla_ImagenLee("fondo.bmp",1);
    Imagen panda = Pantalla_ImagenLee("panda.bmp",1);
    Imagen panda2 = Pantalla_ImagenLee("panda2.bmp",1);
    Imagen p1g = Pantalla_ImagenLee("panda1ganador.bmp",1);
    Imagen p2g = Pantalla_ImagenLee("panda2ganador.bmp",1);
    Imagen enemigo = Pantalla_ImagenLee("enemigo.bmp",1);
    Imagen bala = Pantalla_ImagenLee("disco.bmp",1);
    Imagen estrellaImagen = Pantalla_ImagenLee("bambu.bmp", 1);
    Imagen menu1 = Pantalla_ImagenLee("menu1.bmp",1);
    Imagen menu2 = Pantalla_ImagenLee("menu2.bmp",1);
    Imagen menu3 = Pantalla_ImagenLee("menu3.bmp",1);
    Imagen menu4 = Pantalla_ImagenLee("menu4.bmp",1);
    Imagen ayuda = Pantalla_ImagenLee("ayuda.bmp",0);
    Pantalla_ColorTrazo(0,255,0,255);
    int locator=0;
    int i=0;
    int flagdown=1;
    int flagup=1;

    //while principal
    while (Pantalla_Activa() && locator==0)
    {
        if(Pantalla_TeclaPulsada(SDL_SCANCODE_DOWN) && flagdown==1)
        {
            if(i<3) i=i+1;
            flagdown=0;
        }
        else if(!Pantalla_TeclaPulsada(SDL_SCANCODE_DOWN)) flagdown=1;

        if(Pantalla_TeclaPulsada(SDL_SCANCODE_UP) && flagup==1)
        {
            if(i>0) i=i-1;
            flagup=0;
        }
        else if(!Pantalla_TeclaPulsada(SDL_SCANCODE_UP)) flagup=1;



        switch (i)
        {
        case 0:
            Pantalla_DibujaImagen(menu1,0,0,wPantalla,hPantalla);
            if(Pantalla_TeclaPulsada(SDL_SCANCODE_RETURN)) locator=1;
            break;
        case 1:
            Pantalla_DibujaImagen(menu2,0,0,wPantalla,hPantalla);
            if(Pantalla_TeclaPulsada(SDL_SCANCODE_RETURN)) locator=2;
            break;
        case 2:
            Pantalla_DibujaImagen(menu3,0,0,wPantalla,hPantalla);
            if(Pantalla_TeclaPulsada(SDL_SCANCODE_RETURN)) locator=3;
            break;
        case 3:
            Pantalla_DibujaImagen(menu4,0,0,wPantalla,hPantalla);
            if(Pantalla_TeclaPulsada(SDL_SCANCODE_RETURN)) locator=4;
            break;
        }



        //ayuda
        while (Pantalla_Activa() && locator==2)
        {
            Pantalla_DibujaImagen(ayuda, 0, 0, wPantalla, hPantalla);
            Pantalla_ColorTrazo(0,0,0,255);
            Pantalla_DibujaTexto("Pulse [ESPACIO] para volver al menu principal", 10, 10);
            if(Pantalla_TeclaPulsada(SDL_SCANCODE_SPACE)) locator=0;
            Pantalla_Actualiza();
            Pantalla_Espera(50);
        }


        //jugar
        if (locator==1)
        {
            srand (time (NULL));
            Personaje p = PersonajeCrea(panda, WPERSONAJE, HPERSONAJE, rand()%(wPantalla-WPERSONAJE), hPantalla-HPERSONAJE);
            Enemigos e = EnemigosCrea();
            Balas b = BalasCrea();
            Estrellas estrellas = EstrellasCrea (MAXESTRELLAS);
            int fin = 0;
            int t1 = time(NULL);
            int t2 = time(NULL);
            char texto[100];
            int puntos = 0, puntosExtra = 0;
            int cont =0;
            while (Pantalla_Activa()&&(!fin))
            {
                if (cont==FRECESTRELLAS)
                {
                    EstrellasInsertaNuevaEstrella(estrellas, EstrellaCrea (estrellaImagen, WESTRELLA, HESTRELLA, rand()%(wPantalla-WESTRELLA), rand()%(hPantalla-HESTRELLA)));
                    cont=0;
                }
                if (rand()%FRECENEMIGOS==0) EnemigosInsertaNuevoEnemigo(e, EnemigoCrea(enemigo, WENEMIGO, HENEMIGO, rand()%(wPantalla-WENEMIGO), 0, VXENEMIGO, VYENEMIGO));
                if (Pantalla_TeclaPulsada(SDL_SCANCODE_ESCAPE)) fin=1;
                if (Pantalla_TeclaPulsada(SDL_SCANCODE_LEFT)) PersonajeMueve(p, -VXPERSONAJE, 0);
                if (Pantalla_TeclaPulsada(SDL_SCANCODE_RIGHT)) PersonajeMueve(p, VXPERSONAJE, 0);
                if (Pantalla_TeclaPulsada(SDL_SCANCODE_UP)) PersonajeMueve(p, 0, -VYPERSONAJE);
                if (Pantalla_TeclaPulsada(SDL_SCANCODE_DOWN)) PersonajeMueve(p, 0, VYPERSONAJE);
                EnemigosMueve(e);
                if(Pantalla_TeclaPulsada(SDL_SCANCODE_SPACE)) BalasInsertaNuevoBala(b,BalaCrea(bala, WBALA, HBALA, PersonajeGetX(p), PersonajeGetY(p), VBALA));
                BalasMueve(b);
                BalasColisionEnemigo(b, e) ;
                if (EnemigosColision(e, PersonajeGetX(p), PersonajeGetY(p), PersonajeGetW(p), PersonajeGetH(p))) fin=1;
                if (EstrellasColision(estrellas, PersonajeGetX(p), PersonajeGetY(p), PersonajeGetW(p), PersonajeGetH(p))) puntosExtra+=PUNTOSEXTRA;
                t2= time(NULL);
                puntos = t2-t1+puntosExtra;
                sprintf(texto,"%d", puntos);
                cont ++;
                Pantalla_DibujaImagen (fondo,0,0,wPantalla,hPantalla);
                Pantalla_ColorTrazo (0,255,0,255);
                Pantalla_DibujaTexto ("Pulsa [ESCAPE] para terminar",10,10);
                Pantalla_DibujaTexto(texto,10,35);
                PersonajeDibuja(p);
                EnemigosDibuja(e);
                BalasDibuja(b);
                EstrellasDibuja(estrellas);
                Pantalla_Actualiza();
                Pantalla_Espera(50);
            }
            sprintf(texto, "Puntos : %d", puntos);
            int puntosMax=0;
            int dato;
            FILE * f = fopen("record.txt", "r");
            fscanf(f, "%d", &puntosMax);
            if (f!=NULL)
            {
                while (!feof(f))
                {
                    fscanf(f, "%d", &dato);
                    if (dato>puntosMax) puntosMax = dato;
                }
                fclose(f);
            }
            char texto2[100];
            if (puntos>puntosMax)
                sprintf(texto2, "Nuevo record %d puntos", puntos);
            else sprintf (texto2, "Record = %d puntos", puntosMax);
            f= fopen("record.txt", "a");
            fprintf(f, "%d\n", puntos);
            fclose(f);
            while (Pantalla_Activa() && fin==1)
            {
                Pantalla_DibujaImagen(fondo, 0,0,wPantalla, hPantalla);
                Pantalla_ColorTrazo(0,255,0,255);
                Pantalla_DibujaTexto("Hasta pronto", 215, 210);
                Pantalla_DibujaTexto("Pulse 4 para volver al menu principal y 5 para salir",0,0);
                Pantalla_DibujaTexto(texto, 215,20);
                Pantalla_DibujaTexto(texto2, 195, 400);
                if(Pantalla_TeclaPulsada(SDL_SCANCODE_4))
                {
                    locator=0;
                    fin=0;
                }
                if(Pantalla_TeclaPulsada(SDL_SCANCODE_5))
                {
                    locator=5;
                    fin=0;
                }
                Pantalla_Actualiza();
                Pantalla_Espera(50);
            }
        }



        //1 vs 1
        if (locator==3)
        {
            srand (time (NULL));
            Personaje p = PersonajeCrea(panda, WPERSONAJE, HPERSONAJE, rand()%(wPantalla-WPERSONAJE), hPantalla-HPERSONAJE);
            Personaje p2 = PersonajeCrea(panda2, WPERSONAJE, HPERSONAJE, rand()%(wPantalla-WPERSONAJE), hPantalla-HPERSONAJE);
            Enemigos e = EnemigosCrea();
            int fin = 0;
            int cual =0;
            while (Pantalla_Activa()&&(!fin))
            {
                if (rand()%FRECENEMIGOS==0) EnemigosInsertaNuevoEnemigo(e, EnemigoCrea(enemigo, WENEMIGO, HENEMIGO, rand()%(wPantalla-WENEMIGO), 0, VXENEMIGO, VYENEMIGO));
                if (Pantalla_TeclaPulsada(SDL_SCANCODE_ESCAPE)) fin=1;
                if (Pantalla_TeclaPulsada(SDL_SCANCODE_LEFT)) PersonajeMueve(p, -VXPERSONAJE, 0);
                if (Pantalla_TeclaPulsada(SDL_SCANCODE_RIGHT)) PersonajeMueve(p, VXPERSONAJE, 0);
                if (Pantalla_TeclaPulsada(SDL_SCANCODE_UP)) PersonajeMueve(p, 0, -VYPERSONAJE);
                if (Pantalla_TeclaPulsada(SDL_SCANCODE_DOWN)) PersonajeMueve(p, 0, VYPERSONAJE);
                if (Pantalla_TeclaPulsada(SDL_SCANCODE_A)) PersonajeMueve(p2, -VXPERSONAJE, 0);
                if (Pantalla_TeclaPulsada(SDL_SCANCODE_D)) PersonajeMueve(p2, VXPERSONAJE, 0);
                if (Pantalla_TeclaPulsada(SDL_SCANCODE_W)) PersonajeMueve(p2, 0, -VYPERSONAJE);
                if (Pantalla_TeclaPulsada(SDL_SCANCODE_S)) PersonajeMueve(p2, 0, VYPERSONAJE);
                EnemigosMueve(e);
                if (EnemigosColision(e, PersonajeGetX(p), PersonajeGetY(p), PersonajeGetW(p), PersonajeGetH(p)))
                {
                    fin=1;
                    cual=2;
                }
                if (EnemigosColision(e, PersonajeGetX(p2), PersonajeGetY(p2), PersonajeGetW(p2), PersonajeGetH(p2)))
                {
                    fin=1;
                    cual=1;
                }
                Pantalla_DibujaImagen (fondo,0,0,wPantalla,hPantalla);
                Pantalla_ColorTrazo (0,255,0,255);
                Pantalla_DibujaTexto ("Pulsa [ESCAPE] para terminar",10,10);
                PersonajeDibuja(p);
                PersonajeDibuja(p2);
                EnemigosDibuja(e);
                Pantalla_Actualiza();
                Pantalla_Espera(50);
            }
            PersonajeLibera(p);
            PersonajeLibera(p2);
            while (Pantalla_Activa() && fin==1)
            {
                Pantalla_DibujaImagen(fondo, 0,0,wPantalla, hPantalla);
                Pantalla_ColorTrazo(0,255,0,255);
                Pantalla_DibujaTexto("Hasta pronto", 215, 450);
                if(cual==1)
                {
                    Pantalla_DibujaTexto("�El ganador es el jugador 1! �Enhorabuena!", 10,10);
                    Pantalla_DibujaImagen(p1g, 150, 150, 200, 200);
                }
                if(cual==2)
                {
                    Pantalla_DibujaTexto("�El ganador es el jugador 2! �Enhorabuena!", 10,10);
                    Pantalla_DibujaImagen(p2g, 150, 150, 200, 200);
                }
                Pantalla_DibujaTexto("Pulse 4 para volver al menu principal y 5 para salir",0,380);
                Pantalla_Actualiza();
                Pantalla_Espera(20);
                if(Pantalla_TeclaPulsada(SDL_SCANCODE_4))
                {
                    locator=0;
                    fin=0;
                }
                if(Pantalla_TeclaPulsada(SDL_SCANCODE_5))
                {
                    locator=5;
                    fin=0;
                }
            }
        }




        Pantalla_Actualiza();
        Pantalla_Espera(50);



    }

    Pantalla_ImagenLibera(fondo);
    Pantalla_ImagenLibera(panda);
    Pantalla_ImagenLibera(panda2);
    Pantalla_ImagenLibera(p1g);
    Pantalla_ImagenLibera(p2g);
    Pantalla_ImagenLibera(enemigo);
    Pantalla_ImagenLibera(bala);
    Pantalla_ImagenLibera(estrellaImagen);
    Pantalla_ImagenLibera(menu1);
    Pantalla_ImagenLibera(menu2);
    Pantalla_ImagenLibera(menu3);
    Pantalla_ImagenLibera(menu4);
    Pantalla_ImagenLibera(ayuda);
    return 0;
}
