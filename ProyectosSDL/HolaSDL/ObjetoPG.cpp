#include "ObjetoPG.h"


ObjetoPG::ObjetoPG(){}

//Constructora herencia
ObjetoPG::ObjetoPG(int x, int y, JuegoPG::Texturas_t textura, JuegoPG * juego): x(x), y(y), textura(textura), juego(juego){
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
void ObjetoPG::draw() {}

bool ObjetoPG::onClick() {
	//Cada juego lo interpreta a su manera
	int pmx, pmy;
	juego->getMousePos(pmx, pmy);
	return visible && dentro(pmx, pmy);
}

int ObjetoPG::getPuntos() {
	return puntos;
}
