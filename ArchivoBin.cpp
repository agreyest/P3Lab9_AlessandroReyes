#include "ArchivoBin.h"
#include <sstream>
using std::stringstream;

ArchivoBin::ArchivoBin(string pFileName){
	fileName = pFileName;
}


bool ArchivoBin::abrirLectura(){
	inputFile.open(fileName.c_str(),std::ios::binary);
	return inputFile.is_open();
}

bool ArchivoBin::abrirEscritura(int modo){
	modoEscritura = modo;
	if(modoEscritura == 1)//append
		outputFile.open(fileName.c_str(), std::ios::app | std::ios::binary);
	else
		outputFile.open(fileName.c_str(), std::ios::binary);
			
	return outputFile.is_open();
}


vector<Soldado*> ArchivoBin::leerSoldado(int tip){
	 vector<Soldado*> retValue;
	 
	 
	 while(!inputFile.eof()){
	 	int nameSize=0;
	 	int vida=0; 
	 	int fuerza=0;
	 	int velocidad=0;
	 	int extra=0;
	 	int blindaje=0;
	 	int camuflaje=0;
	 	
		int tipo=-1;
	 	inputFile.read(reinterpret_cast<char*>(&tipo),sizeof(int));
	 	
	 	
	 	
	 	//leer el tamaño del nombre 
	 	inputFile.read(reinterpret_cast<char*>(&nameSize),sizeof(int));
		 	
		char buffer[100];
		//leer el nombre
		inputFile.read(buffer,nameSize);
		 	
	 	string nombre = buffer;
		 	
		//leer la vida
		inputFile.read(reinterpret_cast<char*>(&vida),sizeof(int));
		
		//leer la fuerza
		inputFile.read(reinterpret_cast<char*>(&fuerza),sizeof(int));
		
		if(tipo == tip){
			if(fileName == "Asalto.Bin"){
				//leer la volocidad
				inputFile.read(reinterpret_cast<char*>(&velocidad),sizeof(int));
				//leer la fuerza extra
				inputFile.read(reinterpret_cast<char*>(&extra),sizeof(int));
				
				retValue.push_back(new SAsalto(nombre,vida, fuerza, velocidad, extra));
			}else{
				//leer la blindaje
				inputFile.read(reinterpret_cast<char*>(&blindaje),sizeof(int));
				//leer la camuflaje
				inputFile.read(reinterpret_cast<char*>(&camuflaje),sizeof(int));
				
				retValue.push_back(new SSoporte(nombre,vida, fuerza, blindaje, camuflaje));
			}
			
		}else if(tipo == tip){
			if(fileName == "Asalto.Bin"){
				//leer la volocidad
				inputFile.read(reinterpret_cast<char*>(&velocidad),sizeof(int));
				//leer la fuerza extra
				inputFile.read(reinterpret_cast<char*>(&extra),sizeof(int));
				
				retValue.push_back(new SAsalto(nombre,vida, fuerza, velocidad, extra));
			}else{
				//leer la blindaje
				inputFile.read(reinterpret_cast<char*>(&blindaje),sizeof(int));
				//leer la camuflaje
				inputFile.read(reinterpret_cast<char*>(&camuflaje),sizeof(int));
				
				retValue.push_back(new SSoporte(nombre,vida, fuerza, blindaje, camuflaje));
			}
			
		}
		
	 }
	 
	 return retValue; 
}

bool ArchivoBin::guardarSoldado(vector<Soldado*> soldados, bool ver, int tipo){//tipo == 1 es aliado, ==2 es enemigo
 	if(outputFile.is_open()){
 	    for(int i = 0; i < soldados.size(); i++){
 			SAsalto *pA = dynamic_cast<SAsalto*>(soldados[i]);
						
			if(pA == 0 && !ver){//es un soldado de soporte
				SSoporte *pS = dynamic_cast<SSoporte*>(soldados[i]);
				int sizeNombre = pS->nombre.size();
				
				//guardar si es enemigo o aliado
				outputFile.write(reinterpret_cast<char*>(&tipo), (int)sizeof(int) );
				
				
				//guardar size nombre
		 		outputFile.write(reinterpret_cast<char*>(&sizeNombre), (int)sizeof(int) );
		 		
				//guardar el nombre 
				outputFile.write(pS->nombre.data(),sizeNombre);
				
				//guardar vida
		 		outputFile.write(reinterpret_cast<char*>(&pS->vida), (int)sizeof(int) );
		 		
		 		//guardar fuerza
		 		outputFile.write(reinterpret_cast<char*>(&pS->fuerza), (int)sizeof(int) );
		 		
		 		//guardar blindaje
		 		outputFile.write(reinterpret_cast<char*>(&pS->blindaje), (int)sizeof(int) );
		 		
		 		//guardar camuflaje
		 		outputFile.write(reinterpret_cast<char*>(&pS->camuflaje), (int)sizeof(int) );
							
			}else if(pA != 0 && ver){// es un soldado de asalto
				int sizeNombre = pA->nombre.size();
				
				//guardar si es enemigo o aliado
				outputFile.write(reinterpret_cast<char*>(&tipo), (int)sizeof(int) );
				
		 		//guardar size nombre
		 		outputFile.write(reinterpret_cast<char*>(&sizeNombre), (int)sizeof(int) );
		 		
				//guardar el nombre 
				outputFile.write(pA->nombre.data(),sizeNombre);
				
				//guardar vida
		 		outputFile.write(reinterpret_cast<char*>(&pA->vida), (int)sizeof(int) );
		 		
		 		//guardar fuerza
		 		outputFile.write(reinterpret_cast<char*>(&pA->fuerza), (int)sizeof(int) );
		 		
		 		//guardar velocidad
		 		outputFile.write(reinterpret_cast<char*>(&pA->velocidad), (int)sizeof(int) );
		 		
		 		//guardar fuerza extra
		 		outputFile.write(reinterpret_cast<char*>(&pA->fuerzaex), (int)sizeof(int) );
			}
 			
 		}
 		
				
		return true;
	}else
		return false;		
}

bool ArchivoBin::cerrarEscritura(){
	outputFile.close();
	return !outputFile.is_open();
}

bool ArchivoBin::cerrarLectura(){
	inputFile.close();
	return !inputFile.is_open();
}


