#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

#include "Soldado.h"
#include "SAsalto.h"
#include "SSoporte.h"
//#include "ArchivoBin.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int menu1(){
	int retValue=0;
	while(retValue < 1 || retValue > 4){
		cout<<"		Guerra		"<<endl
			<<"  1.- Crear soldado"<<endl
			<<"  2.- Eliminar soldado"<<endl
			<<"  3.- Listar soldados"<<endl
			<<"  4.- Guardar soldados"<<endl
			<<"  5.- Cargar soldados"<<endl
			<<"  6.- Simulacion"<<endl
			<<"  7.- Salir"<<endl
			<<"Que opcion desea ver: ";
			
			cin>>retValue;
			
			if(retValue >= 1 && retValue <= 4){
				break;
			}else{
				cout<<endl<<"Opcion ingresada incorrecta, elija nuevamente"<<endl;
			}
			
			
	}//end while
	
	return retValue;
}//fin metodo de menu


int main(int argc, char** argv) {
	vector<Soldado*> aliados;
	vector<Soldado*> enemigos;
	
	int  opcion = menu1();
	int seguir = 1;
	
	while(seguir == 1){
		switch(opcion){
			case 1:{//crear soldado
				int bando;
				cout<<"A que bando desea agregarle soldados "<<endl
				<<"1. Aliados: "<<endl
				<<"2. Enemigos: "<<endl
				<<"Escriba el numero: ";
				cin>>bando;
				
				int eleccion;
				cout<<"Que tipo de soldado desea crear "<<endl
				<<"1. Soldado de asalto: "<<endl
				<<"2. soldado de soporte: "<<endl
				<<"Escriba el numero: ";
				cin>>eleccion;
				
				if(bando==1){//aliados
					if(eleccion==1){
						string nombre;
						cout<<"Cual es el nombre de su soldado de asalto: ";
						cin>>nombre;
						
						int vida;
						cout<<"cuantos puntos de vida tendra su soldado de asalto: ";
						cin>>vida;
						
						int fuerza;
						cout<<"Cuantos puntos de fuerza tendra su soldado de asalto: ";
						cin>>fuerza;
						
						int velocidad;
						cout<<"cuantos puntos de velocidad tendra su soldado de asalto: ";
						cin>>velocidad;
						
						int extra;
						cout<<"Cuantos puntos de fuerza extra tendra su soldado de asalto: ";
						cin>>extra;
						
						aliados.push_back(new SAsalto(nombre, vida, fuerza, velocidad, extra) );
					}else if(eleccion == 2){
						string nombre;
						cout<<"Cual es el nombre de su soldado de soporte: ";
						cin>>nombre;
						
						int vida;
						cout<<"cuantos puntos de vida tendra su soldado de soporte: ";
						cin>>vida;
							
						int fuerza;
						cout<<"Cuantos puntos de fuerza tendra su soldado de soporte: ";
						cin>>fuerza;
							
						int blindaje;
						cout<<"cuantos puntos de blindaje tendra su soldado de soporte: ";
						cin>>blindaje;
						
						int camuflaje;
						cout<<"Cuantos puntos de camuflaje tendra su soldado de soporte: ";
						cin>>camuflaje;
							
						aliados.push_back(new SSoporte(nombre, vida, fuerza, blindaje, camuflaje) );
					}else{
						cout<<"Opcion de soldado ingresada incorrecta"<<endl;
					}
				
					
				}else if(bando == 2){//enemigos
					if(eleccion==1){
						string nombre;
						cout<<"Cual es el nombre de su soldado de asalto: ";
						cin>>nombre;
						
						int vida;
						cout<<"cuantos puntos de vida tendra su soldado de asalto: ";
						cin>>vida;
						
						int fuerza;
						cout<<"Cuantos puntos de fuerza tendra su soldado de asalto: ";
						cin>>fuerza;
						
						int velocidad;
						cout<<"cuantos puntos de velocidad tendra su soldado de asalto: ";
						cin>>velocidad;
						
						int extra;
						cout<<"Cuantos puntos de fuerza extra tendra su soldado de asalto: ";
						cin>>extra;
						
						enemigos.push_back(new SAsalto(nombre, vida, fuerza, velocidad, extra) );
					}else if(eleccion == 2){
						string nombre;
						cout<<"Cual es el nombre de su soldado de soporte: ";
						cin>>nombre;
						
						int vida;
						cout<<"cuantos puntos de vida tendra su soldado de soporte: ";
						cin>>vida;
						
						int fuerza;
						cout<<"Cuantos puntos de fuerza tendra su soldado de soporte: ";
						cin>>fuerza;
						
						int blindaje;
						cout<<"cuantos puntos de blindaje tendra su soldado de soporte: ";
						cin>>blindaje;
						
						int camuflaje;
						cout<<"Cuantos puntos de camuflaje tendra su soldado de soporte: ";
						cin>>camuflaje;
						
						enemigos.push_back(new SSoporte(nombre, vida, fuerza, blindaje, camuflaje) );
					}else{
						cout<<"Opcion de soldado ingresada incorrecta"<<endl;
					}
					
				}else{
					cout<<"Opcion de bando ingresada incorrecta"<<endl;
				}
				
				break;
			}//fin case1
			
			case 2:{//eliminar soldado
				cout<<"Antes de eliminar, vea la opcion de lista para saber que numero elijira."<<endl;
				
				int bando;
				cout<<"Que bando desea listar "<<endl
				<<"1. Aliados: "<<endl
				<<"2. Enemigos: "<<endl
				<<"Escriba el numero: ";
				cin>>bando;
				
				if(bando==1){//aliados
					int borrar;
					cout<<"ingrese el numero del soldado que desea borrar: ";
					cin>>borrar;
					
					if(borrar >= 0 && borrar < aliados.size()){
						aliados.erase(aliados.begin() + borrar);
					}else{
						cout<<"Numero ingresado incorrecto."<<endl;
					}
					
				}else if(bando == 2){//enemigos
					int borrar;
					cout<<"ingrese el numero del soldado que desea borrar: ";
					cin>>borrar;
					
					if(borrar >= 0 && borrar < enemigos.size()){
						enemigos.erase(enemigos.begin() + borrar);
					}else{
						cout<<"Numero ingresado incorrecto."<<endl;
					}
					
				}else{
					cout<<"Opcion de bando ingresada incorrecta"<<endl;
				}
				
				break;
			}//fin case2
			
			case 3:{//lista soldados
				int bando;
				cout<<"Que bando desea listar "<<endl
				<<"1. Aliados: "<<endl
				<<"2. Enemigos: "<<endl
				<<"Escriba el numero: ";
				cin>>bando;
				
				if(bando==1){//aliados
					cout<<"LISTA DE ALIADOS"<<endl;
					for(int i = 0; i < aliados.size(); i++){
						SAsalto *pA = dynamic_cast<SAsalto*>(aliados[i]);
						
						if(pA == 0){//es un soldado de soporte
							SSoporte *pS = dynamic_cast<SSoporte*>(aliados[i]);
							cout<<(i)<<") Nombre: "<<pS->getNombre()<<", vida = "<<pS->getVida()
							<<", Fuerza= "<<pS->getFuerza()<<", Blindaje= "<<pS->getBlindaje()
							<<", Camuflaje= "<<pS->getCamuflaje()<<endl;
							
						}else{// es un soldado de asalto
							cout<<(i)<<") Nombre: "<<pA->getNombre()<<", vida = "<<pA->getVida()
							<<", Fuerza= "<<pA->getFuerza()<<", Velocidad= "<<pA->getVelocidad()
							<<", Fuerza extra= "<<pA->getExtra()<<endl;
						}
						
					}
					
				}else if(bando == 2){//enemigos
					cout<<"LISTA DE ENEMIGOS"<<endl;
					for(int i = 0; i < enemigos.size(); i++){
						SAsalto *pA = dynamic_cast<SAsalto*>(enemigos[i]);
						
						if(pA == 0){//es un soldado de soporte
							SSoporte *pS = dynamic_cast<SSoporte*>(enemigos[i]);
							cout<<(i)<<") Nombre: "<<pS->getNombre()<<", vida = "<<pS->getVida()
							<<", Fuerza= "<<pS->getFuerza()<<", Blindaje= "<<pS->getBlindaje()
							<<", Camuflaje= "<<pS->getCamuflaje()<<endl;
							
						}else{// es un soldado de asalto
							cout<<(i)<<") Nombre: "<<pA->getNombre()<<", vida = "<<pA->getVida()
							<<", Fuerza= "<<pA->getFuerza()<<", Velocidad= "<<pA->getVelocidad()
							<<", Fuerza extra= "<<pA->getExtra()<<endl;
						}
					}
					
				}else{
					cout<<"Opcion de bando ingresada incorrecta"<<endl;
				}
				break;
			}//fin case3
			
			case 4:{//guardar soldados
				
				break;
			}//fin case4
			
			case 5:{//cargar soldados
				
				break;
			}//fin case5
			
			case 6:{//simulacion
				cout<<"BIENVENIDO A LA SIMULACION DE LA GUERRA"<<endl;
				while(aliados.size() >0 && enemigos.size() > 0){
					int vid=0;
					//ataque de aliados y defensa del enemigo
					int aliadosSize1 = aliados.size();
					int randomAli1 =(rand()%aliadosSize1);
					int enemigosSize1 = enemigos.size();
					int randomEne1 =(rand()%enemigosSize1);
					
					SAsalto *AA = dynamic_cast<SAsalto*>(aliados[randomEne1]);
					if(AA == 0){//es un soldado de soporte
						int damgAli = aliados[randomAli1]->Ataque(false);	
						
						//defensa enemiga
						SAsalto *DE = dynamic_cast<SAsalto*>(aliados[randomAli1]);
						if(DE == 0){//es un soldado de soporte
							vid = enemigos[randomEne1]->Defensa(damgAli, false);	
								
						}else{// es un soldado de asalto
							vid = enemigos[randomEne1]->Defensa(damgAli, true);
						}	
						
					}else{// es un soldado de asalto
						int damgAli =aliados[randomAli1]->Ataque(true);
						
						//defensa enemiga
						SAsalto *DE = dynamic_cast<SAsalto*>(aliados[randomAli1]);
						if(DE == 0){//es un soldado de soporte
							vid = enemigos[randomEne1]->Defensa(damgAli, false);	
								
						}else{// es un soldado de asalto
							vid = enemigos[randomEne1]->Defensa(damgAli, true);
						}
						
					}
					int vidaEne = enemigos[randomEne1]->getVida();
					enemigos[randomEne1]->setVida(vidaEne - vid);
					if(enemigos[randomEne1]->getVida() <= 0){
						enemigos.erase(enemigos.begin() + randomEne1);
					}
					
					//ataque del enemigo y defensa de aliado
					int aliadosSize2 = aliados.size();
					int randomAli2 =(rand()%aliadosSize2);
					int enemigosSize2 = enemigos.size();
					int randomEne2 =(rand()%enemigosSize2);
					
					SAsalto *AE = dynamic_cast<SAsalto*>(aliados[randomAli2]);
					if(AE == 0){//es un soldado de soporte
						int damgAli = enemigos[randomEne2]->Ataque(false);	
						
						//defensa de aliados
						SAsalto *DA = dynamic_cast<SAsalto*>(aliados[randomAli1]);
						if(DA == 0){//es un soldado de soporte
							vid = aliados[randomAli2]->Defensa(damgAli, false);	
								
						}else{// es un soldado de asalto
							vid = aliados[randomAli2]->Defensa(damgAli, true);
						}	
						
					}else{// es un soldado de asalto
						int damgAli = enemigos[randomEne2]->Ataque(true);
						
						//defensa de aliados
						SAsalto *DA = dynamic_cast<SAsalto*>(aliados[randomAli1]);
						if(DA == 0){//es un soldado de soporte
							vid = aliados[randomAli2]->Defensa(damgAli, false);	
								
						}else{// es un soldado de asalto
							vid = aliados[randomAli2]->Defensa(damgAli, true);
						}
						
					}
					int vidaAli = aliados[randomAli2]->getVida();
					aliados[randomAli2]->setVida(vidaAli - vid);
					if(aliados[randomAli2]->getVida() <= 0){
						aliados.erase(aliados.begin() + randomAli2);
					}
					
				}//fin del while
				
				break;
			}//fin case6
			
			case 7:{
				seguir = 0;
				break;
			}//fin case7
			
		}//fin del switch
		if(seguir == 1){
			opcion = menu1();
		}
	}//fin del while
	
	return 0;
}//fin del main
