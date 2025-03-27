#include "terminal_ui.h"
#include <ncurses.h>

//          Public functions
void setup() {
    initscr(); // Init screen
    raw(); // Enable raw mode
    curs_set(FALSE); // Enable cursor
    noecho(); // No show user input
    keypad(stdscr, true); // Enable keypad

    // Colors
    start_color();

    init_pair(PANEL_COLORS, COLOR_WHITE, COLOR_BLACK);
    init_pair(EDITOR_COLORS, COLOR_WHITE, COLOR_BLUE);
    init_pair(STATUS_COLORS, COLOR_BLACK, COLOR_WHITE);
    init_pair(COMMAND_COLORS, COLOR_WHITE, COLOR_GREEN);
}

void draw_tui(unsigned short &cols, unsigned short &rows, unsigned short &key) {
    for (unsigned short i = 0; i != rows - 2; i++) {
        attron(COLOR_PAIR(PANEL_COLORS));
        mvhline(i, 0, ' ', cols / 4);
        attroff(COLOR_PAIR(PANEL_COLORS));
        attron(COLOR_PAIR(EDITOR_COLORS));
        mvhline(i, cols / 4, ' ', cols - (cols / 4));
        attroff(COLOR_PAIR(EDITOR_COLORS));
    }

    attron(COLOR_PAIR(STATUS_COLORS));
    mvhline(rows - 2, 0, ' ', cols);
    attroff(COLOR_PAIR(STATUS_COLORS));
    attron(COLOR_PAIR(COMMAND_COLORS));
    mvhline(rows - 1, 0, ' ', cols);
    attroff(COLOR_PAIR(COMMAND_COLORS));

    mvprintw(0, 0, "%hu|%s", key, keyname(key));
}

void close() {
    noraw(); // Disable raw mode
    curs_set(TRUE); // Enable cursor
    endwin(); // Exit window
}
