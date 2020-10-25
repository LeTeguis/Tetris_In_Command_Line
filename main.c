#include <time.h>
#include <stdlib.h>
#include <stdio.h>


#include "header/Screen.h"
#include "header/Event.h"
#include "header/Tetriminos.h"
#include "header/Grid.h"

void initScene(TETRIMINOS* type, int *rotation, int* x, int *y){
    update_grid_game();
    *type = rand()%7;
    if(*type != TETRI_O){
    if(*type == TETRI_I || *type == TETRI_S || *type == TETRI_Z)
        (*rotation) = rand()%2;
    else
        (*rotation) = rand()%4;
    }
    (*x) = 6; (*y) = 0;
}


int main(){
    srand(time(NULL));
    Event event;
    int exit_game = 0;
    int direction_presse = 0;

    time_t heure_actuel, heure_precedent;
    heure_actuel = heure_precedent = time(NULL);
    int x = 6, y = 0;
    int miseAjour = 1;

    TETRIMINOS type = 0;
    int rotation = 0;
    initScene(&type, &rotation, &x, &y);
    int _initScene = 0;

    init_grid();

    while(!exit_game){
        while(poll_event(&event)){
            if(event.mode == SPECIAL){
                if(event.key == KEY_LEFT){
                    x--;
                    if(collision_to_border(type,rotation,x,y) || collision(type, rotation, x, y))
                        x++;
                    else
                        miseAjour = 1;
                }
                if(event.key == KEY_RIGHT){
                    x++;
                    if(collision_to_border(type,rotation,x,y) || collision(type, rotation, x, y))
                        x--;
                    else
                        miseAjour = 1;
                }
                if(event.key == KEY_DOWN){
                    y++;
                    if(collision_to_border(type,rotation,x,y) || collision(type, rotation, x, y)){
                        y--;
                        _initScene = 1;
                    }
                    miseAjour = 1;
                }
                if(event.key == KEY_UP){
                    rotation++;
                    while(collision_to_border(type,rotation,x,y))
                        x--;
                    miseAjour = 1;
                }
                if(event.key == KEY_P){
                }
            }else{
                if(event.key == KEY_P){
                }
                if(event.key == KEY_ESCAPE){
                    exit_game = 1;
                }
            }
        }
        heure_actuel = time(NULL);

        if(difftime(heure_actuel,heure_precedent)>1){
            y++;
            if(collision_to_border(type,rotation,x,y) || collision(type, rotation, x, y)){
                y--;
                _initScene = 1;
            }
            miseAjour = 1;
            heure_precedent = heure_actuel;
        }
        if(miseAjour == 1){
            drawit:;
            draw_tetriminos(type, rotation, x, y);
            clear();
            int i = 0, j = 0;
            for(j = 0; j < NUMBER_LINE; j++){
                int k = 0;
                for(k = 0; k < POSITION_X; k++){
                    printf("*");
                }
                for(i = 0; i < NUMBER_ROW; i++){
                    printf("%c",grid_Game_draw[i][j]);
                }
                for(k = POSITION_X + NUMBER_ROW; k < 2*POSITION_X + NUMBER_ROW; k++){
                    printf("*");
                }
                printf("\n");
            }
            int k = 0;
            for(k = 0; k < 2*POSITION_X + NUMBER_ROW; k++){
                printf("*");
            }
            miseAjour = 0;
        }
        if(viderLigne() != 0)
            goto drawit;
        vider_Event(&event);

        if(_initScene == 1){
            initScene(&type, &rotation, &x, &y);
            _initScene = 0;
        }
    }
}
