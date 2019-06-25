/*
** EPITECH PROJECT, 2017
** utils
** File description:
** 	Utils
*/

#include "include/include.h"
#include "include/properties.h"
#include <stdlib.h>

sfIntRect create_rect(int width, int height, int left, int top)
{
	sfIntRect rect;

	rect.height = height;
	rect.width = width;
	rect.left = left;
	rect.top = top;
	return (rect);
}

sfVector2f create_pos(int x, int y)
{
	sfVector2f pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}

sfRenderWindow *create_window()
{
	sfVideoMode video_mode = {1280, 768, 32};
	return sfRenderWindow_create(video_mode, "My Runner", sfResize |
		sfClose, NULL);
}

void manage_mouse_click(sfMouseButtonEvent event, t_game_properties *duck)
{
	int duck_is_hit = 0;

	if ((duck->spriteScale.x == 1) &&
		(event.x > (int)duck->spritePos.x && event.x < (int)duck->spritePos.x + 110) &&
		(event.y > (int)duck->spritePos.y && event.y < (int)duck->spritePos.y + 110)) {
		duck_is_hit = 1;
	} else if ((duck->spriteScale.x == -1) &&
		(event.x < (int)duck->spritePos.x && event.x > (int)duck->spritePos.x - 110) &&
		(event.y > (int)duck->spritePos.y && event.y < (int)duck->spritePos.y + 110)) {
		duck_is_hit = 1;
	}
	if (duck_is_hit == 1) {
		duck->spritePos.x = -110;
		duck->spritePos.y = rand() % 400;
		sfSprite_setPosition(duck->sprite, duck->spritePos);
		duck->speed += 10;
	}
}

void analyse_events(sfRenderWindow *my_window, sfEvent event,
	t_game_properties *duck)
{
	sfMouseButtonEvent *mouseButtonEvent;

	switch (event.type) {
		case sfEvtMouseButtonPressed:
			mouseButtonEvent = &event;
			manage_mouse_click(*mouseButtonEvent, duck);
			break;
		case sfEvtClosed:
			sfRenderWindow_close(my_window);
			break;
		default:
			break;
	}
}
