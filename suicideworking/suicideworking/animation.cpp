#include "animation.h"

const float width = 1920.0;
const float height = 700.0;


void mostrar_secuencia(char& letra) {
	cout << "mostrando la secuencia " << letra << '\n';
	if (blocking_anim(letra)) {
		cout << "la animacion " << letra << " se pudo realizar satisfactoriamente!" << endl;
	}
	else {
		cout << "hubo un error al tratar de reproducir animacion " << letra << " " << endl;
	}
}

bool blocking_anim(char letra) {
	ALLEGRO_DISPLAY * display = nullptr;
	ALLEGRO_SAMPLE * music = nullptr;

	display = al_create_display(width, height);

	switch (letra)
	{
	case 'A':
		music = al_load_sample("Music/shooting_stars.wav");
		break;
	case 'B':
		music = al_load_sample("Music/explosion_music.wav");
		break;
	case 'C':
		music = al_load_sample("Music/explosion2_music.wav");
		break;
	case 'D':
		music = al_load_sample("Music/homero_music.wav");
		break;
	case 'E':
		music = al_load_sample("Music/mario_music.wav");
		break;
	case 'F':
		music = al_load_sample("Music/sonic_music.wav");
		break;

	};
	al_play_sample(music, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
	animation a1;
	a1.play_anim(letra);
	al_destroy_display(display);
	al_destroy_sample(music);
	return 1;

}


void animation::play_anim(char anim_letra)
{
	switch (anim_letra) {
	case 'A':
		draw_cat();
		break;
	case 'B':
		draw_exp();
		break;
	case 'C':
		draw_exp2();
		break;
	case 'D':
		draw_homero();
		break;
	case 'E':
		draw_mario();
		break;
	case 'F':
		draw_sonic();
		break;
	};
}

void animation::draw_cat()
{
	string files[12];
	for (int i = 0; i < 12; i++)
		files[i] = "Pictures/Cat Running/Cat Running-F" + to_string(i + 1) + ".png";
	ALLEGRO_BITMAP * bitmaps[12];
	for (int i = 0; i < 12; i++)
		bitmaps[i] = al_load_bitmap(files[i].c_str());
	ALLEGRO_BITMAP * background;
	background = al_load_bitmap("Pictures/Background/backgroundCat.png");//ACORDATE DE PONER UNA IMAGEN
	int x = -al_get_bitmap_width(bitmaps[0]);
	while (x  < (width - 50))
	{
		for (int i = 0; i < 12; i++)
		{
			al_draw_bitmap(background, 0, 0, 0);
			al_draw_bitmap(bitmaps[i], x, height / 3.0, 0);
			al_flip_display();
			x += 2;
			al_rest(0.1);

		}
	}
}
void animation::draw_exp()
{
	string files[8];
	for (int i = 0; i < 8; i++)
		files[i] = "Pictures/Explosion 1/Explosion 1-F" + to_string(i + 1) + ".png";
	ALLEGRO_BITMAP * bitmaps[8];
	for (int i = 0; i < 8; i++)
		bitmaps[i] = al_load_bitmap(files[i].c_str());
	for (int i = 0; i < 8; i++)
	{

		al_draw_scaled_bitmap(bitmaps[i], 0, 0, al_get_bitmap_width(bitmaps[i]), al_get_bitmap_height(bitmaps[i]), 0, 0, width, height, 0);
		al_flip_display();
		al_rest(0.12);

	}
}
void animation::draw_exp2()
{
	string files[48];
	for (int i = 0; i < 48; i++)
		files[i] = "Pictures/Explosion 2/Explosion 2-F" + to_string(i + 1) + ".png";
	ALLEGRO_BITMAP * bitmaps[48];
	for (int i = 0; i < 48; i++)
		bitmaps[i] = al_load_bitmap(files[i].c_str());
	for (int i = 0; i < 48; i++){
		al_draw_scaled_bitmap(bitmaps[i], 0, 0, al_get_bitmap_width(bitmaps[i]), al_get_bitmap_height(bitmaps[i]), 0, 0, width, height, 0);
		al_flip_display();
		al_rest(0.1);
	}
}
void animation::draw_homero()
{
	string files[10];
	for (int i = 0; i < 10; i++)
		files[i] = "Pictures/Homer Dance/homerdance-F" + to_string(i + 1) + ".png";
	ALLEGRO_BITMAP * bitmaps[10];
	for (int i = 0; i < 10; i++)
		bitmaps[i] = al_load_bitmap(files[i].c_str());
	ALLEGRO_BITMAP * background;
	background = al_load_bitmap("Pictures/Background/backgroundHomero.png");//ACORDATE DE PONER UNA IMAGEN
	int x = -al_get_bitmap_width(bitmaps[0]);
	while (x  < (width - 50)){
		for (int i = 0; i < 10; i++){
			al_draw_bitmap(background, 0, 0, 0);
			al_draw_bitmap(bitmaps[i], x, height / 2, 0);
			al_flip_display();
			x += 100;
			al_rest(0.1);

		}
	}
}
void animation::draw_mario()
{
	string files[12];
	for (int i = 0; i < 12; i++)
		files[i] = "Pictures/Super Mario/Super Mario Running-F" + to_string(i + 1) + ".png";
	ALLEGRO_BITMAP * bitmaps[12];
	for (int i = 0; i < 12; i++)
		bitmaps[i] = al_load_bitmap(files[i].c_str());
	ALLEGRO_BITMAP * background;
	background = al_load_bitmap("Pictures/Background/backgroundMario.png");//ACORDATE DE PONER UNA IMAGEN
	int x = -al_get_bitmap_width(bitmaps[0]);
	while (x  < (width - 50)){
		for (int i = 0; i < 12; i++){
			al_draw_bitmap(background, 0, 0, 0);
			al_draw_bitmap(bitmaps[i], x, 0, 0);
			al_flip_display();
			x += 2;
			al_rest(0.04);
		}
	}
}
void animation::draw_sonic()
{
	string files[10];
	for (int i = 0; i < 10; i++)
		files[i] = "Pictures/Sonic/Sonic Running-F" + to_string(i + 1) + ".png";
	ALLEGRO_BITMAP * bitmaps[10];
	for (int i = 0; i < 10; i++)
		bitmaps[i] = al_load_bitmap(files[i].c_str());
	ALLEGRO_BITMAP * background;
	background = al_load_bitmap("Pictures/Background/backgroundSonic.png");//ACORDATE DE PONER UNA IMAGEN
	int x = -al_get_bitmap_width(bitmaps[0]);
	while (x  < (width - 200)){
		for (int i = 0; i < 4; i++){
			al_draw_bitmap(background, 0, 0, 0);
			al_draw_bitmap(bitmaps[i], x, 0, ALLEGRO_FLIP_HORIZONTAL);
			al_flip_display();
			al_rest(0.06);
		}
		x += 70;
		for (int i = 4; i < 10; i++){
			al_draw_bitmap(background, 0, 0, 0);
			al_draw_bitmap(bitmaps[i], x, 0, ALLEGRO_FLIP_HORIZONTAL);
			al_flip_display();
			al_rest(0.06);
		}
		x += 70;
	}
}