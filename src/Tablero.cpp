#include "Tablero.h"

Tablero::Tablero(){

	primerElemento = 0;
	tamanio = 0;
}

Tablero::~Tablero(){

	while(!this->tableroVacio()){
		this->eliminarTablero(1);
	}
}

bool Tablero::tableroVacio(){

	return (primerElemento == 0);
}

void Tablero::insertar(int filas ,int columnas, std::string nombre){

	Malla* malla = new Malla(filas, columnas, nombre);
	Malla* mallaAux = primerElemento;

	if(this -> tableroVacio()){
		primerElemento = malla;
	} else {
		while(mallaAux->getSiguienteMalla()){
			mallaAux = mallaAux->getSiguienteMalla();
		}
		mallaAux->setSiguienteMalla(malla);
	}
	tamanio++;
}

int Tablero::getCantidadDeFilas(unsigned posicion){

	Malla* mallaAux = primerElemento;
	unsigned i = 1;

	while((i < posicion) && (mallaAux->getSiguienteMalla())){
		mallaAux = mallaAux->getSiguienteMalla();
		i++;
	}
	return mallaAux->getCantidadDeFilas();
}

int Tablero::getCantidadDeColumnas(unsigned posicion){

	Malla* mallaAux = primerElemento;
	unsigned i = 1;

	while((i < posicion) && (mallaAux->getSiguienteMalla())){
		mallaAux = mallaAux->getSiguienteMalla();
		i++;
	}
	return mallaAux->getCantidadDeColumnas();
}

int Tablero::getNombre(unsigned posicion){

	Malla* mallaAux = primerElemento;
	unsigned i = 1;

	while((i < posicion) && (mallaAux->getSiguienteMalla())){
		mallaAux = mallaAux->getSiguienteMalla();
		i++;
	}
	return mallaAux->getNombre();
}

void Tablero::eliminarTablero(unsigned posicion){

	Malla* mallaAux = primerElemento;
	if((posicion == 1) && (!primerElemento->getSiguienteMalla())){
		primerElemento = mallaAux->getSiguienteMalla();
	} else {
		unsigned i = 1;
		Malla* mallaAnterior;

		while((i < posicion) && (mallaAux->getSiguienteMalla())){
			mallaAnterior = mallaAux;
			mallaAux = mallaAux->getSiguienteMalla();
			i++;
		}
		mallaAnterior->setSiguienteMalla(mallaAux->getSiguienteMalla());
	}
	delete mallaAux;
	tamanio--;
}

unsigned Tablero::getTamanio(){

	return tamanio;
}



