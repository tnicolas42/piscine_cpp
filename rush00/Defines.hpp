#pragma once

#include "Texture.hpp"

/* player */
// player size
#define PLAYER_W 10
#define PLAYER_H 5
// player weapon pos
#define PLAYER_WP_X (PLAYER_W / 2)
#define PLAYER_WP_Y - 2
#define PLAYER_WP_SPEED_BULLET_MS 10  // speed of bullet in ms
#define PLAYER_WP_DELAY 200  // delay btw 2 shots
// player speed
#define PLAYER_SPEED_MS 5
#define PLAYER_COLOR	COLOR_WHITE_PAIR
#define PLAYER_HP		3


/* global enemy */
/*
/!\ to generate spawn: update function EnemyFleet::newElement
*/
#define ENEMY_WP_DELAY_RANDOM_PERCENT 50 // the delay can be at 30 percent more or less
#define ENEMY_RANDOM_SPEED_PERCENT 30


/* ENEMY_SM */
// enemy pos
#define ENEMY_SM_W 5
#define ENEMY_SM_H 3
// enemy weapon pos
#define ENEMY_SM_WP_X (ENEMY_SM_W / 2)
#define ENEMY_SM_WP_Y ENEMY_SM_H + 1
#define ENEMY_SM_WP_SPEED_BULLET_MS PLAYER_WP_SPEED_BULLET_MS  // speed of bullet in ms
#define ENEMY_SM_WP_DELAY 1500  // delay btw 2 shots
// enemy speed
#define ENEMY_SM_SPEED_MS 60
#define ENEMY_SM_TEXTURE ENEMY_TEXTURE
#define ENEMY_SM_COLOR COLOR_WHITE_PAIR
#define ENEMY_SM_MOVE_VERTICAL true


/* ENEMY_BM */
// enemy pos
#define ENEMY_BM_W 6
#define ENEMY_BM_H 9
// enemy weapon pos
#define ENEMY_BM_WP_X (ENEMY_BM_W / 2)
#define ENEMY_BM_WP_Y ENEMY_BM_H + 1
#define ENEMY_BM_WP_SPEED_BULLET_MS PLAYER_WP_SPEED_BULLET_MS  // speed of bullet in ms
#define ENEMY_BM_WP_DELAY 1500  // delay btw 2 shots
// enemy speed
#define ENEMY_BM_SPEED_MS 30
// #define ENEMY_BM_TEXTURE ENEMY_TEXTURE
#define ENEMY_BM_COLOR COLOR_WHITE_PAIR
#define ENEMY_BM_MOVE_VERTICAL true


/* ENEMY_HORIZ_W */
// enemy pos
#define ENEMY_HORIZ_W 13
#define ENEMY_HORIZ_H 4
// enemy weapon pos
#define ENEMY_HORIZ_WP_X ENEMY_HORIZ_W + 1
#define ENEMY_HORIZ_WP_Y (ENEMY_HORIZ_H / 2)
#define ENEMY_HORIZ_WP_SPEED_BULLET_MS PLAYER_WP_SPEED_BULLET_MS  // speed of bullet in ms
#define ENEMY_HORIZ_WP_DELAY 1500  // delay btw 2 shots
// enemy speed
#define ENEMY_HORIZ_SPEED_MS 20
// #define ENEMY_HORIZ_TEXTURE ENEMY_HORIZ_TEXTURE
#define ENEMY_HORIZ_COLOR COLOR_WHITE_PAIR
#define ENEMY_HORIZ_MOVE_VERTICAL false
