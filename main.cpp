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
#include "ArchivoBin.h"

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
	int  opcion = menu1();
	int seguir = 1;
	
	while(seguir == 1){
		switch(opcion){
			case 1:{//crear soldado
				
				break;
			}//fin case1
			
			case 2:{//eliminar soldado
				
				break;
			}//fin case2
			
			case 3:{//lista soldados
				
				break;
			}//fin case3
			
			case 4:{//guardar soldados
				
				break;
			}//fin case4
			
			case 5:{//cargar soldados
				
				break;
			}//fin case5
			
			case 6:{//simulacion
				
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
