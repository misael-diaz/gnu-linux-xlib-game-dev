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
	struct game g = {
		.ents = {},
		.supported_protocols = {
			GAME_PROTOCOL_NM,
			GAME_DELETE_WINDOW_NM,
		},
		.protocols = {},
		.display = NULL,
		.window = 0,
		.screen = NULL,
		.visual = NULL,
		.colormap = 0,
		.red = {},
		.green = {},
		.blue = {},
		.gray = {},
		.gc = 0,
		.screen_width = 0,
		.screen_height = 0,
		.screen_depth = 0,
		.protocolno = GAME_SUPPORTED_PROTOCOLS_NUM,
		.screeno = 0,
		.entno = EN_NUM_ENTITY_MAX
	};
	sys_init_random();
	vid_init_gw(&g);
	vid_info_gw(&g);
	en_init(&g);
	g_loop(&g);
	g_pause(&g);
	vid_close_gw(&g);
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
