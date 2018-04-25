#pragma once
#include <allegro5\allegro_image.h>
#include <vector>
#include <iostream>
#include <allegro5\allegro5.h>
#include <string>
#include <allegro5\allegro_audio.h>
using namespace std;
bool blocking_anim(char letra);
void mostrar_secuencia(char& letra);

class animation
{
public:
	void draw_cat();
	void draw_sonic();
	void draw_mario();
	void draw_exp();
	void draw_exp2();
	void draw_homero();
	void play_anim(char anim_letra);
};

