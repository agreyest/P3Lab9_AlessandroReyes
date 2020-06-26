#ifndef SOLDADO_H
#define SOLDADO_H
#include <string>
using namespace std;


class Soldado{
	public:
		
		
		int getVida();
		void setVida(int);
		string getNombre();
		int getFuerza();
		virtual int Ataque(bool) =0;//true = asalto, false = soporte
		virtual int Defensa(int, bool) =0;//true = asalto, false = soporte
		
	protected:
		string nombre;
		int vida;
		int fuerza;
};

#endif
