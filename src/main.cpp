#include <curses.h>
#include <stdlib.h>

const int ESC = 27;

int y = 0;
int x = 0;
bool colors_initialized = false;

int set_color(int key) {
    if (!has_colors()) return 1;

    if (!colors_initialized) {
        init_pair(1, COLOR_RED, COLOR_BLACK);
        init_pair(2, COLOR_WHITE, COLOR_CYAN);
        start_color();
        colors_initialized = true;
    }

    if (key == -1)
        attroff(COLOR_PAIR(1));
    else
        attron(COLOR_PAIR(key));

    return 0;
}


int main() {
    initscr();
    set_color(2);
    keypad(stdscr, TRUE);
    noecho();
    curs_set(1);
    move(y, x);



    int ch;
    while ((ch = getch()) != ESC) {
        switch (ch) {
            case KEY_UP: {
                y = y > 0 ? y - 1 : y;
                move(y, x);
                break;
            }
            case KEY_DOWN: {
                y = y < LINES - 1 ? y + 1 : y;
                move(y, x);
                break;
            }
            case KEY_RIGHT: {
                x = x < COLS - 1 ? x + 1 : x;
                move(y, x);
                break;
            }
            case KEY_LEFT: {
                x = x > 0 ? x - 1 : x;
                move(y, x);
                break;
            }
        }
    }

    endwin();

    return 0;
}