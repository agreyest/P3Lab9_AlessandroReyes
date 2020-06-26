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


vector<Persona*> ArchivoBin::leerSoldado(){
	 vector<Persona*> retValue;
	 
	 
	 while(!inputFile.eof()){
	 	int nameSize=0;
	 	int edad=0; 
	 	
	 	//leer el tamaño del nombre 
	 	inputFile.read(reinterpret_cast<char*>(&nameSize),sizeof(int));
	 	
	 	char buffer[100];
	 	//leer el nombre
	 	inputFile.read(buffer,nameSize);
	 	
	 	string nombre = buffer;
	 	
	 	//leer la edad
	 	inputFile.read(reinterpret_cast<char*>(&edad),sizeof(int));
	 	
	 	retValue.push_back(new Persona(nombre,edad));
	 	
	 }
	 
	 return retValue; 
}

bool ArchivoBin::guardarSoldado(Soldado* soldados){
 	if(outputFile.is_open()){
 		
 		int sizeNombre = persona->nombre.size();
 		//guardar size nombre
 		outputFile.write(reinterpret_cast<char*>(&sizeNombre), (int)sizeof(int) );
 		
		//guardar el nombre 
		outputFile.write(persona->nombre.data(),sizeNombre);
		
		//guardar edad
 		outputFile.write(reinterpret_cast<char*>(&persona->edad), (int)sizeof(int) );
				
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


ArchivoBin::~ArchivoBin(){
	
}
