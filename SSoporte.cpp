#include "SSoporte.h"

SSoporte::SSoporte(string nom, int pvida, int pfuerza, int pblindaje, int pcamuflaje){
	nombre = nom;
	vida = pvida;
	fuerza = pfuerza;
	blindaje = pblindaje;
	camuflaje = pcamuflaje;
}
		
int SSoporte::getBlindaje(){
	return blindaje;
}
int SSoporte::getCamuflaje(){
	return camuflaje;
}
int SSoporte::Ataque(bool tipo){//true = asalto, false = soporte
	int retValue=0;
	
	if(tipo){
		retValue = fuerza * (15+camuflaje);
	}else{
		retValue = fuerza * (10);
	}
	
	return retValue;
}
int SSoporte::Defensa(int ataque, bool tipo){//true = asalto, false = soporte
	int retValue=0;
	
	if(tipo){
		retValue = ataque/(blindaje*2);
	}else{
		retValue = ataque;
	}
	
	return retValue;
}
