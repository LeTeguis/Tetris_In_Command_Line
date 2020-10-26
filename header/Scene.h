#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED

#include <windows.h>

#ifdef __WIN32__
#define clear() system("cls")
#else
#define clear() system("clear")
#endif

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#include "../header/Event.h"
#include "../header/Tetriminos.h"
#include "../header/Grid.h"

#define SCREEN_WIDTH 27
#define SCREEN_HIGHT 28

Event event;
int exit_game;
int direction_presse;
time_t heure_actuel, heure_precedent;

int x, y;
int miseAjour;

TETRIMINOS type;
int rotation;

TETRIMINOS NextType;
int NextRotation;

int _initScene;

int screenGame[SCREEN_WIDTH][SCREEN_HIGHT];

int time_delay;
int score;

void initPlayer(TETRIMINOS* type, int *rotation, int* x, int *y);
void initScene();
void eventState();
void drawScene();
void updateScreenGrid();
void updateScreenScore();
void updateScreenNextTetris();
void updateScreenTime();

int gameOver();

int numberOfChar(int number);
int getDecimal(int number);

#endif // SCENE_H_INCLUDED
