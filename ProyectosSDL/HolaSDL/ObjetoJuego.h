//#ifdef H_ObjetoJuego_H
//#define H_ObjetoJuego_H
class ObjetoJuego
{
public:
	bool live = true;

	ObjetoJuego() {};
	virtual ~ObjetoJuego() {};
	virtual void draw() {};
	virtual void update() {};
	virtual bool onClick() {};
	virtual int getPuntos() {};
	bool live() { return live;}
	
};
//#endif

