#pragma once
/*#ifndef _H_Premio_H_
#define _H_Premio_H_*/
#include "ObjetoPG.h"

class Premio : public ObjetoPG {
public:
	Premio(int px, int py, JuegoPG::Texturas_t text, JuegoPG * j);
	virtual ~Premio();
	void restart();
	virtual void update();
	virtual bool OnClick();
	virtual void draw();
private:
	int toques;
};

//#endif
