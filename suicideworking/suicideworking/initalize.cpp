#include "initialize.h"

#include <iostream>
using namespace std;
int allegro_init(void) {
	if (!al_init()) {
		return -1;
	}
	if (!al_install_keyboard())
	{
		return -1;
	}

	if (!al_init_image_addon()) {
		return -1;
	}

	if (!al_install_audio()) {
		return -1;
	}

	if (!al_init_acodec_addon()) {
		return -1;
	}

	if (!al_reserve_samples(1)) {
		return -1;
	}
	return 0;
}



int parseCallback(char *key, char *value, void *userData) {
	data_t *ud = (data_t*)userData;

	if (key!=NULL?(!strcmp(key, "ip")):false) {
		ud->ip = string(value);
		cout << "setting ip to " << value << '\n';
	}
	else if (!strcmp(value, "iniciar") ) {
		ud->iniciar = 1;
		cout << "setting iniciar to 1 \n";
	}
	else {
		cout << "invalid parameter inserted \n";
		ud->bad = 1;
	}

	return 1;
}
