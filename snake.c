#include "snake.h"
#include <ncurses.h>

void init_game(Game* g) {
    initscr();
    noecho();
    curs_set(0);

    g->win = newwin(WIN_H, WIN_W, 10, 10);
    g->snake.x = WIN_W/2;
    g->snake.y = WIN_H/2;
}

void draw_game(Game* g) {
    werase(g->win);
    mvwprintw(g->win, g->snake.y, g->snake.x, "S");
    box(g->win,0,0);
    wrefresh(g->win);
}

int update_position(Game* g, char ch) {
    if(ch == 'q') return 0;

    if(ch == 'w' && g->snake.y > 1) --g->snake.y;
    else if(ch == 's' && g->snake.y < WIN_H - 2) ++g->snake.y;
    else if(ch == 'a' && g->snake.x > 1) --g->snake.x;
    else if(ch == 'd' && g->snake.x < WIN_W - 2) ++g->snake.x;
    
    return 1;
}
