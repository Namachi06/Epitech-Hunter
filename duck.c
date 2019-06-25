/*
** EPITECH PROJECT, 2017
** duck
** File description:
** 	Manage duck
*/

#include <stdlib.h>
#include <unistd.h>
#include "include/properties.h"

void update_duck_sprite(t_game_properties *duck, int spriteOffset)
{
	spriteOffset %= 4;
	if (spriteOffset == 3) {
		spriteOffset = 1;
	}
	duck->spriteRect.left = spriteOffset * 110;
	sfSprite_setPosition(duck->sprite, duck->spritePos);
	sfSprite_setScale(duck->sprite, duck->spriteScale);
	sfSprite_setTextureRect(duck->sprite, duck->spriteRect);
}

void update_duck_sprite_pos(t_game_properties *duck)
{
	duck->spritePos.x = duck->spritePos.x + (1 * duck->spriteScale.x);
	if (duck->spritePos.x >= 1390) {
		duck->spriteScale.x = -1;
		duck->spritePos.y = rand() % 400;
	} else if (duck->spritePos.x <= -110) {
		duck->spriteScale.x = 1;
		duck->spritePos.y = rand() % 400;
	}
	sfSprite_setPosition(duck->sprite, duck->spritePos);
	sfSprite_setScale(duck->sprite, duck->spriteScale);
}

int init_duck_sprite(t_game_properties **duck)
{
	*duck = (t_game_properties *)malloc(sizeof(t_game_properties));
	(*duck)->texture =
		sfTexture_createFromFile("images/spritesheet.png", NULL);
	if (!(*duck)->texture) {
		return (-1);
	}
	(*duck)->sprite = sfSprite_create();
	sfSprite_setTexture((*duck)->sprite, (*duck)->texture, sfTrue);
	(*duck)->spriteRect = create_rect(110, 110, 0, 0);
	sfSprite_setTextureRect((*duck)->sprite, (*duck)->spriteRect);
	(*duck)->spritePos = create_pos(-110, rand() % 400);
	sfSprite_setPosition((*duck)->sprite, (*duck)->spritePos);
	(*duck)->spriteScale = create_pos(1, 1);
	sfSprite_setScale((*duck)->sprite, (*duck)->spriteScale);
	(*duck)->clock = sfClock_create();
	(*duck)->speed = 10;
	(*duck)->sprite_per_second = 10;
	return (0);
}
