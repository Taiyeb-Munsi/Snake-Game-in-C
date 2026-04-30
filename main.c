#include "snake.h"

int main() {
    int run=1;
    Game g;
    init_game(&g);

    while(run) {
        draw_game(&g);
        char ch = wgetch(g.win);
        for(int i=0;i<g.snake_length;++i)
            run = update_position(&g, ch, i);
    }

    endwin();
    return 0;
}
