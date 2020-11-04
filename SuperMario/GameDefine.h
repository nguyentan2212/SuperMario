#pragma once

#pragma region Animations
#define ANI_DEFAULT_TIME                100
#define ANI_LONG_TIME                   300
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
#define ANI_MARIO_BIG_SIT_LEFT          10
#define ANI_MARIO_BIG_SIT_RIGHT         11
#define ANI_MARIO_BIG_HOLD_RIGHT        12
#define ANI_MARIO_BIG_HOLD_LEFT         13
#define ANI_MARIO_BIG_KICK_RIGHT        14
#define ANI_MARIO_BIG_KICK_LEFT         15

#define ANI_MARIO_SMALL_IDLE_LEFT         20
#define ANI_MARIO_SMALL_IDLE_RIGHT        21
#define ANI_MARIO_SMALL_RUN_LEFT          22
#define ANI_MARIO_SMALL_RUN_RIGHT         23
#define ANI_MARIO_SMALL_JUMP_LEFT         24
#define ANI_MARIO_SMALL_JUMP_RIGHT        25
#define ANI_MARIO_SMALL_FALL_LEFT         26
#define ANI_MARIO_SMALL_FALL_RIGHT        27
#define ANI_MARIO_SMALL_SWITCH_LEFT       28
#define ANI_MARIO_SMALL_SWITCH_RIGHT      29
#define ANI_MARIO_SMALL_HOLD_RIGHT        30
#define ANI_MARIO_SMALL_HOLD_LEFT         31
#define ANI_MARIO_SMALL_KICK_RIGHT        32
#define ANI_MARIO_SMALL_KICK_LEFT         33
#define ANI_MARIO_SMALL_DEATH             34

#define ANI_MARIO_RACCOON_IDLE_LEFT         40
#define ANI_MARIO_RACCOON_IDLE_RIGHT        41
#define ANI_MARIO_RACCOON_RUN_LEFT          42
#define ANI_MARIO_RACCOON_RUN_RIGHT         43
#define ANI_MARIO_RACCOON_JUMP_LEFT         44
#define ANI_MARIO_RACCOON_JUMP_RIGHT        45
#define ANI_MARIO_RACCOON_FALL_LEFT         46
#define ANI_MARIO_RACCOON_FALL_RIGHT        47
#define ANI_MARIO_RACCOON_SWITCH_LEFT       48
#define ANI_MARIO_RACCOON_SWITCH_RIGHT      49
#define ANI_MARIO_RACCOON_SIT_LEFT          50
#define ANI_MARIO_RACCOON_SIT_RIGHT         51
#define ANI_MARIO_RACCOON_HOLD_RIGHT        52
#define ANI_MARIO_RACCOON_HOLD_LEFT         53
#define ANI_MARIO_RACCOON_KICK_RIGHT        54
#define ANI_MARIO_RACCOON_KICK_LEFT         55

#define ANI_MARIO_FIRE_IDLE_LEFT         60
#define ANI_MARIO_FIRE_IDLE_RIGHT        61
#define ANI_MARIO_FIRE_RUN_LEFT          62
#define ANI_MARIO_FIRE_RUN_RIGHT         63
#define ANI_MARIO_FIRE_JUMP_LEFT         64
#define ANI_MARIO_FIRE_JUMP_RIGHT        65
#define ANI_MARIO_FIRE_FALL_LEFT         66
#define ANI_MARIO_FIRE_FALL_RIGHT        67
#define ANI_MARIO_FIRE_SWITCH_LEFT       68
#define ANI_MARIO_FIRE_SWITCH_RIGHT      69
#define ANI_MARIO_FIRE_SIT_LEFT          70
#define ANI_MARIO_FIRE_SIT_RIGHT         71
#define ANI_MARIO_FIRE_HOLD_RIGHT        72
#define ANI_MARIO_FIRE_HOLD_LEFT         73
#define ANI_MARIO_FIRE_KICK_RIGHT        74
#define ANI_MARIO_FIRE_KICK_LEFT         75



#define ANI_BACKGROUND                  200
//--GOOMBA
#define ANI_GOOMBA_RUN                  301
#define ANI_GOOMBA_DEATH                302

//--KOOPA
#define ANI_KOOPA_RUN_RIGHT            401
#define ANI_KOOPA_RUN_LEFT             402
#define ANI_KOOPA_CRAZY                403
#define ANI_KOOPA_STUN                 404

#define FIGURE_SMALL              1
#define FIGURE_BIG                2
#define FIGURE_RACCOON            3
#define FIGURE_FIRE               4
#pragma endregion animations, figure and render time
#pragma region States and Actions
// STATE CONST
#define STATE_IDLE			      1
#define STATE_RUN      	          2
#define STATE_JUMP     		      3
#define STATE_FALL                4
#define STATE_CHANGED_FIGURE      5
#define STATE_DEATH               6
#define STATE_SIT                 7
#define STATE_STUN                8
#define STATE_CRAZY               9
// ACTION CONST
#define SWITCH                    10
#define HOLD                      11
#define KICK                      12
#pragma endregion
#pragma region Sprites info
// MARIO
#define MARIO_BIG_WIDTH                 17
#define MARIO_BIG_HEIGHT                28
#define MARIO_SMALL_WIDTH               14
#define MARIO_SMALL_HEIGHT              15

// GOOMBA
#define GOOMBA_WIDTH                    15
#define GOOMBA_HEIGHT                   15
#define GOOMBA_DIE_HEIGHT               9

// KOOPA
#define KOOPA_WIDTH                    15
#define KOOPA_HEIGHT                   27
#define KOOPA_STUN_HEIGHT              15
#pragma endregion width and height of sprites
#pragma region Physics const
// MARIO SPEED CONST
#define MARIO_RUN_SPEED              7.0f
#define MARIO_JUMP_SPEED             -28.0f
#define MARIO_SUPER_RUN_SPEED        12.0f
#define MARIO_SUPER_JUMP_SPEED       -35.0f
#define MARIO_SHORT_JUMP_SPEED       -18.0f
#define MARIO_RUNNING_TIMER          150.0f

//
#define GOOMBA_RUN_SPEED             5.0f
#define KOOPA_RUN_SPEED              5.0f
#define KOOPA_SUPER_RUN_SPEED        10.0f
// WORLD CONST
#define GRAVITY                         10.0f
#define SCALE_CONST                     3.0f
#define LEFT                            -1
#define RIGHT                           1
#pragma endregion speed of characters and world const
#pragma region Game const
// GAME CONST
#define BACKGROUND_TEXTURE_WIDTH        2816
#define GAME_WIDTH                      780
#define GAME_HEIGHT                     614
#define FRAME_RATE                      50
#define TICK_PER_FRAME                  1000/FRAME_RATE   
#define BACKGROUND_COLOR                D3DCOLOR_XRGB(255, 255, 255)
#define	COLLISION_TIME                  0.4f

#define KEYBOARD_BUFFER_SIZE            1024

// GAMEOBJECT ID
#define ID_MARIO                           1
#define ID_GOOMBA_1                        2
#define ID_KOOPA_1                         10
#pragma endregion 

