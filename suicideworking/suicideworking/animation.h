#pragma once
#include <allegro5\allegro_image.h>
#include <vector>
#include <iostream>
#include <allegro5\allegro5.h>
#include <string>
#include <allegro5\allegro_audio.h>
using namespace std;
bool blocking_anim(char letra, double width, double height);
void mostrar_secuencia(char& letra);
class animation
{
private:
	char anim_id;

public:
	animation(char name);
	void draw_cat(float height, float width);
	void draw_sonic(float width);
	void draw_mario(float width);
	void draw_exp(float height, float width);
	void draw_exp2(float height, float width);
	void draw_homero(float height, float width);
	

	vector<ALLEGRO_BITMAP*> background;
	char& get_anim_id(void);

	void play_anim(char anim_type, float MAX_SCREEN_WIDTH, float MAX_SCREEN_HEIGHT);
	~animation();
};

