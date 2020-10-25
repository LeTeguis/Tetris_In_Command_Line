#ifndef TETRIMINOS_H_INCLUDED
#define TETRIMINOS_H_INCLUDED

typedef enum{TETRI_L = 0,TETRI_I = 1,TETRI_O = 2,TETRI_T = 3,TETRI_J = 4,TETRI_Z = 5,TETRI_S = 6}TETRIMINOS;

int O_Condition(int x, int y, int i, int j);
int L_Condition(int x, int y, int i, int j, int rot);
int I_Condition(int x, int y, int i, int j, int rot);
int T_Condition(int x, int y, int i, int j, int rot);
int J_Condition(int x, int y, int i, int j, int rot);
int Z_Condition(int x, int y, int i, int j, int rot);
int S_Condition(int x, int y, int i, int j, int rot);

int getTetriminos(TETRIMINOS type,int x, int y, int i, int j, int rot);

#endif // TETRIMINOS_H_INCLUDED
