#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "system.h"
#include "input.h"
#include "video.h"
#include "entity.h"
#include "game.h"

int main ()
{
	Display *display = NULL;
	Window window = {};
	struct entity ents[EN_NUM_ENTITY_MAX] = {};
	int num_entities = EN_NUM_ENTITY_MAX;
	sys_init_random();
	vid_init_gw(&display, &window);
	vid_info_gw(&display);
	en_init(
			ents,
			num_entities,
			WidthOfScreen(DefaultScreenOfDisplay(display)),
			HeightOfScreen(DefaultScreenOfDisplay(display))
	);
	vid_close_gw(&display, &window);
	return 0;
}

/*

gnu-linux-xlib-game-dev                                          May 23, 2025

author: @misael-diaz
source: src/main.c

Attempts to implement a basic game with Xlib for GNU/Linux.

Copyright (C) 2025 Misael Diaz-Maldonado

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, version 2 only of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

*/
