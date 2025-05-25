# GNU/Linux Xlib Game Dev
Game development with xlib for GNU/Linux.

## Motivation

My drive is not to build a game because I like games but to build a game because I
want to get the experience of writing code in an area outside of my field of expertise.

## References

We are using the [Xlib Programming Manual](https://tronche.com/gui/x/xlib/) as our main
source of information for building this game and of course the GNU/Linux man pages.

## Progress

Draws entities in the game window:
![phase-1](https://github.com/misael-diaz/gnu-linux-xlib-game-dev/blob/93f6196f98943aa8450b07d11e1e784cb9678121/public/graphics/phase-1-draw-entities.png)

This image was generated with the game at commit
[8611f7f42bf6f55c7624e1d8b5c813f02529bfb8](https://github.com/misael-diaz/gnu-linux-xlib-game-dev/commit/8611f7f42bf6f55c7624e1d8b5c813f02529bfb8)

The enemies, red squares, spawn at random locations in the screen, the player, blue
square, is centered, and the green rectangle displays the player health bar.

At this point there's no player interactivity, the game only shows the initial position
of the entities and pauses until the user presses a key on the console (we have yet to
add key event handling code to the game).

Playable game:
[![Watch the video](https://img.youtube.com/vi/MSf5etK1ojw/hqdefault.jpg)](https://www.youtube.com/watch?v=MSf5etK1ojw)

