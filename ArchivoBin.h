#ifndef ARCHIVOBIN_H
#define ARCHIVOBIN_H

#include "Soldado.h"
#include "SAsalto.h"
#include "SSoporte.h"
#include <iostream>

#include <fstream>
using std::ofstream;
using std::ifstream;

#include <string>
using std::string;

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class ArchivoBin{
	public:
		ArchivoBin(string);
		

		virtual bool abrirEscritura(int);
		virtual bool abrirLectura();
		vector<Soldado*> leerSoldado(int);
		bool guardarSoldado(vector<Soldado*>, bool, int);
		bool cerrarLectura();
		bool cerrarEscritura();
		
		
	protected:
		string fileName;
		ofstream outputFile;
		int modoEscritura;
		ifstream inputFile;
};

#endif
