#include "Tablero.h"

using namespace  std;

Tablero::Tablero(int filas, int columnas, string nombre){

	this->nombre = nombre;
	ancho = columnas;
	alto = filas;
	celulasVivas = 0;
	celulasVivasTurnoAnterior = 0;
	parcelas = new Parcela*[alto];

	for(int i = 0; i < alto; i++){
		parcelas[i] = new Parcela[ancho];
	}
}


Tablero::~Tablero(){

	for(int i = 0; i < alto; i++){
		delete[] parcelas[i];
	}
	delete[] parcelas;
}

int Tablero::getCantidadDeCelulasVivas(){

	celulasVivas = 0;
	Parcela parcela;
	Celula celula;

	for(int i=0; i<alto; i++){
		for(int j=0; j<ancho; j++){

			parcela = parcelas[i][j];
			celula = parcela.getCelula();

			if(celula.saberSiEstaViva()){
				celulasVivas++;
			}
		}
	}
	return celulasVivas;
}

