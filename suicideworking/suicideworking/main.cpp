#define _WIN32_WINNT 0x0501

#include <iostream>
#include <cstring>
#include <vector>
#include <time.h>
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

	//iniciliazacion de allegro
	if (allegro_init() == -1) {
		return -1;
	}
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
	if (data.iniciar) {
		cout << "comenzando como maquina que inicia \n";
		while (1) {
			if (!iniciar(direcciones, data.ip)) {
				break;
			}
		}
	}
	else {
		cout << "iniciando como maquina que escucha \n";
		while (1) {
			if (!escuchar(direcciones)) {
				break;
			}
		}
	}
	cout << "ending program \n";
	return 0;
}



