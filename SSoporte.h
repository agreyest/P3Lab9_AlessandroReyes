#ifndef SSOPORTE_H
#define SSOPORTE_H

#include "Soldado.h"

class SSoporte : public Soldado {
	public:
		SSoporte(string, int, int, int, int);
		
		int getBlindaje();
		int getCamuflaje();
		int Ataque(bool);//true = asalto, false = soporte
		int Defensa(int, bool);//true = asalto, false = soporte
		
	protected:
		int blindaje;
		int camuflaje;
};

#endif
