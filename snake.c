#include "snake.h"
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

void init_game(Game* g) {
    initscr();
    noecho();
    curs_set(0);
    srand(time(NULL));

    g->win = newwin(WIN_H, WIN_W, 10, 10);
    g->snake_length = 1;

    for(int i=0;i<g->snake_length;++i) {
        g->snake[i].x = (WIN_W/2)-i;
        g->snake[i].y = WIN_H/2;
        g->snake[i].velX = 1;
    }

    g->food.x = rand()%(WIN_W-2)+1;
    g->food.y = rand()%(WIN_H-2)+1;

    halfdelay(5);
}

void draw_game(Game* g) {
    werase(g->win);
    mvwprintw(g->win, g->food.y, g->food.x, "F");
    for(int i=0;i<g->snake_length;++i) mvwprintw(g->win, g->snake[i].y, g->snake[i].x, "S");
    box(g->win,0,0);
    wrefresh(g->win);
}

void food_collision(Game* g) {
    if(g->snake[0].x == g->food.x && g->snake[0].y == g->food.y) {
        ++(g->snake_length);
        g->snake[g->snake_length - 1].x = g->snake[g->snake_length - 2].x - 1;
        g->snake[g->snake_length - 1].y = g->snake[g->snake_length - 2].y;
        g->snake[g->snake_length - 1].velX = g->snake[g->snake_length - 2].velX;
        g->snake[g->snake_length - 1].velY = g->snake[g->snake_length - 2].velY;
        g->food.x = rand()%(WIN_W-2)+1;
        g->food.y = rand()%(WIN_H-2)+1;
    }
}

int update_position(Game* g, char ch, int pos) {
    if(ch == 'q') return 0;

    if(ch == 'w' && g->snake[pos].velY == 0) { 
        g->snake[pos].velY = -1;
        g->snake[pos].velX = 0;
    } else if(ch == 's' && g->snake[pos].velY == 0) {
        g->snake[pos].velY = 1;
        g->snake[pos].velX = 0;
    } else if(ch == 'a' && g->snake[pos].velX == 0) {
        g->snake[pos].velX = -1;
        g->snake[pos].velY = 0;
    } else if(ch == 'd' && g->snake[pos].velX == 0) {
        g->snake[pos].velX = 1;
        g->snake[pos].velY = 0;
    }
    
    g->snake[pos].x += g->snake[pos].velX;
    g->snake[pos].y += g->snake[pos].velY;

    if(g->snake[pos].x < 1) g->snake[pos].x = WIN_W-2;
    if(g->snake[pos].x > WIN_W-2) g->snake[pos].x = 1;
    if(g->snake[pos].y < 1) g->snake[pos].y = WIN_H-2;
    if(g->snake[pos].y > WIN_H-2) g->snake[pos].y = 1;

    return 1;
}
