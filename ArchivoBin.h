#ifndef ARCHIVOBIN_H
#define ARCHIVOBIN_H
#include "Soldado.h"

#include <fstream>
using std::ofstream;
using std::ifstream;

#include <string>
using std::string;

#include <vector>
using std::vector;

class ArchivoBin{
	public:
		ArchivoBin(string);
		

		virtual bool abrirEscritura(int);
		virtual bool abrirLectura();
		virtual vector<Soldado*> leerSoldado();
		bool guardarSoldado(Soldado*){
		bool cerrarLectura();
		bool cerrarEscritura();
		
		~ArchivoBin();
	protected:
		string fileName;
		ofstream outputFile;
		int modoEscritura;
		ifstream inputFile;
};

#endif
