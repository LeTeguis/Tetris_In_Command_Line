#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED

#include "../header/Tetriminos.h"

#define NUMBER_LINE 20
#define NUMBER_ROW 12

#define POSITION_X 4
#define POSITION_Y 4

#define BRICK_PLAINE 254
#define BRICK_VIDE ' '

int grid_Game[NUMBER_ROW][NUMBER_LINE];
int grid_Game_draw[NUMBER_ROW][NUMBER_LINE];

void init_grid();
void draw_tetriminos(TETRIMINOS type, int rotation, int x, int y);
void update_grid_game();
int collision_to_border(TETRIMINOS type, int rotation, int x, int y);
int collision(TETRIMINOS type, int rotation, int x, int y);
int viderLigne();
int get_grid_draw(int x, int y);

#endif // GRID_H_INCLUDED
