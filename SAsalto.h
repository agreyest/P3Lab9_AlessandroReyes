#ifndef SASALTO_H
#define SASALTO_H

#include "Soldado.h"

class SAsalto: public Soldado{
	public:
		SAsalto(string, int, int, int, int);
		
		int getVelocidad();
		int getExtra();
		int Ataque(bool);//true = asalto, false = soporte
		int Defensa(int, bool);//true = asalto, false = soporte
		
	protected:
		int velocidad;
		int fuerzaex;
};

#endif
