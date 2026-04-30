#include "snake.h"
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

void init_game(Game* g) {
    initscr();
    noecho();
    curs_set(0);
    srand(time(NULL));

    g->win = newwin(WIN_H, WIN_W, WIN_Y, WIN_X);
    g->snake_length = 12;
    g->score = 0;
    g->state = 0;

    for(int i=0;i<g->snake_length;++i) {
        g->snake[i].x = (WIN_W/2)-i;
        g->snake[i].y = WIN_H/2;

        g->snake[i].velX = 1;
    }

    g->food.x = rand()%(WIN_W-2)+1;
    g->food.y = rand()%(WIN_H-2)+1;

    halfdelay(2);
}

void draw_game(Game* g) {
    werase(g->win);
    mvwprintw(g->win, g->food.y, g->food.x, "*");
    
    for(int i=0;i<g->snake_length;++i)
        if(i == 0)
            mvwprintw(g->win, g->snake[i].y, g->snake[i].x, "@");
        else 
            mvwprintw(g->win, g->snake[i].y, g->snake[i].x, "o");
    
    box(g->win,0,0);

    mvprintw(WIN_Y-1, WIN_X+WIN_W-8, "       ");
    mvprintw(WIN_Y+WIN_H, WIN_X, "                   ");
    mvprintw(WIN_Y-1, WIN_X, " Score : %d", g->score);
    if(g->state == 2) mvprintw(WIN_Y-1, WIN_X+WIN_W-8, " Paused");
    if(g->state == 1) mvprintw(WIN_Y+WIN_H, WIN_X, " Game lost, press R");
    refresh();
    wrefresh(g->win);
}

void food_collision(Game* g) {
    if(g->snake[0].x == g->food.x && g->snake[0].y == g->food.y) {
        ++(g->snake_length);

        g->snake[g->snake_length - 1].x = g->snake[g->snake_length - 2].x - g->snake[g->snake_length - 2].velX;
        g->snake[g->snake_length - 1].y = g->snake[g->snake_length - 2].y - g->snake[g->snake_length - 2].velY;

        g->snake[g->snake_length - 1].velX = g->snake[g->snake_length - 2].velX;
        g->snake[g->snake_length - 1].velY = g->snake[g->snake_length - 2].velY;
        
        g->food.x = rand()%(WIN_W-2)+1;
        g->food.y = rand()%(WIN_H-2)+1;

        ++g->score;
    }
}

void self_collision(Game* g) {
    for(int i=1;i<g->snake_length;++i) {
        if(g->snake[0].x == g->snake[i].x && g->snake[0].y == g->snake[i].y) {
            g->state = 1;
            break;
        }
    }
}

void restart(Game* g) {
    g->state = 0;
    g->score = 0;
    g->snake_length = 1;
    g->snake[0].x = WIN_W/2;
    g->snake[0].y = WIN_H/2;
    g->snake[0].velX = 1;
    g->snake[0].velY = 0;
}

void update_position(Game* g, char ch) {;
    if(ch == 'w' && g->snake[0].velY == 0) { 
        g->snake[0].velY = -1;
        g->snake[0].velX = 0;
    } else if(ch == 's' && g->snake[0].velY == 0) {
        g->snake[0].velY = 1;
        g->snake[0].velX = 0;
    } else if(ch == 'a' && g->snake[0].velX == 0) {
        g->snake[0].velX = -1;
        g->snake[0].velY = 0;
    } else if(ch == 'd' && g->snake[0].velX == 0) {
        g->snake[0].velX = 1;
        g->snake[0].velY = 0;
    }
    
    g->snake[0].x += g->snake[0].velX;
    g->snake[0].y += g->snake[0].velY;

    if(g->snake[0].x < 1)
        g->snake[0].x = WIN_W-2;
    if(g->snake[0].x > WIN_W-2)
        g->snake[0].x = 1;
    if(g->snake[0].y < 1)
        g->snake[0].y = WIN_H-2;
    if(g->snake[0].y > WIN_H-2)
        g->snake[0].y = 1;
}

void update_position_all(Game* g) {
    for(int i=g->snake_length-1;i>0;--i) {
        g->snake[i].x = g->snake[i-1].x;
        g->snake[i].y = g->snake[i-1].y;

        g->snake[i].velX = g->snake[i-1].velX;
        g->snake[i].velY = g->snake[i-1].velY;
    }
}
