/*
** EPITECH PROJECT, 2017
** properties
** File description:
** 	Game properties
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

typedef struct s_game_properties {
	sfSprite *sprite;
	sfTexture *texture;
	sfVector2f spritePos;
	sfVector2f spriteScale;
	sfIntRect spriteRect;
	sfClock *clock;
	float seconds;
	float sprite_per_second;
	float speed;
} t_game_properties;

sfIntRect create_rect(int width, int height, int left, int top);
sfVector2f create_pos(int x, int y);
sfRenderWindow *create_window();
void manage_mouse_click(sfMouseButtonEvent event, t_game_properties *duck);
void analyse_events(sfRenderWindow *my_window, sfEvent event,
	t_game_properties *duck);
int init_duck_sprite(t_game_properties **duck);
void update_duck_sprite_pos(t_game_properties *duck);
void update_duck_sprite(t_game_properties *duck, int spriteOffset);
int init_background_sprite(t_game_properties **background);
void draw_all(sfRenderWindow *my_window, t_game_properties *back,
	t_game_properties *duck);
void destroy_all(t_game_properties *duck, t_game_properties *back,
	sfRenderWindow *my_window);
