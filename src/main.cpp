//      Focus
#define PANEL_FOCUS 0
#define EDITOR_FOCUS 1
#define COMMAND_FOCUS 2

//      Libs
#include <ncurses.h>
#include <list>
#include <string>
#include "terminal_ui.h"
#include "keyboard.h"

using namespace std;

int main() {
    // General variables
    bool exit_program = false;
    unsigned short cols = 0, rows = 0;
    unsigned char current_focus = 0;

    // Command line
    list<string>command_history;
    string command_line;
    unsigned char current_command;

    // File panel
    list<string>dirs_and_files;
    string current_dir;
    unsigned short current_file = 0;

    // Setting up
    setup();

    while (!exit_program) {
        getmaxyx(stdscr, rows, cols); // Get terminal size
        draw_tui(cols, rows); // Draw TUI :v
        refresh(); // Refresh terminal

        unsigned short key = getch(); // Get user input

        switch (current_focus) {
            case PANEL_FOCUS:
                get_panel_input(key, dirs_and_files, current_dir, current_file);
                break;
            case EDITOR_FOCUS:
                get_editor_input(key);
                break;
            default:
                get_command_input(key, command_history, command_line, current_command);
                break;
        }
    }

    close();
}
