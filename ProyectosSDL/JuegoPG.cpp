#include "JuegoPG.h"
//#include "checkML.h"
#include "Globos.h"
#include "Premio.h"
#include "Mariposa.h"

using namespace std;

JuegoPG::JuegoPG() {
	//Inicializamos variables y punteros
	pWin = nullptr;
	pRenderer = nullptr;
	initSDL();
	vecTexturas.reserve(4);
	Sprites.reserve(5);
	/*Sprites.push_back("..\\bmps\\globete1.png");
	Sprites.push_back("..\\bmps\\globete2.png");
	Sprites.push_back("..\\bmps\\fondo.png");
	Sprites.push_back("..\\bmps\\mariposa.png");
	Sprites.push_back("..\\bmps\\premio.png");*/
	contGlobos = 10;
	contMar = 1;

	puntos = 0;
	aux = 0;
	Objetos.resize(contGlobos + contMar /* x2 */);
	initMedia();
	initObjetos();
	/*for (size_t i = 0;i < vecTexturas.size(); i++) {
		vecTexturas[i] = new TexturasSDL;
		vecTexturas[i]->load(pRenderer);
	}*/
	pTexture, pColor = nullptr;
	error = gameover = exit = pausa =  false;
}


JuegoPG::~JuegoPG()
{
	freeMedia();
	closeSDL();
}

//Perf
void JuegoPG::run(){
	SDL_HideWindow(pWin);
	if (!error) {
		Uint32 MSxUpdate = 500;
		cout << "PLAY \n";
		Uint32 lastUpdate = SDL_GetTicks();
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Start", "¿Desea empezar?", nullptr);

		SDL_ShowWindow(pWin);
		render(/*pRenderer, pTexture*/);
		handle_events();
		while (!exit && !gameover) {
			if (!pausa && SDL_GetTicks() - lastUpdate >= MSxUpdate) {
				update();
				lastUpdate = SDL_GetTicks();
				if (contGlobos == 0) {
					gameover = true;
				}
			}
			render();
			handle_events();			
		}
		if (exit) { 
			cout << "EXIT \n"; 
		} else { 
			closeSDL();
			cout << "Has obtenido " << puntos << " puntos\n";
			string points = "Puntos: ";
			points += to_string(puntos);
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Game Over", points.c_str(), nullptr);
		}
		SDL_Delay(1000); //cin.get();
	}
}



bool JuegoPG::initSDL() {

	bool success = true;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "SDL could not initialize! \nSDL_Error: " << SDL_GetError() << '\n';
		success = false;
	}
	else {
		pWin = SDL_CreateWindow("Practica 1 Borja Cano", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (pWin == nullptr) {
			cout << "Window could not be created! \nSDL_Error: " << SDL_GetError() << '\n';
			success = false;
		}
		else {
			//Get window surface:
			pRenderer = SDL_CreateRenderer(pWin, -1, SDL_RENDERER_ACCELERATED);
			SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255); //Set background color to black 
			if (pRenderer == nullptr) {
				cout << "Renderer could not be created! \nSDL_Error: " << SDL_GetError() << '\n';
				success = false;
			}
		}
	}

	return success;
}
void JuegoPG::closeSDL() {

	SDL_DestroyRenderer(pRenderer);
	pRenderer = nullptr;

	SDL_DestroyWindow(pWin);
	pWin = nullptr;

	SDL_Quit();
}

//Perfect
bool JuegoPG::initObjetos() {
	srand(SDL_GetTicks());
	int aux1, aux2;
	for (size_t i = 0; i < contGlobos; i++) {
		rndPos(aux1, aux2);
		Objetos.push_back(new Globos(aux1, aux2, TGlobo, this));
	}
	rndPos(aux1, aux2);
	Objetos.push_back(new Mariposa(aux1, aux2, TMariposa, this));
	//El vecGlobos hay que cambiarlo por un vector general para todos los objetos.
}

//Para crear elementos en el initMedia.
void JuegoPG::initMedia() {
	for (size_t i = 0; i < 5; i++)
	{
		vecTexturas.push_back(new TexturasSDL());
		vecTexturas[i]->load(pRenderer, Sprites[i]);
	}
}

//Para eliminar los elem creados en el initMedia
void JuegoPG::freeMedia() {
	unsigned int i = 0;
	for (; i < Objetos.size(); i++) {
		if (Objetos[i] != nullptr) {
			delete Objetos[i];
			Objetos[i] = nullptr;
		}
	}
	for (i = 0 ; i < vecTexturas.size(); i++) {
		delete vecTexturas[i];
		vecTexturas[i] = nullptr;
	}
}

//Done render
void JuegoPG::render(/*SDL_Renderer* pRenderer, SDL_Texture* pTexture*/) {

	//Clear the window to background color 
	SDL_RenderClear(pRenderer);

	// Draw objets 
	for (size_t i = 0; i < Objetos.size(); i++) {
		if (!Objetos[i]->pinchado) {
			Objetos[i]->draw();
		}
	}  // nullptr, nullptr -> toda la textura en toda la ventana

	//Show the window
	SDL_RenderPresent(pRenderer);
}

//Perf
void JuegoPG::handle_events() {

	while (SDL_PollEvent(&e) && !exit) {
		if (e.type == SDL_QUIT) exit = true;

		else if (e.type == SDL_MOUSEBUTTONUP) {
			if (e.button.button == SDL_BUTTON_LEFT) {
				onClick(e.button.x, e.button.y);
				cout << "CLICK ";
			}
		}
		else if (e.key.keysym.sym == SDLK_p){
			aux++;
			pausa = (aux % 2 == 0);
		}
	}
}

//Perf
void JuegoPG::onClick(int pmx, int pmy) {
	mousex = pmx;
	mousey = pmy;
	bool pinchado = false;
	size_t i = Objetos.size() - 1;
	while (!pinchado && i >= 0) {
		if (Objetos[i] != nullptr) {
			if (Objetos[i]->OnClick(mousex, mousey)) {
				pinchado = true;
				if (!Objetos[i]->live()) {
					delete Objetos[i];
					Objetos[i] = nullptr;
				}
			}
		}
		i--;
	}
}

//Done update
void JuegoPG::update() {
	size_t i = 0;
	for (; i < Objetos.size(); i++) {
		if (!Objetos[i]->pinchado())
			Objetos[i]->update();
	}
}

//Perf
void JuegoPG::destroid(ObjetoJuego * p) {
	p->live = false;
	if (typeid(*p) == typeid(Globos)) contGlobos--;
	else if (typeid(*p) == typeid(Mariposa)) contMar--;
}

//Perf	
void JuegoPG::newPremio() {
	int x, y;
	rndPos(x, y);
	Objetos.push_back(new Premio(x, y, TPremio, this));

}
void JuegoPG::rndPos(int &x, int &y) {
	//Calculamos posiciones aleatorias para el objeto dentro de la ventana
	x = rand() % SCREEN_WIDTH;
	y = rand() % SCREEN_HEIGHT;


	//Nos aseguramos que el Objeto no esté justo en el borde
	int margen = 100;
	//Control x
	if (x > SCREEN_WIDTH - margen) { x = SCREEN_WIDTH - margen; }
	else if (x < margen) { x = margen; }
	//Control y
	if (y > SCREEN_HEIGHT - margen) { y = SCREEN_HEIGHT - margen; }
	else if (y < margen) { y = margen; }
}

//Perf
void JuegoPG::sumaPuntos(ObjetoJuego* p) {
	int aux = p->getPuntos();
	puntos += aux;
	cout << aux << " puntos/n";
}