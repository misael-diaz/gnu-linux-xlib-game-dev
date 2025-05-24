#ifndef GNU_LINUX_XLIB_GAME_DEV_ENTITY_H
#define GNU_LINUX_XLIB_GAME_DEV_ENTITY_H

#include "gmdefs.h"

#define EN_NUM_ENTITY_MAX 15

/* ids for special entities in the array of entities */

#define EN_HUD_ID 0
#define EN_GAMER_ID 1

/* DEV: if you change the HUD LEN you must also change the HUD DAMAGE accordingly */

#define EN_HUD_LEN 200
#define EN_HUD_WIDTH EN_HUD_LEN
#define EN_HUD_HEIGHT 32

/* we use squares to represent the gamer/player and the enemies, length-unit: pixel */

#define EN_GAMER_LEN 128
#define EN_ENEMY_LEN 64

/* fix coordinates for the HUD */

#define EN_HUD_XPOS (EN_HUD_HEIGHT + (EN_HUD_WIDTH  >> 1))
#define EN_HUD_YPOS (EN_HUD_HEIGHT + (EN_HUD_HEIGHT >> 1))

/* velocity limits in pixels/sec */

#define EN_GAMER_VEL 16
#define EN_GAMER_XVEL EN_GAMER_VEL
#define EN_GAMER_YVEL EN_GAMER_VEL

#define EN_ENEMY_MINVEL 8
#define EN_ENEMY_MAXVEL 16
#define EN_ENEMY_VEL EN_ENEMY_MAXVEL

/* entity RGB color codes */

#define EN_HUD_ALPHA 0
#define EN_HUD_BLUE 0
#define EN_HUD_GREEN 128
#define EN_HUD_RED 0

#define EN_GAMER_ALPHA 0
#define EN_GAMER_BLUE 255
#define EN_GAMER_GREEN 0
#define EN_GAMER_RED 0

#define EN_ENEMY_ALPHA 0
#define EN_ENEMY_BLUE 0
#define EN_ENEMY_GREEN 0
#define EN_ENEMY_RED 255

/* color setting when the player takes damage  */

#define EN_GAMER_DAMAGED_ALPHA 0
#define EN_GAMER_DAMAGED_BLUE 128
#define EN_GAMER_DAMAGED_GREEN 128
#define EN_GAMER_DAMAGED_RED 128

#define EN_HUD_HP 100
#define EN_ENEMY_HP 20
#define EN_GAMER_HP 100

/* DEV: if you change the collision damage you must adjust the settings for the HUD */

#define EN_HUD_DAMAGE 40
#define EN_COLLISION_DAMAGE 20
#define EN_COLLISION_IGNORE ((int) (4.0 * GAME_FRAMERATE_HZ))

/* entity tags */

enum entag {
	EN_HUD,
	EN_GAMER,
	EN_ENEMY,
	EN_NTAGS
};

struct entity {
	enum entag tag;
	int id;
	int invisibility;
	int width;
	int height;
	int len;
	int red;
	int green;
	int blue;
	int alpha;
	int ticks;
	int hp;
	float xpos;
	float ypos;
	float xvel;
	float yvel;
	float xmin;
	float ymin;
	float xmax;
	float ymax;
};

void en_init(
		struct entity * const entities,
		int const num_entities,
		int const width_game_window,
		int const height_game_window
);

void en_update(
		struct entity * const entities,
		int num_entities
);

void en_handle_collisions(
		struct entity * const entities,
		int const num_entities
);

#endif

/*

gnu-linux-xlib-game-dev                                 May 23, 2025

author: @misael-diaz
source: src/entity.h

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
