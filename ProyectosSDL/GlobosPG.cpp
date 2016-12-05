#include "GlobosPG.h"

GlobosPG::GlobosPG(TexturasSDL * img, int px, int py){
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
}
GlobosPG::~GlobosPG(){}

void GlobosPG::draw(SDL_Renderer* pRenderer)const{
	if (visible && !explotado)
		SDL_RenderCopy(pRenderer, pTexture->pTextura, nullptr, &rect);
}
bool GlobosPG::OnClick(int pmx, int pmy) {
	bool esta = false;
	int xtotal = x + pTexture->getW();
	int ytotal = y + pTexture->getH();
	if (visible && !explotado && pmx < xtotal && pmx > x && pmy < ytotal && pmy > y) {
		explotado = esta = true;
		cout << "Pum";
	}
		
	return esta;
}
void GlobosPG::update() {
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