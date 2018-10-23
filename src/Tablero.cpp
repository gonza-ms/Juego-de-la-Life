#include "Tablero.h"

Tablero::Tablero(){
	nombre = "boca la concha de tu madre";
	ancho = 20;
	alto = 20;
	celulasVivas = 0;
	celulasVivasTurnoAnterior = 0;
	parcelas = new Parcela[ancho][alto];
}

Tablero::~Tablero(){
	delete []parcelas;
}

int Tablero::getCantidadDeCelulasVivas(){

	celulasVivas = 0;
	Parcela parcela;
	Celula celula;

	for(int i=0; i<alto; i++){
		for(int j=0; j<ancho; j++){

			parcela = parcelas[i][j];
			celula = parcela.getCelula();

			if(celula.estaViva()){
				celulasVivas++;
			}
		}
	}
	return celulasVivas;
}

