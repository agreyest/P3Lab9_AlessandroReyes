#ifndef SOLDADO_H
#define SOLDADO_H
#include <string>
using namespace std;

class Soldado{
	public:
		Soldado();
		
		int getVida();
		int getFuerza();
		virtual int Ataque() =0;
		virtual int Defensa() =0;
		
	protected:
		string nombre;
		int vida;
		int fuerza;
};

#endif
