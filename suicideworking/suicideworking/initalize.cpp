#include "initialize.h"

#include <iostream>
using namespace std;
int allegro_init(void) {
	if (al_init()) {
		if (al_install_keyboard()){
			if (al_init_image_addon()) {
				if (al_install_audio()) {
					if (al_init_acodec_addon()) {
						if (al_reserve_samples(1)) {return 0;}
					}
				}
			}
		}
	}
	return -1;
}



int parseCallback(char *key, char *value, void *userData) {
	if (key!=NULL?(!strcmp(key, "ip")):false) {((data_t*)userData)->ip = string(value);}
	else if (!strcmp(value, "iniciar") ) {((data_t*)userData)->iniciar = 1;}
	else {((data_t*) userData)->bad = 1;}
	return 1;
}
