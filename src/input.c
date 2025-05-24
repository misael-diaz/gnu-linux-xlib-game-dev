#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include "input.h"

#define KBD_ESC XKeysymToKeycode(dpy, XK_Escape)
#define KBD_LEFT XKeysymToKeycode(dpy, XK_Left)
#define KBD_RIGHT XKeysymToKeycode(dpy, XK_Right)
#define KBD_DOWN XKeysymToKeycode(dpy, XK_Down)
#define KBD_UP XKeysymToKeycode(dpy, XK_Up)

int in_handle_input(struct game * const g)
{
	int rc = 0;
	XEvent ev = {};
	Display *dpy = g->display;
	while (XPending(g->display)) {
		XNextEvent(g->display, &ev);
		if (KeyPress == ev.type) {
			if (KBD_ESC == ev.xkey.keycode) {
				rc = 1;
				break;
			} else if (KBD_LEFT == ev.xkey.keycode) {
				fprintf(stdout, "%s\n", "left-key pressed");
				struct entity * const gamer = &g->ents[EN_GAMER_ID];
				gamer->xvel = -EN_GAMER_XVEL;
				rc = 0;
				break;
			} else if (KBD_RIGHT == ev.xkey.keycode) {
				fprintf(stdout, "%s\n", "right-key pressed");
				struct entity * const gamer = &g->ents[EN_GAMER_ID];
				gamer->xvel = EN_GAMER_XVEL;
				rc = 0;
				break;
			} else if (KBD_DOWN == ev.xkey.keycode) {
				fprintf(stdout, "%s\n", "down-key pressed");
				struct entity * const gamer = &g->ents[EN_GAMER_ID];
				gamer->yvel = EN_GAMER_YVEL;
				rc = 0;
				break;
			} else if (KBD_UP == ev.xkey.keycode) {
				fprintf(stdout, "%s\n", "up-key pressed");
				struct entity * const gamer = &g->ents[EN_GAMER_ID];
				gamer->yvel = -EN_GAMER_YVEL;
				rc = 0;
				break;
			}
		} else if (KeyRelease == ev.type) {
			if (KBD_LEFT == ev.xkey.keycode) {
				fprintf(stdout, "%s\n", "left-key released");
				struct entity * const gamer = &g->ents[EN_GAMER_ID];
				gamer->xvel = 0;
				rc = 0;
				break;
			} else if (KBD_RIGHT == ev.xkey.keycode) {
				fprintf(stdout, "%s\n", "right-key released");
				struct entity * const gamer = &g->ents[EN_GAMER_ID];
				gamer->xvel = 0;
				rc = 0;
				break;
			} else if (KBD_DOWN == ev.xkey.keycode) {
				fprintf(stdout, "%s\n", "down-key released");
				struct entity * const gamer = &g->ents[EN_GAMER_ID];
				gamer->yvel = 0;
				rc = 0;
				break;
			} else if (KBD_UP == ev.xkey.keycode) {
				fprintf(stdout, "%s\n", "up-key released");
				struct entity * const gamer = &g->ents[EN_GAMER_ID];
				gamer->yvel = 0;
				rc = 0;
				break;
			}
		}
	}
	return rc;
}

/*

gnu-linux-xlib-game-dev                                 May 23, 2025

author: @misael-diaz
source: src/input.c

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
