//Borja Cano
#include "JuegoPG.h"


int main(int argc, char* args[]){
	JuegoPG* j = new JuegoPG;//Creamos una variable de tipo juego para que herede los metodos y pollas
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//Esto hay ponerlo. Es para que no deje basura
	if (!(j->error))//Llamamos al método de detección de errores antes de arrancalo
		j->run();//Si no ha habido un error, arrancamos el juego
	return 0;
	system("PAUSE");
}