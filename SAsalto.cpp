#include "SAsalto.h"

SAsalto::SAsalto(string nom, int pvida, int pfuerza, int pvelocidad, int pfuerzaex){
	nombre = nom;
	vida = pvida;
	fuerza = pfuerza;
	velocidad = pvelocidad;
	fuerzaex = pfuerzaex;
}
		
int SAsalto::getVelocidad(){
	return velocidad;
}
int SAsalto::getExtra(){
	return fuerzaex;
}
int SAsalto::Ataque(bool tipo){//true = asalto, false = soporte
	int retValue=0;
	
	if(tipo){
		retValue = fuerza * 10;
	}else{
		retValue = fuerza * (10+(velocidad*2));
	}
	
	return retValue;
}
int SAsalto::Defensa(int ataque, bool tipo){//true = asalto, false = soporte
	int retValue=0;
	
	if(tipo){
		retValue = ataque;
	}else{
		retValue = ataque/fuerzaex;
	}
	
	return retValue;
}
