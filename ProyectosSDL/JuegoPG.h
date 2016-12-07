#pragma once
#include "SDL.h" 
#include <string>
#include "TexturasSDL.h"
#include <iostream>
#include <time.h>
#include <vector>
//#include "ObjetoJuego.h"
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

	enum Texturas_t {
		TGlobo = 0, TFondo = 1, TMariposa = 2, TPremio = 3
	};
	TexturasSDL * getTextura(Texturas_t et) const {
		return vecTexturas[et];
	};
	SDL_Renderer* getRender() const { return pRenderer; };
	void getMousePos(int &pmx, int &pmy) const {
		pmx = mousex;
		pmy = mousey;
	};
	//void newPuntos(ObjetoJuego* po);
	void newPremio();
	//void newBaja(ObjetoJuego* po);
private:
	bool gameover, pausa, exit;
	int contGlobos, puntos, aux;
	int mousex, mousey;
	SDL_Event e;
	vector<string> Sprites; //dirSprites
	vector<TexturasSDL*> vecTexturas;
	vector<Globos*> Objetos; //vector<ObjetoJuego *>objetos;
	SDL_Rect fond;
	SDL_Window * pWin;
	SDL_Renderer * pRenderer;
	SDL_Texture *pTexture;
	SDL_Color* pColor;


	
	bool initSDL();
	void closeSDL();
	bool initGlobos();//Éstos métodos los he dejado aquí porque lo pone en la especificación
	void freeGlobos();//Aunque no les encuentro el sentido porque su función ya la cumple el contructor de Juego
	void render(/*SDL_Renderer* pRenderer, SDL_Texture* pTexture*/);
	void onClick(int pmx, int pmy);
	void update();
	void handle_events();
	void freeMedia();
	void initMedia();
	bool initObjetos();
	void rndPos(int &x, int &y);
};

