#include "snake.h"
#include <ncurses.h>

void init_game(Game* g) {
    initscr();
    noecho();
    curs_set(0);

    g->win = newwin(WIN_H, WIN_W, 10, 10);
    g->snake.x = WIN_W/2;
    g->snake.y = WIN_H/2;

    halfdelay(5);
}

void draw_game(Game* g) {
    werase(g->win);
    mvwprintw(g->win, g->snake.y, g->snake.x, "S");
    box(g->win,0,0);
    wrefresh(g->win);
}

int update_position(Game* g, char ch) {
    if(ch == 'q') return 0;

    if(ch == 'w' && g->snake.velY == 0) { 
        g->snake.velY = -1;
        g->snake.velX = 0;
    } else if(ch == 's' && g->snake.velY == 0) {
        g->snake.velY = 1;
        g->snake.velX = 0;
    } else if(ch == 'a' && g->snake.velX == 0) {
        g->snake.velX = -1;
        g->snake.velY = 0;
    } else if(ch == 'd' && g->snake.velX == 0) {
        g->snake.velX = 1;
        g->snake.velY = 0;
    }
    
    g->snake.x += g->snake.velX;
    g->snake.y += g->snake.velY;

    if(g->snake.x < 1) g->snake.x = WIN_W-2;
    if(g->snake.x > WIN_W-2) g->snake.x = 1;
    if(g->snake.y < 1) g->snake.y = WIN_H-2;
    if(g->snake.y > WIN_H-2) g->snake.y = 1;

    return 1;
}
