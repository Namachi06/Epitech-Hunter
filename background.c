/*
** EPITECH PROJECT, 2017
** background
** File description:
** 	Manage background
*/

#include "include/properties.h"
#include <stdlib.h>

int init_background_sprite(t_game_properties **background)
{
	*background = (t_game_properties *)malloc(sizeof(t_game_properties));
	(*background)->texture = sfTexture_createFromFile("images/background.png", NULL);
	if (!(*background)->texture) {
		return (-1);
	}
	(*background)->sprite = sfSprite_create();
	sfSprite_setTexture((*background)->sprite, (*background)->texture, sfFalse);
	return (0);
}
