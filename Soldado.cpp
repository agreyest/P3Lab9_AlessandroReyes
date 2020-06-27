#include "Soldado.h"

Soldado::Soldado(string pnombre, int pvida, int pfuerza){
	nombre = pnombre;
	vida = pvida;
	fuerza = pfuerza;
}

int Soldado::getVida(){
	return vida;
}
void Soldado::setVida(int pvida){
	vida = pvida;
}
string Soldado::getNombre(){
	return nombre;
}
int Soldado::getFuerza(){
	return fuerza;
}
