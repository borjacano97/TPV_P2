#pragma once
#include "SDL.h"  // Para utilizar SDL
#include "TexturasSDL.h"
#include "SDL_image.h"
#include <iostream>  // la consola: cin / cout
using namespace std; // Para cualificar automaticamente con std:: los identificadores de la librería estandar 


class GlobosPG
{
private: 
	static const int PVIS = 70, PDES = 30, DT = 5, AP = 5;
	//Para la imagen, textura y rectangulo.
	bool visible, explotado;
	TexturasSDL* pTexture;
	SDL_Rect rect;
	int puntos, x, y;
public:
	GlobosPG(TexturasSDL * img, int px, int py);
	~GlobosPG();
	void draw(SDL_Renderer* pRenderer) const;
	bool OnClick(int pmx, int pmy);
	void update();
	bool pinchado() { return explotado; };
	int getPuntos() { return puntos; };
	int getX() { return x; };
	int getY() { return y; };
};

