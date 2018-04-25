#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "initialize.h"
using namespace std;

bool preguntar_continuar();

struct package_data {
	int seq[MAX_MAQUINAS];
	int cnt_maq;
	int actual;
	char animation;
};

string compose_msg(package_data &data);
void decompose_msg(string msg, package_data &data);

void preguntar_secuencia(char *letra, int seq[MAX_MAQUINAS], vector <string> &direcciones);
int leer_direcciones(vector <string> &direcciones);