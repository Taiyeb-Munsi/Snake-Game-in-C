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
    WINDOW* win;
    Snake snake[MAX_L];
    int snake_length;
} Game;

void init_game(Game*);
void draw_game(Game*);
int update_position(Game*, char, int);

#endif
