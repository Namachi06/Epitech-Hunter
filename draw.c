/*
** EPITECH PROJECT, 2017
** draw
** File description:
** 	Draw All
*/

#include "include/include.h"
#include "include/properties.h"
#include <unistd.h>

void draw_all(sfRenderWindow *my_window, t_game_properties *back,
	t_game_properties *duck)
{
	sfRenderWindow_drawSprite(my_window, back->sprite, NULL);
	sfRenderWindow_drawSprite(my_window, duck->sprite, NULL);
	sfRenderWindow_display(my_window);
}
