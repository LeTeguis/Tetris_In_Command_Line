#include "../header/Grid.h"

void init_grid(){
    int i = 0, j = 0;
    for(j = 0; j < NUMBER_LINE; j++){
        for(i = 0; i < NUMBER_ROW; i++){
            grid_Game[i][j] = BRICK_PLAINE;
            grid_Game_draw[i][j] = BRICK_PLAINE;
        }
    }
}
void draw_tetriminos(TETRIMINOS type, int rotation, int x, int y){
    int i = 0, j = 0;
    for(i = 0; i<NUMBER_ROW;i++){
        for(j = 0; j<NUMBER_LINE;j++){
            grid_Game_draw[i][j] = (getTetriminos(type, x, y, i, j, rotation) == 1)?BRICK_VIDE:grid_Game[i][j];
        }
    }
}
void update_grid_game(){
    int i = 0, j = 0;
    for(i = 0; i<NUMBER_ROW;i++){
        for(j = 0; j<NUMBER_LINE;j++){
            grid_Game[i][j] = grid_Game_draw[i][j];
        }
    }
}
int collision_to_border(TETRIMINOS type, int rotation, int x, int y){
    if(x < 0)
        return 1;
    if(type == TETRI_O && (x + 2 > NUMBER_ROW || y + 2 > NUMBER_LINE))
        return 1;
    if((type == TETRI_L || type == TETRI_J || type == TETRI_S || type == TETRI_Z || type == TETRI_T)&& (rotation%2 == 0)
        && (x + 2 > NUMBER_ROW || y + 3 > NUMBER_LINE))
        return 1;
    if((type == TETRI_L || type == TETRI_J || type == TETRI_S || type == TETRI_Z|| type == TETRI_T)&& (rotation%2 == 1)
        && (x + 3 > NUMBER_ROW || y + 2 > NUMBER_LINE))
        return 1;
    if((type == TETRI_I && rotation%2 == 0) && (x >= NUMBER_ROW || y + 3 >= NUMBER_LINE))
        return 1;
    if((type == TETRI_I && rotation%2 == 1) && (x + 3 >= NUMBER_ROW || y >= NUMBER_LINE))
        return 1;
    return 0;
}
int collision(TETRIMINOS type, int rotation, int x, int y){
    if(type == TETRI_O){
        if(grid_Game[x][y] == BRICK_VIDE || grid_Game[x+1][y] == BRICK_VIDE ||
            grid_Game[x+1][y+1] == BRICK_VIDE ||grid_Game[x][y+1] == BRICK_VIDE)
            return 1;
    }else if(type == TETRI_I){
        if(rotation%2 == 0 && (grid_Game[x][y] == BRICK_VIDE || grid_Game[x][y+1] == BRICK_VIDE||
           grid_Game[x][y+2] == BRICK_VIDE ||grid_Game[x][y+3] == BRICK_VIDE))
           return 1;
        if(rotation%2 == 1 &&(grid_Game[x][y] == BRICK_VIDE || grid_Game[x+1][y] == BRICK_VIDE||
           grid_Game[x+2][y] == BRICK_VIDE ||grid_Game[x+3][y] == BRICK_VIDE))
            return 1;
    }
    else if(type == TETRI_J){
        if(rotation%4 == 0 && (grid_Game[x+1][y] == BRICK_VIDE || grid_Game[x+1][y+1] == BRICK_VIDE||
           grid_Game[x+1][y+2] == BRICK_VIDE ||grid_Game[x][y+2] == BRICK_VIDE))
           return 1;
        if(rotation%4 == 1 &&(grid_Game[x][y] == BRICK_VIDE || grid_Game[x+1][y] == BRICK_VIDE||
           grid_Game[x+2][y] == BRICK_VIDE ||grid_Game[x+2][y+1] == BRICK_VIDE))
            return 1;
        if(rotation%4 == 2 && (grid_Game[x][y] == BRICK_VIDE || grid_Game[x][y+1] == BRICK_VIDE||
           grid_Game[x][y+2] == BRICK_VIDE ||grid_Game[x+1][y] == BRICK_VIDE))
           return 1;
        if(rotation%4 == 3 &&(grid_Game[x][y+1] == BRICK_VIDE || grid_Game[x+1][y+1] == BRICK_VIDE||
           grid_Game[x+2][y+1] == BRICK_VIDE ||grid_Game[x][y] == BRICK_VIDE))
            return 1;
    }
    else if(type == TETRI_L){
        if(rotation%4 == 0 && (grid_Game[x][y] == BRICK_VIDE || grid_Game[x][y+1] == BRICK_VIDE||
           grid_Game[x][y+2] == BRICK_VIDE ||grid_Game[x+1][y+2] == BRICK_VIDE))
           return 1;
        if(rotation%4 == 1 &&(grid_Game[x][y+1] == BRICK_VIDE || grid_Game[x+1][y+1] == BRICK_VIDE||
           grid_Game[x+2][y+1] == BRICK_VIDE ||grid_Game[x+2][y] == BRICK_VIDE))
            return 1;
        if(rotation%4 == 2 && (grid_Game[x+1][y] == BRICK_VIDE || grid_Game[x+1][y+1] == BRICK_VIDE||
           grid_Game[x+1][y+2] == BRICK_VIDE ||grid_Game[x][y] == BRICK_VIDE))
           return 1;
        if(rotation%4 == 3 &&(grid_Game[x][y] == BRICK_VIDE || grid_Game[x+1][y] == BRICK_VIDE||
           grid_Game[x+2][y] == BRICK_VIDE ||grid_Game[x][y+1] == BRICK_VIDE))
            return 1;
    }
    else if(type == TETRI_T){
        if(rotation%4 == 0 && (grid_Game[x][y] == BRICK_VIDE || grid_Game[x][y+1] == BRICK_VIDE||
           grid_Game[x][y+2] == BRICK_VIDE ||grid_Game[x+1][y+1] == BRICK_VIDE))
           return 1;
        if(rotation%4 == 1 &&(grid_Game[x][y+1] == BRICK_VIDE || grid_Game[x+1][y+1] == BRICK_VIDE||
           grid_Game[x+2][y+1] == BRICK_VIDE ||grid_Game[x+1][y] == BRICK_VIDE))
            return 1;
        if(rotation%4 == 2 && (grid_Game[x+1][y] == BRICK_VIDE || grid_Game[x+1][y+1] == BRICK_VIDE||
           grid_Game[x+1][y+2] == BRICK_VIDE ||grid_Game[x][y+1] == BRICK_VIDE))
           return 1;
        if(rotation%4 == 3 &&(grid_Game[x][y] == BRICK_VIDE || grid_Game[x+1][y] == BRICK_VIDE||
           grid_Game[x+2][y] == BRICK_VIDE ||grid_Game[x+1][y+1] == BRICK_VIDE))
            return 1;
    }
    else if(type == TETRI_S){
        if(rotation%2 == 1 && (grid_Game[x][y+1] == BRICK_VIDE || grid_Game[x+1][y+1] == BRICK_VIDE||
           grid_Game[x+1][y] == BRICK_VIDE ||grid_Game[x+2][y] == BRICK_VIDE))
           return 1;
        if(rotation%2 == 0 &&(grid_Game[x][y] == BRICK_VIDE || grid_Game[x][y+1] == BRICK_VIDE||
           grid_Game[x+1][y+1] == BRICK_VIDE ||grid_Game[x+1][y+2] == BRICK_VIDE))
            return 1;
    }
    else if(type == TETRI_Z){
        if(rotation%2 == 1 && (grid_Game[x][y] == BRICK_VIDE || grid_Game[x+1][y] == BRICK_VIDE||
           grid_Game[x+1][y+1] == BRICK_VIDE ||grid_Game[x+2][y+1] == BRICK_VIDE))
           return 1;
        if(rotation%2 == 0 &&(grid_Game[x][y+1] == BRICK_VIDE || grid_Game[x][y+2] == BRICK_VIDE ||
           grid_Game[x+1][y] == BRICK_VIDE || grid_Game[x+1][y+1] == BRICK_VIDE))
            return 1;
    }

    return 0;
}

int viderLigne(){
    int i = 0, j = 0;
    int actual_position = NUMBER_LINE - 1;
    int count_line_delete = 0;
    int tmp[NUMBER_ROW][NUMBER_LINE];
    for(i = 0; i < NUMBER_ROW; i++)
        for(j = 0; j < NUMBER_LINE; j++)
            tmp[i][j] = BRICK_PLAINE;

    for(j = 0; j < NUMBER_LINE; j++){
        int can_delete = 1;
        for(i = 0; i < NUMBER_ROW; i++){
            if(grid_Game[i][NUMBER_LINE - j - 1] == BRICK_PLAINE){
                can_delete = 0;
                int k = 0;
                for(k = 0; k < NUMBER_ROW; k++){
                    tmp[k][actual_position] = grid_Game[k][NUMBER_LINE - j - 1];
                }
                actual_position--;
                break;
            }
        }
        if (can_delete == 1)
            count_line_delete++;
    }

    if(count_line_delete != 0){
        for(i = 0; i < NUMBER_ROW; i++)
            for(j = 0; j < NUMBER_LINE; j++)
                grid_Game[i][j] = tmp[i][j];
    }
    return count_line_delete;
}

int get_grid_draw(int x, int y){
    return grid_Game_draw[x][y];
}
