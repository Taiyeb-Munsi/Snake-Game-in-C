#ifndef SNAKE_H
#define SNAKE_H

#include <ncurses.h>
#define WIN_H 20
#define WIN_W 80
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
    Food food;
    int snake_length;
} Game;

void init_game(Game*);
void draw_game(Game*);
void food_collision(Game*);
int update_position(Game*, char);
void update_position_all(Game*);

#endif
