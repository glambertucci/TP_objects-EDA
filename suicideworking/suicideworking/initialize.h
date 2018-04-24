#pragma once
#include <allegro5\allegro_acodec.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
int allegro_init();

int parseCallback(char *key, char *value, void *userData);

#include <string>

const int MAX_MAQUINAS = 256;
const std::string DIRECCIONES_FILE = "direcciones.txt";
class data_t {
public:
	std::string ip;
	int iniciar;
	int bad;
	data_t() : ip("0.0.0.0"), iniciar(0), bad(0) {}
};