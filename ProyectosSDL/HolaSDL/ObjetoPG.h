//#ifdef H_ObjetoPG_H
//#define H_ObjetoPG_H
#include <SDL.h>
#include "ObjetoJuego.h"
#include "JuegoPG.h"

class ObjetoPG : public ObjetoJuego{

public:
	ObjetoPG();
	virtual ~ObjetoPG() {};
	virtual bool onClick();
	virtual void draw();
	virtual int getPuntos();
protected:
	ObjetoPG(int x, int y, JuegoPG::Texturas_t t, JuegoPG * juego);
	bool dentro(int x, int y) const;
	int x, y, puntos;
	bool visible;
	SDL_Rect rect;
	JuegoPG * juego;
	JuegoPG::Texturas_t textura;

};
//#endif // H_ObjetoPG_H

