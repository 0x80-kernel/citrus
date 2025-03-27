#include "keyboard.h"
#include <list>
#include <string>
#include <ncurses.h>

using namespace std;

void get_panel_input(unsigned short &key, list<string> &dirs_and_files, string &current_dir, unsigned short &current_file) {
    switch (key) {
        case KEY_ENTER: // Open file or enter into dir
            break;

        // Movement
        case KEY_UP: //
            break;
        case KEY_DOWN:
            break;

        // Back and forward
        case KEY_LEFT:
            break;
        case KEY_RIGHT:
            break;
    }
}
void get_editor_input(unsigned short &key) {
    switch (key) {
        // Movement
        case KEY_UP:
            break;
        case KEY_DOWN:
            break;
        case KEY_RIGHT:
            break;
        case KEY_LEFT:
            break;

        case KEY_ENTER: // New line
            break;
        case KEY_BACKSPACE: // Delete
            break;

        default:
            break;
    }
}

void get_command_input(unsigned short &key, list<string> &command_history, string &command_line, unsigned char &current_command) {

}
