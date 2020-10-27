#include "../header/Scene.h"

void initPlayer(TETRIMINOS* type, int *rotation, int* x, int *y){
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

void initScene(){

    exit_game = 0;
    direction_presse = 0;

    x = 6;
    y = 0;
    miseAjour = 1;

    type = 0;
    rotation = 0;

    _initScene = 0;

    time_delay = 0;
    score = 0;

    srand(time(NULL));
    heure_actuel = heure_precedent = time(NULL);
    initPlayer(&NextType, &NextRotation, &x, &y);
    type = NextType;
    rotation = NextRotation;
    initPlayer(&NextType, &NextRotation, &x, &y);
    init_grid();

    int i = 0, j = 0;
    for(i = 0; i < SCREEN_WIDTH; i++){
        for(j = 0; j < SCREEN_HIGHT; j++){
            if(i == 0){
                screenGame[i][j] = '[';
            }else if( i == SCREEN_WIDTH - 1){
                screenGame[i][j] = ']';
            }
            else if((j == 0 || j == SCREEN_HIGHT - 1 || j == 2) && (i != 0 || i != SCREEN_WIDTH - 1)){
                screenGame[i][j] = BRICK_PLAINE;
            }else if((i == 3 || i == 16) && j >= 4 && j <= 23){
                screenGame[i][j] = 124;
            }else if( (j == 3 || j == 24) && i >= 4 && i <= 15){
                screenGame[i][j] = 134;
            }
            else{
                screenGame[i][j] = ' ';
            }
        }
    }

    updateScreenTitle();
}

void drawScene(){
    clear();
    int i = 0, j = 0;
    for(j = 0; j < SCREEN_HIGHT; j++){
        for(i = 0; i < SCREEN_WIDTH; i++){
            printf("%c",screenGame[i][j]);
        }
        printf("\n");
    }
}

int gameOver(){
    int i = 0;
    for(i = 0; i < NUMBER_ROW; i++){
        if(get_grid_draw(i, 0) == BRICK_PLAINE){
            //return 1;
        }
    }
    return 0;
}

void updateScreenGrid(){
    int i = 0, j = 0;
    for(i = 0; i < NUMBER_ROW; i++){
        for(j = 0; j < NUMBER_LINE; j++){
            screenGame[POSITION_X + i][POSITION_Y + j] = get_grid_draw(i, j);
        }
    }
}

void updateScreenTitle(){

    screenGame[POSITION_X][POSITION_Y - 3] = 'T';
    screenGame[POSITION_X + 1][POSITION_Y - 3] = 'e';
    screenGame[POSITION_X + 2][POSITION_Y - 3] = 't';
    screenGame[POSITION_X + 3][POSITION_Y - 3] = 'r';
    screenGame[POSITION_X + 4][POSITION_Y - 3] = 'i';
    screenGame[POSITION_X + 5][POSITION_Y - 3] = 's';
    screenGame[POSITION_X + 7][POSITION_Y - 3] = 'b';
    screenGame[POSITION_X + 8][POSITION_Y - 3] = 'y';
    screenGame[POSITION_X + 10][POSITION_Y - 3] = 'L';
    screenGame[POSITION_X + 11][POSITION_Y - 3] = 'E';
    screenGame[POSITION_X + 12][POSITION_Y - 3] = 'T';
    screenGame[POSITION_X + 13][POSITION_Y - 3] = 'E';
    screenGame[POSITION_X + 14][POSITION_Y - 3] = 'G';
    screenGame[POSITION_X + 15][POSITION_Y - 3] = 'U';
    screenGame[POSITION_X + 16][POSITION_Y - 3] = 'I';
    screenGame[POSITION_X + 17][POSITION_Y - 3] = 'S';

    screenGame[POSITION_X + NUMBER_ROW + 3][POSITION_Y] = 'N';
    screenGame[POSITION_X + NUMBER_ROW + 4][POSITION_Y] = 'e';
    screenGame[POSITION_X + NUMBER_ROW + 5][POSITION_Y] = 'x';
    screenGame[POSITION_X + NUMBER_ROW + 6][POSITION_Y] = 't';

    screenGame[POSITION_X + NUMBER_ROW + 3][POSITION_Y + 9] = 'S';
    screenGame[POSITION_X + NUMBER_ROW + 4][POSITION_Y + 9] = 'c';
    screenGame[POSITION_X + NUMBER_ROW + 5][POSITION_Y + 9] = 'o';
    screenGame[POSITION_X + NUMBER_ROW + 6][POSITION_Y + 9] = 'r';
    screenGame[POSITION_X + NUMBER_ROW + 7][POSITION_Y + 9] = 'e';

    screenGame[POSITION_X + NUMBER_ROW + 3][POSITION_Y + 6] = 'T';
    screenGame[POSITION_X + NUMBER_ROW + 4][POSITION_Y + 6] = 'i';
    screenGame[POSITION_X + NUMBER_ROW + 5][POSITION_Y + 6] = 'm';
    screenGame[POSITION_X + NUMBER_ROW + 6][POSITION_Y + 6] = 'e';
}

void updateScreenNextTetris(){
    int i = 0, j = 0;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            screenGame[POSITION_X + NUMBER_ROW + 3 + i][POSITION_Y + 1 + j] = (getTetriminos(NextType, 0, 0, i, j, NextRotation) == 1)?BRICK_PLAINE:' ';
        }
    }
}
void updateScreenScore(){
    int i = 0, j = 0;
    int scoreTmp = score;
    for(i = 0; i < numberOfChar(score); i++){
        screenGame[POSITION_X + NUMBER_ROW + 3 + numberOfChar(score) - i - 1][POSITION_Y + 10] = getDecimal(scoreTmp)+48;
        scoreTmp /= 10;
    }
}
void updateScreenTime(){
    int i = 0, j = 0;
    int timeTmp = time_delay;
    for(i = 0; i < numberOfChar(time_delay); i++){
        screenGame[POSITION_X + NUMBER_ROW + 3 + numberOfChar(time_delay) - i - 1][POSITION_Y + 7] = getDecimal(timeTmp)+48;
        timeTmp /= 10;
    }
}

void eventState(){
    draw_tetriminos(type, rotation, x, y);
    updateScreenGrid();
    updateScreenNextTetris();
    updateScreenTime();
    updateScreenScore();

    time_t delayActuel = time(NULL);
    time_t delayPrecedent = delayActuel;

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

        delayActuel = time(NULL);

        if(difftime(heure_actuel,heure_precedent)>1){
            time_delay++;
            miseAjour = 1;
            delayPrecedent = delayActuel;
        }

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
            updateScreenTime();
            updateScreenGrid();

            if(_initScene == 1){
                type = NextType;
                rotation = NextRotation;
                initPlayer(&NextType, &NextRotation, &x, &y);
                updateScreenNextTetris();
                draw_tetriminos(type, rotation, x, y);
                updateScreenGrid();
                if(gameOver()==1){
                    initScene();
                    updateScreenNextTetris();
                    draw_tetriminos(type, rotation, x, y);
                    updateScreenScore();
                    updateScreenTime();
                    updateScreenGrid();
                }
                _initScene = 0;
            }

            drawScene();
            miseAjour = 0;
        }
        if(viderLigne() != 0){
            score += 10;
            updateScreenScore();
            goto drawit;
        }
        vider_Event(&event);
    }
}

int numberOfChar(int number){
    if(number <= 9 && number >= 0)
        return 1;
    return numberOfChar(number/10) + 1;
}
int getDecimal(int number){
    return number - (((int)(number/10))*10);
}
