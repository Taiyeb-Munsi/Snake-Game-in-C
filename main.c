#include "snake.h"

int main() {
    int run=1;
    Game g;
    init_game(&g);

    while(run) {
        draw_game(&g);
        char ch = wgetch(g.win);
        update_position_all(&g);
        run = update_position(&g, ch);
        food_collision(&g);
    }

    endwin();
    return 0;
}
