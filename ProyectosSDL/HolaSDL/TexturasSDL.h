#pragma once
#include "SDL.h" 
#include <string>
#include <iostream>
#include "SDL_image.h"
using namespace std;

class TexturasSDL{
	int h, w;
public:
	SDL_Texture* pTextura;
	SDL_Renderer* pRenderer;
	TexturasSDL();
	~TexturasSDL();
	int getH();
	int getW();

	bool load(SDL_Renderer* pTextura);

	void Draw(SDL_Renderer* pTextura, SDL_Rect const& rect);

};

