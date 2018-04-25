#include <fstream>
#include <iostream>
#include <curses.h>
using namespace std;

#include "auxiliar.h"



string compose_msg(package_data &data) {
	char arr[2] = { data.animation,0 };
	string ans = arr;
	ans += data.actual +1;
	for (int i = 0; i < data.cnt_maq; i++) {
		ans+=(data.seq[i]+1);//La razon por la que lo hice asi es que me confundi, asumi maquinas empiezan en 0 y era en uno, esto es un cheap fix 
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
	if (!myfile.is_open()) {return 0;}
	string line;
	while (getline(myfile, line))
		direcciones.push_back(line);
	myfile.close();
	return 1;
}

bool preguntar_continuar() {
		
	WINDOW * winTest = NULL;
	winTest = initscr();
	nodelay(winTest, TRUE);
	noecho();
	immedok(winTest, TRUE);
	bool invalid_letter;
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	color_set(1, NULL);
	mvprintw(0,0,"Would you like to continue?\nPress 'Y' to continue, 'N' to close");
	int answer;	bool done = false;
	do {

		answer = getch();
		if (answer != ERR){
			if (toupper(answer) == 'Y' || toupper(answer) == 'N'){
				mvdeleteln(10, 15);
				done = true;
			}
			else if ((toupper(answer) >= 'A' && toupper(answer) < 'N') || (toupper(answer) > 'N' && toupper(answer) <= 'Z')){
				color_set(2, NULL);
				mvprintw(10, 15, "Letra invalida");
			}
		}
	} while (done);
	endwin();
	if (answer == 'N')  return 0;
	else return 1;
}

void preguntar_secuencia(char *letra, int seq[MAX_MAQUINAS], vector <string> &direcciones) {
	WINDOW * winTest = NULL;
	winTest = initscr();
	nodelay(winTest, TRUE);
	noecho();
	immedok(winTest, TRUE);
	bool invalid_letter;
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	color_set(1, NULL);
	mvprintw(0,0,"Indique animacion");
	int answer;
	bool done = false;
	do {

		answer = getch();
		if (answer != ERR)
		{
			if (toupper(answer) >= 'A' && toupper(answer) <= 'F')
			{
				mvprintw(0, 0, "Animacion elegida %c!", answer);
				mvdeleteln(10, 15);
				done = true;
				*letra = toupper(answer);
			}
			else if ( (toupper(answer) > 'F' && toupper(answer) <= 'Z'))
			{
				color_set(2, NULL);
				mvprintw(10, 15, "Letra invalida");
			}
		}
	} while (!done);

	int used[MAX_MAQUINAS];
	fill(used, used + direcciones.size(), 0);
	bool done2 = false;

	mvprintw(2, 0, "Seleccion de secuencia ");
	for (int i = 0; i < direcciones.size(); i++) {
		int val;
		bool invalid;
		mvprintw(3, 0, "Elija el orden de la pc %d ", i);
		do { 
			val = getch();
			if (val != ERR){
				invalid = ((val-'0') < 0 || ((val-'0') >= direcciones.size()));
				if (invalid) {
					color_set(2, NULL);
					mvprintw(10,15,"Indicó una opcion invalida");
					color_set(1, NULL);
				}
				else {
				mvdeleteln(10, 15);
				mvprintw(0,5,"Opcion elegida: %c",val);
				}
			}
		} while (invalid);
		invalid = true;
		seq[i] = val-'0';
		used[val] = 1;
	}
	mvdeleteln(2,0);
	endwin();
}