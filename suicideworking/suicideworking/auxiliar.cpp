#include <fstream>
#include <iostream>
using namespace std;

#include "auxiliar.h"



string compose_msg(package_data &data) {
	char arr[2] = { data.animation,0 };
	string ans = arr;

	ans += data.actual +1;

	for (int i = 0; i < data.cnt_maq; i++) {
		ans+=(data.seq[i]+1);//HOT FIX, me tengo que fijar como lo recibo 
	}

	return ans;
}
void decompose_msg(string msg, package_data &data) {

	data.animation = msg[0];
	data.actual = msg[1] -1; //Such a hot fix
	int j = 2;
	for (int i = 0; i < data.cnt_maq; i++) {
		data.seq[i] = msg[j++]-1;
	}

}

int leer_direcciones(vector <string> &direcciones) {
	ifstream myfile;
	myfile.open(DIRECCIONES_FILE);

	if (!myfile.is_open()) {
		return 0;
	}
	string line;
	while (getline(myfile, line))
		direcciones.push_back(line);

	myfile.close();


	return 1;
}

void preguntar_secuencia(char *letra, int seq[MAX_MAQUINAS], vector <string> &direcciones) {

	bool invalid_letter;

	do {
		cout << "Indique animacion: ";
		cin >> *letra;
		*letra = toupper(*letra);
		invalid_letter = (*letra) < 'A' || (*letra) > 'F';
		if (invalid_letter) {
			cout << "Letra invalida insertada \n";
		}
	} while (invalid_letter);
	int used[MAX_MAQUINAS];
	fill(used, used + direcciones.size(), 0);

	for (int i = 0; i < direcciones.size(); i++) {
		int val;
		bool invalid;
		do {
			cout << "Indique Pc " << i << " de la secuencia:";
			cin >> val;
			
			invalid = val < 0 || val >= direcciones.size() || used[val];
			if (invalid) cout << "Indico una opcion invalida\n";
		} while (invalid);
		seq[i] = val;
		used[val] = 1;
	}
	cout << "Orden de maquinas : ";
	for (int i = 0; i < direcciones.size(); i++) {
		cout << seq[i] << ',';
	}
	cout << "." << endl;;
}


void complete_string(string &str_ans, char* ans, int sz) {
	for (int i = 0; i < sz; i++) {
		str_ans.push_back(ans[i]);
	}
}