#ifndef SNAKE_H
#define SNAKE_H

#include <ncurses.h>
#define WIN_H 20
#define WIN_W 40
#define WIN_X 10
#define WIN_Y 10
#define MAX_L (WIN_H - 2) * (WIN_W - 2)

typedef struct {
    int x, y;
    int velX, velY;
} Snake;

typedef struct {
    int x, y;
} Food;

typedef struct {
    WINDOW* win;
    Snake snake[MAX_L];
    Food food, super_food;
    int snake_length, score, state;
    const char *difficulty;
    //state = 0 : game running, = 1 : game lost, = 2 : game paused
} Game;

void init_game(Game*, char*);
void draw_game(Game*);
void food_collision(Game*);
void self_collision(Game*);
void restart(Game*);
void update_position(Game*, char);
void update_position_all(Game*);

#endif
