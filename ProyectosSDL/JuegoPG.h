#pragma once
#include "SDL.h" 
#include <string>
#include "TexturasSDL.h"
#include "GlobosPG.h"
#include <iostream>
#include <vector>
using namespace std;

class JuegoPG
{
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
public:
	JuegoPG();
	~JuegoPG();
	void run();
	bool error;
private:
	bool gameover, pausa, exit;
	int contGlobos, puntos, aux;
	SDL_Event e;
	vector<TexturasSDL*> vecTexturas;
	vector<GlobosPG*> vecGlobos;
	SDL_Window * pWin;
	SDL_Renderer * pRenderer;
	SDL_Texture *pTexture;
	SDL_Color* pColor;


	
	bool initSDL(SDL_Window* &pWindow, SDL_Renderer* &pRenderer);
	void closeSDL(SDL_Window* & pWindow, SDL_Renderer* & pRenderer);
	bool initGlobos();//Éstos métodos los he dejado aquí porque lo pone en la especificación
	void freeGlobos();//Aunque no les encuentro el sentido porque su función ya la cumple el contructor de Juego
	void render(SDL_Renderer* pRenderer, SDL_Texture* pTexture);
	void onClick(int pmx, int pmy);
	void update();
	void handle_events();
};

