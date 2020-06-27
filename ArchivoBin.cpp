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


vector<Soldado*> ArchivoBin::leerSoldado(){
	 vector<Soldado*> retValue;
	 
	 
	 while(!inputFile.eof()){
	 	int nameSize=0;
	 	int vida=0; 
	 	
	 	
	 	//leer el tamaño del nombre 
	 	inputFile.read(reinterpret_cast<char*>(&nameSize),sizeof(int));
		 	
		char buffer[100];
		//leer el nombre
		inputFile.read(buffer,nameSize);
		 	
	 	string nombre = buffer;
		 	
		//leer la edad
		inputFile.read(reinterpret_cast<char*>(&vida),sizeof(int));
		 	
		retValue.push_back(new Soldado(nombre,vida, 150));
		 
	 	
	 	
	 }
	 
	 return retValue; 
}

bool ArchivoBin::guardarSoldado(vector<Soldado*> soldados){
 	if(outputFile.is_open()){
 		for(int i = 0; i < soldados.size(); i++){
 			int sizeNombre = soldados[i]->nombre.size();
	 		//guardar size nombre
	 		outputFile.write(reinterpret_cast<char*>(&sizeNombre), (int)sizeof(int) );
	 		
			//guardar el nombre 
			outputFile.write(persona->nombre.data(),sizeNombre);
			
			//guardar vida
	 		outputFile.write(reinterpret_cast<char*>(&soldados[i]->vida), (int)sizeof(int) );
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


