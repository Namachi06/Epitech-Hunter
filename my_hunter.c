/*
** EPITECH PROJECT, 2017
** main
** File description:
** 	Run the program
*/

#include "include/properties.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main()
{
	sfRenderWindow *my_window;
	sfEvent event;
	int res;
	t_game_properties *duck;
	t_game_properties *background;
	int spriteOffset = 0;
	srand(time(NULL));
	sfTime timer;
	int initialized = 0;

	my_window = create_window();
	res = init_duck_sprite(&duck);
	if (res != 0) {
		return (84);
	}
	res = init_background_sprite(&background);
	if (res != 0) {
		return (84);
	}
	while (sfRenderWindow_isOpen(my_window)) {
		while (sfRenderWindow_pollEvent(my_window, &event))
		{
			analyse_events(my_window, event, duck);
		}
		timer = sfClock_getElapsedTime(duck->clock);
		duck->seconds = timer.microseconds / 1000000.0;
		if ((initialized == 0) || (duck->seconds >
			(1/duck->sprite_per_second))) {
			initialized = 1;
			update_duck_sprite(duck, spriteOffset++);
			draw_all(my_window, background, duck);
			sfClock_restart(duck->clock);
		} else {
			update_duck_sprite_pos(duck);
			draw_all(my_window, background, duck);
		}
	}
	destroy_all(duck, background, my_window);
	return (0);
}
