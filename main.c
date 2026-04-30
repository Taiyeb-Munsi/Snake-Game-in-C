#include "snake.h"

int main() {
    int run=1;
    Game g;
    init_game(&g);

    while(run) {
        draw_game(&g);
        char ch = wgetch(g.win);

        if(!g.state) {
            update_position_all(&g);
            update_position(&g, ch);
        }

        if(ch == 'q') run = 0;
        if(ch == 'p') g.state = (g.state == 2)?0:2;
        if(ch == 'r' && g.state == 1) restart(&g);

        food_collision(&g);
        self_collision(&g);
    }

    endwin();
    return 0;
}
