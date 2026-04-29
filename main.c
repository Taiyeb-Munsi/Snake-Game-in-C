#include "snake.h"

int main() {
    int run=1;
    Game g;
    init_game(&g);

    while(run) {
        draw_game(&g);
        char ch = wgetch(g.win);
        run = update_position(&g, ch);
    }

    endwin();
    return 0;
}
