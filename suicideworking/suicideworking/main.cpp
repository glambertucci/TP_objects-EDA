#define _WIN32_WINNT 0x0501
//grupo 3
#include <iostream>
#include <vector>
#include "server.h"
#include "client.h"
#include "parser.h"
#include "auxiliar.h"
#include "animation.h"
#include "network.h"
#include <allegro5\allegro_acodec.h>
#include <allegro5\allegro_audio.h>
#include "initialize.h"
#include "boost/asio.hpp"
#include "boost/function.hpp"
#include "boost/bind.hpp"
#include <fstream>


using namespace std;

int main(char argc, char *argv[]) {
	bool exit = false, close = false;
	if (allegro_init() == -1) {return -1;}	//iniciliazacion de allegro
	vector <string> direcciones;
	if (!leer_direcciones(direcciones)) {
		cout << "no se puede abrir el archivo de direcciones \n";
		return -1;
	}
	data_t data;
	parseCmdLine(argc, argv, parseCallback, (void*)&data);
	if (data.bad) {
		cout << "saliendo ... \n";
		return -1;
	}
	else if (data.ip == "0.0.0.0") {
		cout << "No se especifico IP ... \n";
		return -1;
	}
	do{
		if (data.iniciar) {
			iniciar(direcciones, data.ip);
			data.iniciar = false;
		}
		else if (!close){
			close = escuchar(direcciones);
			cout << "iniciando como maquina que escucha \n";
		}
		else{
			if( preguntar_continuar()){{ data.iniciar = 1; close = false; }}
			else exit = true;
		}
	} while (!exit);
	return 0;
}


