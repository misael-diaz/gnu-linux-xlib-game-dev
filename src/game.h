#ifndef GNU_LINUX_XLIB_GAME_DEV_GAME_H
#define GNU_LINUX_XLIB_GAME_DEV_GAME_H

#include <X11/Xlib.h>
#include "entdefs.h"

struct game {
	struct entity ents[EN_NUM_ENTITY_MAX];
	char *supported_protocols[GAME_SUPPORTED_PROTOCOLS_NUM];
	Atom protocols[GAME_SUPPORTED_PROTOCOLS_NUM];
	Display *display;
	Window window;
	Screen *screen;
	Visual *visual;
	Colormap colormap;
	XColor red;
	XColor green;
	XColor blue;
	XColor gray;
	GC gc;
	int screen_width;
	int screen_height;
	int screen_depth;
	int protocolno;
	int screeno;
	int entno;
};

void g_loop(struct game * const g);
void g_pause(struct game const * const g);

#endif

/*

gnu-linux-xlib-game-dev                                 May 23, 2025

author: @misael-diaz
source: src/game.h

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
