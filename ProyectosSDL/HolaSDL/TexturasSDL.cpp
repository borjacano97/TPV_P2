#include "TexturasSDL.h"



TexturasSDL::TexturasSDL()
{
	pTextura = nullptr;
	pRenderer = nullptr;

}


TexturasSDL::~TexturasSDL()
{
}
int TexturasSDL::getH(){ return h; };
int TexturasSDL::getW(){ return w; };

bool TexturasSDL::load(SDL_Renderer* pRenderer){
	SDL_Surface* pTempSurface = nullptr;
	bool success = true;  //Flag de exito y return

	//Cargar imagen
	pTempSurface = IMG_Load("..\\bmps\\globo.png");  // si usamos string: bmpName.c_str() 
	if (pTempSurface == nullptr) {
		cout << "Unable to load image " << "globo.png" << "! \nSDL Error: " << SDL_GetError() << '\n';
		success = false;
	}
	else {
		pTextura = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
		h = pTempSurface->h;
		w = pTempSurface->w;
		SDL_FreeSurface(pTempSurface);
		success = pTextura != nullptr;
	}

	return success;
}
void TexturasSDL::Draw(SDL_Renderer* pRenderer, SDL_Rect const& rect){
	SDL_RenderCopy(pRenderer, pTextura, nullptr, nullptr);
}