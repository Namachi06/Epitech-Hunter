/*
** EPITECH PROJECT, 2017
** destroy
** File description:
** 	Destroy All
*/

#include "include/properties.h"

void destroy_all(t_game_properties *duck, t_game_properties *back,
	sfRenderWindow *my_window)
{
	sfClock_destroy(duck->clock);
	sfSprite_destroy(back->sprite);
	sfSprite_destroy(duck->sprite);
	sfRenderWindow_destroy(my_window);
}
