#include "Premio.h"


Premio::Premio(int px, int py, JuegoPG::Texturas_t text, JuegoPG * j): ObjetoPG(px, py, text, j), oportunidades(0) {
	visible = true;
	rect.h = 50;
	rect.w = 50;
	puntos = 20;
}

Premio::~Premio() {}

void Premio::update() {}
void Premio::restart() {}

void Premio::draw() {
	j->getTextura(t)->draw(j->getRender(), rect);
}

bool Premio::OnClick() {
	bool devolver;
	if (ObjetoPG::OnClick()) {
		j->newPuntos(this);
		j->newBaja(this); //Revisar que es esta shit
		return true;
	} else {
		if (/*oportunidades*/ toques < 3) toques++;
		else { j-> newBaja(this); }
		return false;
	}
}
