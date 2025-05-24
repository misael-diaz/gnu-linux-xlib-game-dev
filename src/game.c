#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "input.h"
#include "system.h"
#include "game.h"

void g_loop(struct game * const g)
{
	struct timespec time_game_start = {};
	struct timespec time_game_end = {};
	clockid_t clockid = CLOCK_MONOTONIC;
	float etime = 0;
	clock_gettime(clockid, &time_game_start);
	while (1) {
		if (in_handle_input(g)) {
			break;
		}
	}
	clock_gettime(clockid, &time_game_end);
	etime = sys_etime(&time_game_end, &time_game_start);
	fprintf(stdout, "g_loop: game-duration: %f sec\n", etime);
}

void g_pause(struct game const * const g)
{
	char c = 0;
	fprintf(stdout, "g_pause: Press Any Key To Continue\n");
	fread(&c, sizeof(c), 1, stdin);
}

/*

gnu-linux-xlib-game-dev                                          May 23, 2025

author: @misael-diaz
source: game.c

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
