//#ifdef H_ObjetoJuego_H
//#define H_ObjetoJuego_H
class ObjetoJuego
{
public:
	ObjetoJuego() {};
	virtual ~ObjetoJuego() {};
	virtual void draw() {};
	virtual void update() {};
	virtual bool onClick() {};
	virtual int getPuntos() {};
};
//#endif

