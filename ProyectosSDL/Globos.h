//#ifdef H_GlobosPG_H
//#define H_GlobosPG_H
#pragma once

#include "ObjetoPG.h"
#include <iostream>  // la consola: cin / cout
using namespace std; // Para cualificar automaticamente con std:: los identificadores de la librería estandar 


class Globos
{
private: 
	
	//Para la imagen, textura y rectangulo.
	bool visible, explotado;
	TexturasSDL* pTexture;
	SDL_Rect rect;
	int puntos, x, y;
public:
	Globos(int px, int y, JuegoPG::Texturas_t texture, JuegoPG * game);
	virtual ~Globos();
	virtual void draw(SDL_Renderer* pRenderer) const;
	virtual bool OnClick(int pmx, int pmy);
	virtual void update();
	bool pinchado() { return explotado; };
	int getPuntos() { return puntos; };
	int getX() { return x; };
	int getY() { return y; };
};
//#endif

