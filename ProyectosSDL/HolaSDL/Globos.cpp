#include "Globos.h"
#include "SDL.h"
//#include "checkML.h"
#include <iostream>


Globos::Globos(int px, int y, JuegoPG::Texturas_t texture, JuegoPG * game): ObjetoPG(px, py, texture, game) {
	puntos = 1;
	rect.w = game->getTexturas(texture)->getW();
	rect.h = game->getTexturas(texture)->getH();
}
/*Globos::Globos(TexturasSDL * img, int px, int py){
	visible = true;
	explotado = false;
	puntos = 1;
	pTexture = img;
	x = px;
	y = py;
	rect.x = px;
	rect.y = py;
	rect.w = pTexture->getW();
	rect.h = pTexture->getH();
}*/
Globos::~Globos() {}

void Globos::draw() {
	j->getTextura(textura)->draw(juego->getRender(), rect);
}
/*void Globos::draw(SDL_Renderer* pRenderer)const{
	if (visible && !explotado)
		SDL_RenderCopy(pRenderer, pTexture->pTextura, nullptr, &rect);
}*/ 

bool Globos::OnClick(int pmx, int pmy) {
	if (ObjetoPG::onClick()) {
		juego->newPuntos(this);
		juego->newBaja(this);
		return true;
	}
	else
		return false;
}

void Globos::update() {
	if (rand() % 100 < PVIS) visible = true;
	else visible = false;

	if (rand() % 100 < PDES) {
		puntos += AP;
		rect.w -= DT;
		rect.h -= DT;
	}
	if (rect.w <= 0 || rect.h <= 0)
		explotado = true;
};