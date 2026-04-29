#include <ncurses.h>

int main() {
    int x=2, y=2, winH=20, winW=80;

    initscr();
    noecho();
    curs_set(0);
    
    WINDOW* win = newwin(winH,winW,10,10);

    while(1) {
        werase(win);
        mvwprintw(win, x, y, "S");
        box(win,0,0);

        wrefresh(win);
        char ch = wgetch(win);

        if(ch == 'w' && x > 1) --x;
        else if(ch == 's' && x < winH-2) ++x;
        else if(ch == 'a' && y > 1) --y;
        else if(ch == 'd' && y < winW-2) ++y;
        else if(ch == 'q') break;
    }

    endwin();
    return 0;
}
