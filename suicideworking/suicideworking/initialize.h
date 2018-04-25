#pragma once
#include <allegro5\allegro_acodec.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <string>
const int MAX_MAQUINAS = 255;
const std::string DIRECCIONES_FILE = "direcciones.txt";

int allegro_init();//inicia allegro
int parseCallback(char *key, char *value, void *userData);//callback

class data_t {
public:
	std::string ip;
	int iniciar;
	int bad;
	data_t() : ip("0.0.0.0"), iniciar(0), bad(0) {}
};