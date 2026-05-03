#include "snake.h"

int main(int argc, char* argv[]) {
    int run=1;
    Game g;
    
    if(argc < 2)
        init_game(&g, "-e");
    else if(argc >= 2)
        init_game(&g, argv[1]);

    while(run) {
        draw_game(&g);
        char ch = wgetch(g.win);

        if(!g.state) {
            update_position_all(&g);
            update_position(&g, ch);
            ++g.time;
            g.time %= TIME_CYClE;
        }

        if(ch == 'q') run = 0;
        if(ch == 'p') g.state = (g.state == 2)?0:2;
        if(ch == 'r' && g.state == 1) restart(&g);

        food_collision(&g, FOOD_NORMAL);
        food_collision(&g, FOOD_SUPER);
        self_collision(&g);
    }

    endwin();
    return 0;
}
