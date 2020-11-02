#pragma once

// ANIMATION CONST
#define ANI_DEFAULT_TIME                100
//--MARIO
#define ANI_MARIO_BIG_RUN_RIGHT         1
#define ANI_MARIO_BIG_RUN_LEFT          -1
#define ANI_MARIO_BIG_IDLE_RIGHT        2
#define ANI_MARIO_BIG_IDLE_LEFT         -2
#define ANI_MARIO_BIG_JUMP_RIGHT        3
#define ANI_MARIO_BIG_JUMP_LEFT         -3
#define ANI_MARIO_BIG_FALL_RIGHT        4
#define ANI_MARIO_BIG_FALL_LEFT         -4 
#define ANI_BACKGROUND                  5
#define ANI_MARIO_BIG_SWITCH_RIGHT      6
#define ANI_MARIO_BIG_SWITCH_LEFT       -6

//--GOOMBA
#define ANI_GOOMBA_RUN                  9

// MARIO STATE CONST
#define STATE_RUN      	          1
#define STATE_IDLE			      2
#define STATE_JUMP     		      3
#define STATE_FALL                4

// MARIO SPEED CONST
#define MARIO_RUN_SPEED              7.0f
#define MARIO_JUMP_SPEED             -20.0f

// MARIO CONST
#define MARIO_FIGURE_SMALL              0
#define MARIO_FIGURE_BIG                1
#define MARIO_FIGURE_RACCOON            2
#define MARIO_BIG_WIDTH                 17
#define MARIO_BIG_HEIGHT                28
#define MARIO_SMALL_WIDTH               14
#define MARIO_SMALL_HEIGHT              15

// GOOMBA CONST
#define GOOMBA_WIDTH                    15
#define GOOMBA_HEIGHT                   15
#define GOOMBA_DIE_HEIGHT               9

// WORLD CONST
#define GRAVITY                         17.5f
#define SCALE_CONST                     3.0f
#define BACKGROUND_TEXTURE_WIDTH        2816
#define GAME_WIDTH                      780
#define GAME_HEIGHT                     614
#define FRAME_RATE                      60
#define TICK_PER_FRAME                  1000/FRAME_RATE   
#define BACKGROUND_COLOR                D3DCOLOR_XRGB(255, 255, 255)
#define	COLLISION_TIME                  0.4f

#define KEYBOARD_BUFFER_SIZE            1024

// GAMEOBJECT ID
#define ID_MARIO                           1
#define ID_GOOMBA_1                        2