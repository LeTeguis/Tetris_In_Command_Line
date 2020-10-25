#include "../header/Tetriminos.h"

int O_Condition(int x, int y, int i, int j){
    if((x == i  || x == i - 1) && (y == j || y == j-1))
        return 1;
    return 0;
}

int L_Condition(int x, int y, int i, int j, int rot){
    if(rot%4 == 0){
        if((x == i && (y == j || y == j-1 || y == j-2))||(x == i - 1 && y == j-2))
            return 1;
    }else if(rot%4 == 1){
        if((y == j - 1 && (x == i || x == i-1 || x == i-2))||(y == j && x == i-2))
            return 1;
    }else if(rot%4 == 2){
        if((x == i-1 && (y == j || y == j-1 || y == j-2))||(x == i && y == j))
            return 1;
    }else{
        if((y == j && (x == i || x == i-1 || x == i-2))||(y == j-1 && x == i))
            return 1;
    }
    return 0;
}
int I_Condition(int x, int y, int i, int j, int rot){
    if(rot%2 == 0){
        if(x == i && (y == j || y == j-1 || y == j-2 || y == j-3))
            return 1;
    }else{
        if((x == i  || x == i - 1 || x == i - 2 || x == i - 3) && y == j)
            return 1;
    }
    return 0;
}
int T_Condition(int x, int y, int i, int j, int rot){
    if(rot%4 == 0){
        if((x == i && (y == j || y == j-1 || y == j-2))||(x == i - 1 && y == j-1))
            return 1;
    }else if(rot%4 == 1){
        if((y == j - 1 && (x == i || x == i-1 || x == i-2))||(y == j && x == i-1))
            return 1;
    }else if(rot%4 == 2){
        if((x == i-1 && (y == j || y == j-1 || y == j-2))||(x == i && y == j-1))
            return 1;
    }else{
        if((y == j && (x == i || x == i-1 || x == i-2))||(y == j-1 && x == i-1))
            return 1;
    }
    return 0;
}
int J_Condition(int x, int y, int i, int j, int rot){
    if(rot%4 == 0){
        if((x == i-1 && (y == j || y == j-1 || y == j-2))||(x == i && y == j-2))
            return 1;
    }else if(rot%4 == 1){
        if((y == j && (x == i || x == i-1 || x == i-2))||(y == j-1 && x == i-2))
            return 1;
    }else if(rot%4 == 2){
        if((x == i && (y == j || y == j-1 || y == j-2))||(x == i-1 && y == j))
            return 1;
    }else{
        if((y == j-1 && (x == i || x == i-1 || x == i-2))||(y == j && x == i))
            return 1;
    }
    return 0;
}
int Z_Condition(int x, int y, int i, int j, int rot){
    if(rot%2 == 1){
        if(((x == i  || x == i - 1) && (y == j))||((x == i-1  || x == i - 2) && (y == j-1)))
            return 1;
    }else{
        if(((y == j  || y == j - 1) && (x == i-1))||((y == j-1  || y == j - 2) && (x == i)))
            return 1;
    }
    return 0;
}
int S_Condition(int x, int y, int i, int j, int rot){
    if(rot%2 == 1){
        if(((x == i  || x == i - 1) && (y == j-1))||((x == i-1  || x == i - 2) && (y == j)))
            return 1;
    }else{
        if(((y == j  || y == j - 1) && (x == i))||((y == j-1  || y == j - 2) && (x == i-1)))
            return 1;
    }
    return 0;
}

int getTetriminos(TETRIMINOS type,int x, int y, int i, int j, int rot){
    if(type == TETRI_I)
        return I_Condition(x, y, i, j, rot);
    if(type == TETRI_O)
        return O_Condition(x, y, i, j);
    if(type == TETRI_L)
        return L_Condition(x, y, i, j, rot);
    if(type == TETRI_J)
        return J_Condition(x, y, i, j, rot);
    if(type == TETRI_T)
        return T_Condition(x, y, i, j, rot);
    if(type == TETRI_S)
        return S_Condition(x, y, i, j, rot);
    if(type == TETRI_Z)
        return Z_Condition(x, y, i, j, rot);
}
