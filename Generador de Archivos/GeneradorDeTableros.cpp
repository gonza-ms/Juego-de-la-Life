#include "GeneradorDeTableros.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#define SI 'S'
#define NO 'N'
using namespace std;

GeneradorDeTableros::GeneradorDeTableros(string ruta){
	this->ruta = ruta;
	salida.open(ruta.c_str());
}

void GeneradorDeTableros::pedirTableros(){

	string nombreTablero;
	int filas, columnas;

	while(preguntarAlUsuario("¿Desea ingresar un tablero? (S/N)")){
		cout << "Ingrese nombre del tablero: " << endl;
		cin >> nombreTablero;

		cout << "Ingrese número de filas: " << endl;
		cin >> filas;

		cout << "Ingrese número de columnas: " << endl;
		cin >> columnas;

		salida << "Tablero " << nombreTablero << " " << columnas << " " << filas << endl;
	}
}

void GeneradorDeTableros::generarParcelas(){
	std::ifstream leer;
	leer.open(ruta.c_str());
	string palabraAuxiliar, nombre;
	int fila, columna;

	salida << setprecision(2) <<fixed;

	while( leer >> palabraAuxiliar ){
			if( !palabraAuxiliar.compare("Tablero") ){
				leer >> nombre >> fila >> columna;
				salida << "Parcela " << nombre << " " << columna << " " << fila << " " << rand()%256 << " " << rand()%256 << " " << rand()%256 << " " << (float)rand()/RAND_MAX << " " << (float)rand()/RAND_MAX<< endl;
			}
	}
}

void GeneradorDeTableros::pedirPortales(){

	string nombreTableroDestino, nombreTableroOrigen;
	int xOrigen, xDestino, yOrigen, yDestino;
	char estado;

	while(preguntarAlUsuario("¿Desea ingresar un portal? (S/N)")){
		cout << "Ingrese nombre del tablero de origen: " << endl;
		cin >> nombreTableroOrigen;

		cout << "Ingrese coordenada en x origen: " << endl;
		cin >> xOrigen;

		cout << "Ingrese coordenada en y origen: " << endl;
		cin >> yOrigen;

		cout << "Ingrese estado (A - Activo, N - Normal - P - Pasivo): " << endl;
		cin >> estado;

		cout << "Ingrese nombre del tablero destino: " << endl;
		cin >> nombreTableroDestino;

		cout << "Ingrese coordenada en x destino: " << endl;
		cin >> xDestino;

		cout << "Ingrese coordenada en y destino: " << endl;
		cin >> yDestino;

		salida << "Portal " << nombreTableroOrigen << " " << xOrigen << " " << yOrigen << " " << estado << " " << nombreTableroDestino << " " << xDestino << " " << yDestino << endl;
	}
}

bool GeneradorDeTableros::preguntarAlUsuario(string mensaje){

	char respuesta;
	cout << mensaje;
	cin >> respuesta;

	respuesta = toupper(respuesta);
	if(respuesta!=SI && respuesta!=NO){
		cout << "Ingreso inválido. ";
		preguntarAlUsuario(mensaje);
	}

	return (respuesta == SI);
}
