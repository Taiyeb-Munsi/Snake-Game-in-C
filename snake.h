#ifndef SNAKE_H
#define SNAKE_H

#include <ncurses.h>
#define WIN_H 20
#define WIN_W 80

typedef struct {
    int x, y;
} Snake;

typedef struct {
    WINDOW* win;
    Snake snake;
} Game;

void init_game(Game*);
void draw_game(Game*);
int update_position(Game*, char);

#endif
