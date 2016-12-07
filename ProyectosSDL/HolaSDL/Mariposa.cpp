#include "Mariposa.h"


Mariposa::Mariposa(int px, int py, JuegoPG::Texturas_t text, JuegoPG * j) : ObjetoPG(px, py, text, juego), numclicks(0), actualframe(1), velX(5), velY(-3) {
	visible = true;
	puntos = 0;
	rect.h = 50;
	rect.w = 50;
}

Mariposa::~Mariposa()
{
}

bool Mariposa::onClick() {
	if (ObjetoPG::onClick()) {
		juego->newBaja(this);
		juego->newPremio();
		return true;
	}
	else
		return false;
}

void Mariposa::update() {
	rect.x += velX;
	rect.y += velY;
}

void Mariposa::draw() {
	juego->getTextura(t)->draw(juego->getRender(), rect);
}
