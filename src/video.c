#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "entity.h"
#include "video.h"

void vid_init_gw(
		Display ** const display,
		Window * const window
)
{
	*display = XOpenDisplay(NULL);
	if (!*display) {
		fprintf(stderr, "%s\n", "vid_info_gw: XOpenDisplayError");
		exit(EXIT_FAILURE);
	}
	XEvent ev = {};
	int const x = 0;
	int const y = 0;
	int const border_width = 0;
	unsigned int input_output_class = InputOutput;
	int const screeno = DefaultScreen(*display);
	Screen *screen = DefaultScreenOfDisplay(*display);
	XSetWindowAttributes attributes_window = {
		.background_pixel = BlackPixel(*display, screeno),
		.event_mask = ExposureMask | KeyPressMask | KeyReleaseMask

	};
	*window = XCreateWindow(
			*display,
			DefaultRootWindow(*display),
			x,
			y,
			WidthOfScreen(screen),
			HeightOfScreen(screen),
			border_width,
			DefaultDepthOfScreen(screen),
			input_output_class,
			DefaultVisual(*display, screeno),
			CWBackPixel | CWEventMask,
			&attributes_window
	);
	GC gc = DefaultGC(*display, screeno);
	XSetGraphicsExposures(*display, gc, True);
	XMapWindow(*display, *window);
	XWindowEvent(*display, *window, ExposureMask, &ev);
}

void vid_info_gw(
		Display ** const display
)
{
	int const screen = DefaultScreen(*display);
	int const image_byte_order = ImageByteOrder(*display);
	int const bitmap_bit_order = BitmapBitOrder(*display);
	Screen *scr = DefaultScreenOfDisplay(*display);
	fprintf(stdout, "vid_init_gw: XProtocolVersion: %d\n", ProtocolVersion(*display));
	fprintf(stdout, "vid_init_gw: fd: %d\n", ConnectionNumber(*display));
	fprintf(stdout, "vid_init_gw: screen: %d\n", screen);
	fprintf(stdout, "vid_init_gw: screen-count: %d\n", ScreenCount(*display));
	fprintf(stdout, "vid_init_gw: depth: %d\n", DisplayPlanes(*display, screen));
	fprintf(stdout, "vid_init_gw: default-depth: %d\n", DefaultDepthOfScreen(scr));
	if (LSBFirst == image_byte_order) {
		fprintf(stdout, "%s\n", "vid_init_gw: image_byte_order: LSBFirst");
	} else {
		fprintf(stdout, "%s\n", "vid_init_gw: image_byte_order: MSBFirst");
	}
	if (LSBFirst == bitmap_bit_order) {
		fprintf(stdout, "%s\n", "vid_init_gw: bitmap_bit_order: LSBFirst");
	} else {
		fprintf(stdout, "%s\n", "vid_init_gw: bitmap_bit_order: MSBFirst");
	}
	fprintf(stdout, "vid_init_gw: bitmap_pad: %d\n", BitmapPad(*display));
	fprintf(stdout, "vid_init_gw: width: %d\n", DisplayWidth(*display, screen));
	fprintf(stdout, "vid_init_gw: height: %d\n", DisplayHeight(*display, screen));
	fprintf(stdout, "vid_init_gw: screen-width: %d\n", WidthOfScreen(scr));
	fprintf(stdout, "vid_init_gw: screen-height: %d\n", HeightOfScreen(scr));
	fprintf(stdout, "vid_init_gw: cells: %d\n", CellsOfScreen(scr));
	fprintf(stdout, "vid_init_gw: planes: %d\n", PlanesOfScreen(scr));
	fprintf(stdout, "vid_init_gw: max-num-colormaps: %d\n", MaxCmapsOfScreen(scr));
	fprintf(stdout, "vid_init_gw: min-num-colormaps: %d\n", MinCmapsOfScreen(scr));

}

void vid_draw_gw(
		Display ** const display,
		Window * const window,
		struct entity const * const entities,
		int const num_entities
)
{
	int const screeno = DefaultScreen(*display);
	GC gc = DefaultGC(*display, screeno);

	Colormap colormap = DefaultColormap(*display, screeno);
	XColor red = {};
	XColor screen_red = {};
	XColor green = {};
	XColor screen_green = {};
	XColor blue = {};
	XColor screen_blue = {};
	XAllocNamedColor(
			*display,
			colormap,
			"red",
			&screen_red,
			&red
	);
	XAllocNamedColor(
			*display,
			colormap,
			"green",
			&screen_green,
			&green
	);
	XAllocNamedColor(
			*display,
			colormap,
			"blue",
			&screen_blue,
			&blue
	);

	for (int i = 0; i != num_entities; ++i) {
		struct entity const * const ent = &entities[i];
		if (EN_GAMER == ent->tag) {
			XSetForeground(*display, gc, blue.pixel);
		} else if (EN_ENEMY == ent->tag) {
			XSetForeground(*display, gc, red.pixel);
		} else if (EN_HUD == ent->tag) {
			XSetForeground(*display, gc, green.pixel);
		} else {
			XSetForeground(*display, gc, WhitePixel(*display, screeno));
		}
		XFillRectangle(
				*display,
				*window,
				gc,
				ent->xpos,
				ent->ypos,
				ent->width,
				ent->height
			      );
	}
	XFlush(*display);
}

void vid_close_gw(
		Display ** const display,
		Window * const window
)
{
	XDestroyWindow(*display, *window);
	XCloseDisplay(*display);
	*display = NULL;
}

/*

gnu-linux-xlib-game-dev                                          May 23, 2025

author: @misael-diaz
source: src/video.c

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
