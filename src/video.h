#ifndef GNU_LINUX_XLIB_GAME_DEV_VIDEO_H
#define GNU_LINUX_XLIB_GAME_DEV_VIDEO_H

#include <X11/Xlib.h>
#include "entity.h"

void vid_init_gw(
		Display ** const display,
		Window * const window
);
void vid_info_gw(Display ** const display);

void vid_draw_gw(
		Display ** const display,
		Window * const window,
		struct entity const * const entities,
		int const num_entities
);

void vid_close_gw(
		Display ** const display,
		Window * const window
);

#endif

/*

gnu-linux-xlib-game-dev                                 May 23, 2025

author: @misael-diaz
source: src/system.h

Game Window GW

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
