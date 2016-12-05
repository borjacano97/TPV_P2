#include "JuegoPG.h"



JuegoPG::JuegoPG()
{
	//Inicializamos variables y punteros
	pWin = nullptr;
	pRenderer = nullptr;
	srand(1);
	initSDL(pWin, pRenderer);

	contGlobos = 10;

	puntos = 0;
	aux = 0;
	vecTexturas.resize(2);
	vecGlobos.resize(contGlobos);
	for (size_t i = 0;i < vecTexturas.size(); i++) {
		vecTexturas[i] = new TexturasSDL;
		vecTexturas[i]->load(pRenderer);
	}
	for (size_t i = 0; i < vecGlobos.size(); i++) {
		vecGlobos[i] = new Globos(vecTexturas[1], rand() % (SCREEN_WIDTH - 50), rand() % (SCREEN_HEIGHT - 50));
	}
	//vecGlobos[0] = new GlobosPG(vecTexturas[1],(SCREEN_WIDTH/2), (SCREEN_HEIGHT/2));
//	vecGlobos[1] = new GlobosPG(vecTexturas[1], (vecGlobos[0]->getX() + (vecTexturas[1]->getW() / 2)), vecGlobos[0]->getY() + (vecTexturas[1]->getH() / 2));
	pTexture, pColor = nullptr;
	error = gameover = exit = pausa =  false;
}


JuegoPG::~JuegoPG()
{
}

void JuegoPG::run(){
	if (!error) {
		Uint32 MSxUpdate = 500;
		cout << "PLAY \n";
		Uint32 lastUpdate = SDL_GetTicks();
		render(pRenderer, pTexture);
		handle_events();
		while (!exit && !gameover) {
			if (!pausa && SDL_GetTicks() - lastUpdate >= MSxUpdate) {
				update();
				lastUpdate = SDL_GetTicks();
			}
			render(pRenderer, pTexture);
			handle_events();			
		}
		if (exit) cout << "EXIT \n";
		else cout << "Has obtenido " << puntos << " puntos\n";
		SDL_Delay(1000); //cin.get();
	}
}
bool JuegoPG::initSDL(SDL_Window* &pWindow, SDL_Renderer* &pRenderer) {

	bool success = true;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "SDL could not initialize! \nSDL_Error: " << SDL_GetError() << '\n';
		success = false;
	}
	else {
		pWindow = SDL_CreateWindow("Practica 1 Borja Cano", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (pWindow == nullptr) {
			cout << "Window could not be created! \nSDL_Error: " << SDL_GetError() << '\n';
			success = false;
		}
		else {
			//Get window surface:
			pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
			SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255); //Set background color to black 
			if (pRenderer == nullptr) {
				cout << "Renderer could not be created! \nSDL_Error: " << SDL_GetError() << '\n';
				success = false;
			}
		}
	}

	return success;
}
void JuegoPG::closeSDL(SDL_Window* & pWindow, SDL_Renderer* & pRenderer) {

	SDL_DestroyRenderer(pRenderer);
	pRenderer = nullptr;

	SDL_DestroyWindow(pWindow);
	pWindow = nullptr;

	SDL_Quit();
}
void JuegoPG::render(SDL_Renderer* pRenderer, SDL_Texture* pTexture) {

	//Clear the window to background color 
	SDL_RenderClear(pRenderer);

	// Draw objets 
	for (size_t i = 0; i < vecGlobos.size(); i++) {
		vecGlobos[i]->draw(pRenderer);
	}  // nullptr, nullptr -> toda la textura en toda la ventana

	//Show the window
	SDL_RenderPresent(pRenderer);
}
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
void JuegoPG::onClick(int pmx, int pmy) {
	for (size_t i = 0; i < vecGlobos.size();i++) {
		if (vecGlobos[i]->OnClick(pmx, pmy))
			puntos += vecGlobos[i]->getPuntos();
	}
}
void JuegoPG::update() {
	size_t i = 0;
	gameover = true;
	for (; i < vecGlobos.size(); i++) {
		vecGlobos[i]->update();
		if (!vecGlobos[i]->pinchado())
			gameover = false;
	}
}