#pragma once
#ifndef _H_Mariposa_H_
#define _H_Mariposa_H_

#include "ObjetoPG.h"
#include "JuegoPG.h"

class Mariposa {
private:
	int numclicks;
	int frameactual;
	int velX, velY;
public:
	Mariposa(int px, int py, JuegoPG::Texturas_t text, JuegoPG * j);
	~Mariposa();
	virtual bool onClick();
	virtual bool update();
	virtual void draw();
};

#endif 

