#pragma once

// GAME OBJECT
#define MARIO 0
#define GOOMBA 1

// ANIMATION CONST
#define ANI_DEFAULT_TIME                100
//--MARIO
#define ANI_MARIO_BIG_IDLE_LEFT         0
#define ANI_MARIO_BIG_IDLE_RIGHT        1
#define ANI_MARIO_BIG_RUN_LEFT          2
#define ANI_MARIO_BIG_RUN_RIGHT         3
#define ANI_MARIO_BIG_JUMP_LEFT         4
#define ANI_MARIO_BIG_JUMP_RIGHT        5
#define ANI_MARIO_BIG_FALL_LEFT         6
#define ANI_MARIO_BIG_FALL_RIGHT        7
#define ANI_MARIO_BIG_SWITCH_LEFT       8
#define ANI_MARIO_BIG_SWITCH_RIGHT      9

#define ANI_MARIO_SMALL_IDLE_LEFT         10
#define ANI_MARIO_SMALL_IDLE_RIGHT        11
#define ANI_MARIO_SMALL_RUN_LEFT          12
#define ANI_MARIO_SMALL_RUN_RIGHT         13
#define ANI_MARIO_SMALL_JUMP_LEFT         14
#define ANI_MARIO_SMALL_JUMP_RIGHT        15
#define ANI_MARIO_SMALL_FALL_LEFT         16
#define ANI_MARIO_SMALL_FALL_RIGHT        17
#define ANI_MARIO_SMALL_SWITCH_LEFT       18
#define ANI_MARIO_SMALL_SWITCH_RIGHT      19


#define ANI_BACKGROUND                  100
//--GOOMBA
#define ANI_GOOMBA_RUN                  110

// STATE CONST
#define STATE_IDLE			      1
#define STATE_RUN      	          2
#define STATE_JUMP     		      3
#define STATE_FALL                4
#define STATE_CHANGED_FIGURE      5
#define STATE_DEATH               6
// ACTION CONST
#define SWITCH                    5

// MARIO SPEED CONST
#define MARIO_RUN_SPEED              7.0f
#define MARIO_JUMP_SPEED             -28.0f

// MARIO CONST

#define FIGURE_SMALL              1
#define FIGURE_BIG                2
#define FIGURE_RACCOON            3
#define MARIO_BIG_WIDTH                 17
#define MARIO_BIG_HEIGHT                28
#define MARIO_SMALL_WIDTH               14
#define MARIO_SMALL_HEIGHT              15

// GOOMBA CONST
#define GOOMBA_WIDTH                    15
#define GOOMBA_HEIGHT                   15
#define GOOMBA_DIE_HEIGHT               9

// WORLD CONST
#define GRAVITY                         10.0f
#define SCALE_CONST                     3.0f
#define LEFT                            -1
#define RIGHT                           1

// GAME CONST
#define BACKGROUND_TEXTURE_WIDTH        2816
#define GAME_WIDTH                      780
#define GAME_HEIGHT                     614
#define FRAME_RATE                      50
#define TICK_PER_FRAME                  1000/FRAME_RATE   
#define BACKGROUND_COLOR                D3DCOLOR_XRGB(255, 255, 255)
#define	COLLISION_TIME                  0.8f

#define KEYBOARD_BUFFER_SIZE            1024

// GAMEOBJECT ID
#define ID_MARIO                           1
#define ID_GOOMBA_1                        2