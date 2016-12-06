#include "ObjetoPG.h"


ObjetoPG::ObjetoPG(){}

//Constructora herencia
ObjetoPG::ObjetoPG(int x, int y, JuegoPG::Texturas_t textura, JuegoPG*juego): x(x), y(y), textura(textura), juego(juego){
	rect.x = x;
	rect.y = y;
	rect.w = juego->getTexturas(textura)->getW();
	rect.h = juego->getTexturas(textura)->getH();
}

ObjetoPG::~ObjetoPG(){}

bool ObjetoPG::dentro(int pmx, int pmy) const {
	int xtotal = (rect.x + rect.w);
	int ytotal = (rect.y + rect.h);
	return (visible && pmx < xtotal && pmx > x && pmy < ytotal && pmy > y);
}
void ObjetoPG::draw() {
	if (visible) {
		rect.x = x;
		rect.y = y;
	}
}
